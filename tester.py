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


def run(exercise, base=None, sanitize=True):
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
                (temp / "main.c").write_text(generated, encoding="utf-8")
                inputs = [temp / "main.c"]
            else:
                inputs = sorted(folder.glob("*.c"))
            command = compiler_command() + ["-I", str(folder)]
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
        for args in test_cases:
            try:
                result = subprocess.run(
                    [str(executable)] + args, capture_output=True, timeout=2,
                    env={**os.environ, "UBSAN_OPTIONS": "halt_on_error=1"})
            except subprocess.TimeoutExpired:
                return False, f"TIMEOUT: args={args!r}; check progress and the stopping condition."
            if result.returncode:
                return False, (f"RUNTIME/MEMORY: args={args!r}\n"
                               + result.stderr.decode(errors="replace")[:3500])
            expected = (oracle(name, args) if exercise["kind"] == "program"
                        else outputs.get(name, "")).encode()
            if result.stdout != expected:
                return False, (f"args={args!r}\nexpected={expected!r}\n"
                               f"received={result.stdout!r}")
        detail = " The harness checks multiple internal cases." if exercise["kind"] == "function" else ""
        return True, f"{len(test_cases)} successful execution(s).{detail}"


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("exercise", nargs="?", default="next",
                        help="ID, next, list, status, concepts, level1–level4 or all")
    parser.add_argument("--no-sanitize", action="store_true")
    parser.add_argument("--watch", action="store_true")
    args = parser.parse_args()
    state = load_progress()
    if args.exercise in ("list", "status"):
        approved = sum(state.get(e["id"]) == fingerprint(e) for e in ALL)
        print(f"Progress: {approved}/{len(ALL)} passed with the current source contents.")
        if args.exercise == "list":
            for exercise in ALL:
                mark = "✓" if state.get(exercise["id"]) == fingerprint(exercise) else "·"
                print(f"{mark} {exercise['id']:24} level {exercise['level']}  {exercise['path']}")
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
    while True:
        failures = 0
        observed = [fingerprint(e) for e in targets]
        for exercise, before in zip(targets, observed):
            print(f"Source: {exercise['path']}/{exercise['id']}.c", flush=True)
            ok, message = run(exercise, sanitize=not args.no_sanitize)
            print(("PASSED " if ok else "FAILED ") + exercise["id"])
            print(message, flush=True)
            failures += not ok
            if ok and before == fingerprint(exercise):
                state = load_progress()
                state[exercise["id"]] = before
                save_progress(state)
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
