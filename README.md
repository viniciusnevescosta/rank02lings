# Rank02lings

Turn ideas into C code: fix small broken exercises, get feedback in your terminal, and work toward a four-level mock exam.

[Study plan](STUDY_PLAN.md) · [Reasoning worksheet](WORKSHEET.md)

- **24 concept exercises** with short lessons and worked examples.
- **56 practice problems**, grouped into four levels, with intentional defects.
- **A local tester** that checks compilation, output, timeouts, and memory errors.
- **Four original challenges** to implement from scratch after completing the track.

Inspired by the practice loop in Rustlings and Ziglings. This is an independent learning project, not an official 42 grader. Rust, Zig, external accounts, and an AI assistant are not required.

## Getting started

You need Python 3.9+ and Clang or GCC with C99 support. There are no Python packages to install. The project is checked on macOS and Linux in CI.

```sh
git clone https://github.com/viniciusnevescosta/rank02lings.git
cd rank02lings
git switch -c studies/your-name
python3 tester.py next
```

Start with [`concepts/c01_count/c01_count.c`](concepts/c01_count/c01_count.c). Read the comment, describe your steps in plain language, fix the function body, and run:

```sh
python3 tester.py c01_count --watch
```

**Initial failure is expected.** The exercises start broken. After each success, the tester saves progress and automatically runs the next pending exercise, stopping at the first failure. With `--watch`, it waits for edits to that exercise and continues when it passes. Concept exercises come before the exam practice bank. Documentation, source comments, and tester messages are in English.

Every concept and practice source includes a lesson about that exercise: an explanation, a small example or trace, and a final **GOAL** describing what you must implement or repair. Examples teach the underlying concept; they do not provide a complete exercise solution. For practice problems, `SUBJECT.md` supplies the full contract and allowed functions.

Incomplete functions may contain `(void)param;` to silence a warning for a parameter they do not use yet. Remove that line when your implementation starts using the parameter.

On macOS, install a missing compiler with `xcode-select --install`. On Ubuntu/Debian, use `sudo apt install python3 build-essential`. Select a compiler with `CC=clang python3 tester.py next`.

## Commands

| Command | Purpose |
| --- | --- |
| `python3 tester.py` or `python3 tester.py next` | Start at the first pending exercise; advance until a failure |
| `python3 tester.py list` | List exercise IDs, paths, and progress |
| `python3 tester.py status` | Show overall progress |
| `python3 tester.py ft_strlen` | Start at an ID; advance until a failure |
| `python3 tester.py ft_strlen --only` | Test just that exercise |
| `python3 tester.py concepts` | Test all concept exercises |
| `python3 tester.py level1` | Test level 1; level2–level4 also work |
| `python3 tester.py all` | Test the entire track |
| `python3 tester.py --watch` | Watch the current pending exercise; advance after each success |
| `python3 tester.py ID --only --watch` | Watch a single exercise |
| `python3 tester.py ID --verbose` | Show values for every check, including large case tables |
| `python3 tester.py --color never` | Disable terminal colors |
| `python3 mock_exam.py` | Unlock four challenges after finishing the track |

Exit codes: 0 for success, 1 for a failed test, 2 for an invalid ID. Press `Ctrl+C` to stop watching. Progress is tied to source contents, so editing a passed exercise requires retesting it. Personal progress and generated mock exam files are ignored by Git.

## Reading feedback

Each check shows **Expected** and **Obtained**, on success as well as failure. Green marks a passing check; red marks a failure. Colors are automatic in a terminal, omitted in redirected output, and respect `NO_COLOR`. Use `--color always` to force them. Large test tables show six examples by default; `--verbose` shows all checks.

Function values come from the running C test harness. Your function does not need to print anything. For programs that print, the tester compares actual stdout with the expected bytes; quotes and escapes make empty strings, tabs, and newlines visible.

The **Source** line identifies the C file you are editing. Compiler diagnostics and sanitizer reports retain their native C file locations. A wrong result is reported as **C CHECK FAILED**, with the expected value, obtained value, and a separate **C test** location. That location identifies the assertion that detected the difference; it cannot determine which statement in your function caused a logic bug. **TIMEOUT** identifies the last C call/check when available. These messages are distinct from memory errors.

## Learning approach

Before coding, describe the input, output, state, steps, stopping condition, and progress. Trace an example by hand. After fixing a defect, explain its cause and rewrite the solution without looking.

Use the [study plan](STUDY_PLAN.md), [reasoning worksheet](WORKSHEET.md), and [56-problem checklist](CHECKLIST.md). The mock exam has four original problems, one per level, with no implementation hints. Its suggested 180-minute duration is a training choice, not an official exam rule.

## What passing means

Tests check compilation with warnings treated as errors, function results, exact program output, timeouts, and errors detected by AddressSanitizer/UndefinedBehaviorSanitizer. Expectations were written separately from the supplied practice sources.

**Passing means passing these local tests.** It does not certify an official exam result, Norminette compliance, allowed function usage, absence of every memory leak, or behavior under injected malloc failures. Check each `SUBJECT.md`. Libraries used by a harness are not automatically allowed in your submission.

If sanitizers are unavailable, `--no-sanitize` runs with reduced memory checking. Some supplied sources have limitations beyond their intentional defect; correcting them is part of the practice.

## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md). Useful contributions include edge cases, clearer comments, new microexercises, and reproducible tester bug reports. Keep personal solutions on your study branch so `main` remains ready for new learners.

The runner, tests, and original project content use the [MIT license](LICENSE). Third-party material in `practice/` has a separate scope; see [PROVENANCE.md](PROVENANCE.md) for origin and attribution.
