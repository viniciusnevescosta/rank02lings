#!/usr/bin/env python3
"""Compile, fix, and track local C exercises."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shlex
import subprocess
import sys
import tempfile
import time
from functools import lru_cache

ROOT = Path(__file__).resolve().parent
sys.path.insert(0, str(ROOT / "tests"))
from programs import cases, oracle


def load_exercises():
    entries = []
    for name in ("concepts.json", "manifest.json", "simulation.json"):
        path = ROOT / name
        if path.exists():
            entries.extend(json.loads(path.read_text(encoding="utf-8")))
    return entries


ALL = load_exercises()
REPORT_PREFIX = "RANK02LINGS_CHECK\t"
REPORT_LIMIT = 6


def parse_c_reports(stderr):
    """Read values emitted by the C harness; keep native diagnostics intact."""
    reports, native = [], []
    context, pending = "", None
    for line in stderr.decode(errors="replace").splitlines():
        if not line.startswith(REPORT_PREFIX):
            native.append(line)
            continue
        try:
            record = json.loads(line[len(REPORT_PREFIX):])
            if record["kind"] == "case":
                context = record["expression"]
                pending = {**record, "context": context}
            elif record["kind"] == "pending":
                pending = {**record, "context": context}
            elif record["kind"] == "check":
                reports.append({**record, "context": context})
                pending = None
        except (ValueError, KeyError, TypeError):
            native.append(line)
    return reports, "\n".join(native), pending


def value_text(value):
    if isinstance(value, bytes):
        return json.dumps(value.decode("latin1"), ensure_ascii=True)
    if value is None:
        return "NULL"
    if value in ("NULL", "non-NULL"):
        return value
    return json.dumps(value, ensure_ascii=True)


def c_location(record):
    path = Path(record["file"])
    try:
        path = path.relative_to(ROOT)
    except ValueError:
        pass
    return f"{path}:{record['line']}" if record.get("line") else str(path)


def report_text(reports, verbose=False):
    lines = []
    shown = 0
    passing = [i for i, r in enumerate(reports) if r["passed"]]
    if not verbose and len(passing) > REPORT_LIMIT:
        # Array/list harnesses may allocate many nodes before calling student
        # code. Prefer value comparisons to repeated allocation guards.
        values = [i for i in passing if reports[i]["expected"] != "non-NULL"]
        guards = [i for i in passing if reports[i]["expected"] == "non-NULL"]
        passing = (values + guards)[:REPORT_LIMIT]
    selected = set(passing)
    for i, report in enumerate(reports):
        if report["passed"] and i not in selected:
            continue
        shown += 1
        status = "PASS" if report["passed"] else "FAIL"
        label = report["expression"]
        if report.get("context"):
            label = report["context"] + " → " + label
        lines.extend([
            f"  {status} {label}",
            f"    Expected: {value_text(report['expected'])}",
            f"    Obtained: {value_text(report['actual'])}",
            f"    {'C test' if report.get('line') else 'C output'}: {c_location(report)}",
        ])
    omitted = len(reports) - shown
    if omitted:
        lines.append(f"  {omitted} more C checks passed. Use --verbose to see all values.")
    return "\n".join(lines)


def paint(text, color, policy="auto"):
    enabled = policy == "always" or (
        policy == "auto" and sys.stdout.isatty()
        and "NO_COLOR" not in os.environ and os.environ.get("TERM") != "dumb")
    return f"\033[{color}m{text}\033[0m" if enabled else text


def print_result(exercise, passed, message, color):
    status = "PASSED" if passed else "FAILED"
    print(paint(f"{status} {exercise['id']}", "32" if passed else "31", color))
    check_color = "32" if passed else "31"
    for line in message.splitlines():
        if line.startswith("  PASS "):
            check_color = "32"
            print(paint(line, "32", color))
        elif line.startswith("  FAIL "):
            check_color = "31"
            print(paint(line, "31", color))
        elif line.startswith("    Obtained:"):
            print(paint(line, check_color, color))
        elif line.startswith(("COMPILATION", "TIMEOUT", "RUNTIME/MEMORY", "C CHECK FAILED", "C OUTPUT MISMATCH", "C EXECUTION")):
            print(paint(line, "31", color))
        else:
            print(line)
    print(flush=True)


def load_progress():
    path = ROOT / "progress.json"
    return json.loads(path.read_text(encoding="utf-8")) if path.exists() else {}


def save_progress(state):
    temporary = ROOT / "progress.json.tmp"
    temporary.write_text(json.dumps(state, indent=2) + "\n", encoding="utf-8")
    temporary.replace(ROOT / "progress.json")


def fingerprint(exercise):
    folder = ROOT / exercise["path"]
    digest = hashlib.sha256()
    for path in sorted(folder.iterdir()):
        if path.suffix in (".c", ".h"):
            digest.update(path.name.encode())
            digest.update(b"\0")
            digest.update(path.read_bytes())
    return digest.hexdigest()


@lru_cache(maxsize=1)
def compiler_command():
    command = shlex.split(os.environ.get("CC", "cc"))
    if not command:
        raise ValueError("CC is empty. Use CC=clang or CC=gcc.")
    version = subprocess.run(command + ["--version"], capture_output=True, timeout=10)
    flags = ["-std=c99", "-Wall", "-Wextra", "-Werror", "-g"]
    if b"clang" in version.stdout.lower():
        # The original remove_if subject requires int (*cmp)().
        flags.append("-Wno-deprecated-non-prototype")
    return command + flags


def run(exercise, base=None, sanitize=True, verbose=False):
    """Return (passed, diagnostic) without modifying progress."""
    name = exercise["id"]
    folder = (base / ("Level_" + str(exercise["level"])) / name
              if base else ROOT / exercise["path"])
    source = folder / (name + ".c")
    with tempfile.TemporaryDirectory(prefix="rank02lings-") as temporary:
        temp = Path(temporary)
        executable = temp / "exercise"
        try:
            if exercise["kind"] == "function":
                harness = ROOT / "tests" / (name + ".c")
                generated = harness.read_text(encoding="utf-8").replace(
                    "STUDENT_SOURCE", str(source.resolve()))
                generated = f"#line 1 {json.dumps(str(harness))}\n" + generated
                (temp / "main.c").write_text(generated, encoding="utf-8")
                inputs = [temp / "main.c"]
            else:
                inputs = sorted(folder.glob("*.c"))
            command = compiler_command() + ["-I", str(folder), "-I", str(ROOT / "tests")]
            if sanitize:
                command += ["-fsanitize=address,undefined", "-fno-omit-frame-pointer"]
            compiled = subprocess.run(
                command + [str(p) for p in inputs] + ["-o", str(executable)],
                capture_output=True, timeout=20)
        except (OSError, ValueError, subprocess.TimeoutExpired) as error:
            return False, f"TOOLS/FILES: {error}"
        if compiled.returncode:
            return False, "COMPILATION\n" + compiled.stderr.decode(errors="replace")
        outputs = json.loads((ROOT / "tests/function_output.json").read_text())
        test_cases = cases(name) if exercise["kind"] == "program" else [[]]
        all_reports = []
        stdout_reports = []
        for args in test_cases:
            try:
                result = subprocess.run(
                    [str(executable)] + args, capture_output=True, timeout=2,
                    env={**os.environ, "UBSAN_OPTIONS": "halt_on_error=1"})
            except subprocess.TimeoutExpired as error:
                reports, native, pending = parse_c_reports(error.stderr or b"")
                detail = "TIMEOUT: the C program did not finish within 2 seconds."
                if pending:
                    label = pending.get("context") or pending["expression"]
                    detail += f"\nLast C check: {c_location(pending)} — {label}"
                elif exercise["kind"] == "program":
                    detail += f"\nC arguments: {args!r}"
                detail += "\nCheck the stopping condition and progress in your C loop."
                return False, "\n".join(filter(None, [
                    report_text(all_reports + reports, verbose), detail, native[:3500]]))
            reports, native, pending = parse_c_reports(result.stderr)
            all_reports.extend(reports)
            if result.returncode:
                if any(not r["passed"] for r in reports):
                    detail = "C CHECK FAILED: the C harness compared the values shown above."
                elif any(marker in native for marker in (
                        "AddressSanitizer", "UndefinedBehaviorSanitizer", "runtime error:")):
                    detail = "RUNTIME/MEMORY: a sanitizer detected an error in the C execution."
                else:
                    detail = f"C EXECUTION: the program exited with code {result.returncode}."
                if pending:
                    label = pending.get("context") or pending["expression"]
                    detail += f"\nLast C check: {c_location(pending)} — {label}"
                return False, "\n".join(filter(None, [
                    report_text(all_reports, verbose), detail, native[:3500]]))
            expected = (oracle(name, args) if exercise["kind"] == "program"
                        else outputs.get(name, "")).encode()
            if exercise["kind"] == "program" or name in outputs or result.stdout != expected:
                stdout_reports.append({
                    "passed": result.stdout == expected, "expression": f"stdout; argv={args!r}",
                    "file": str(source if exercise["kind"] == "program" else harness),
                    "line": None, "expected": expected, "actual": result.stdout,
                })
            if result.stdout != expected:
                return False, report_text(all_reports + stdout_reports, verbose) + "\nC OUTPUT MISMATCH: stdout differs from the expected bytes."
        reports = all_reports + stdout_reports
        detail = f"{len(reports)} C checks passed." if reports else "C harness exited successfully; no value reports were emitted."
        return True, "\n".join(filter(None, [report_text(reports, verbose), detail]))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("exercise", nargs="?", default="next",
                        help="ID, next, list, status, concepts, level1–level4 or all")
    parser.add_argument("--no-sanitize", action="store_true")
    parser.add_argument("--watch", action="store_true")
    parser.add_argument("--only", action="store_true", help="test one pending exercise or one ID, without advancing")
    parser.add_argument("--verbose", action="store_true", help="show expected and obtained values for every C check")
    parser.add_argument("--color", choices=("auto", "always", "never"), default="auto")
    args = parser.parse_args()
    state = load_progress()
    if args.exercise in ("list", "status"):
        approved = sum(state.get(e["id"]) == fingerprint(e) for e in ALL)
        print(f"Progress: {approved}/{len(ALL)} passed with the current source contents.")
        if args.exercise == "list":
            for exercise in ALL:
                mark = "✓" if state.get(exercise["id"]) == fingerprint(exercise) else "·"
                line = f"{mark} {exercise['id']:24} level {exercise['level']}  {exercise['path']}"
                print(paint(line, "32", args.color) if mark == "✓" else line)
        return 0
    if args.exercise == "next":
        targets = [e for e in ALL if state.get(e["id"]) != fingerprint(e)][:1]
    elif args.exercise == "all":
        targets = ALL
    elif args.exercise == "concepts":
        targets = [e for e in ALL if e["path"].startswith("concepts/")]
    elif args.exercise in ("level1", "level2", "level3", "level4"):
        targets = [e for e in ALL if e["level"] == int(args.exercise[-1])
                   and e["path"].startswith("practice/")]
    else:
        targets = [e for e in ALL if e["id"] == args.exercise]
        if not targets:
            parser.error("Unknown ID. See: python3 tester.py list")
    if not targets:
        print("Track completed. To unlock the four exercises: python3 mock_exam.py")
        return 0
    advance = not args.only and args.exercise not in (
        "all", "concepts", "level1", "level2", "level3", "level4")
    while True:
        failures = 0
        observed = [fingerprint(e) for e in targets]
        for exercise, before in zip(targets, observed):
            print(f"[{ALL.index(exercise) + 1}/{len(ALL)}] {exercise['id']}", flush=True)
            print(f"Source: {exercise['path']}/{exercise['id']}.c", flush=True)
            ok, message = run(exercise, sanitize=not args.no_sanitize, verbose=args.verbose)
            if ok and before != fingerprint(exercise):
                ok = False
                message += "\nSource changed during the run. Retest the current contents before advancing."
            print_result(exercise, ok, message, args.color)
            failures += not ok
            if ok and before == fingerprint(exercise):
                state = load_progress()
                state[exercise["id"]] = before
                save_progress(state)
        if advance and not failures:
            start = 0 if args.exercise == "next" else ALL.index(targets[-1]) + 1
            state = load_progress()
            targets = [e for e in ALL[start:] if state.get(e["id"]) != fingerprint(e)][:1]
            if targets:
                print("Moving to the next exercise...\n", flush=True)
                continue
            print(paint("Track completed. To unlock the four exercises: python3 mock_exam.py", "32", args.color))
            return 0
        if not args.watch:
            return 1 if failures else 0
        print("Waiting for changes (Ctrl+C to stop)...", flush=True)
        while observed == [fingerprint(e) for e in targets]:
            time.sleep(0.5)


if __name__ == "__main__":
    try:
        sys.exit(main())
    except KeyboardInterrupt:
        print("\nStopped.")
        sys.exit(130)
