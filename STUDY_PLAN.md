# Rank02lings study plan: from ideas to code

This C track combines 24 small concept exercises with 56 problems from a four-level Rank 02 practice bank. Edit an exercise, run the tester, explain the failure, and advance. Rust and Zig are not required.

## Start with one exercise

```sh
python3 tester.py next
```

The first source is `concepts/c01_count/c01_count.c`. Read its comment and fix the function body. To retest when you save:

```sh
python3 tester.py c01_count --watch
```

**FAILED is expected at first.** The starter code is intentionally broken. After it passes, use `python3 tester.py next` to move forward. Requirements and installation instructions are in README.md.

## Advance by understanding, not by a deadline

The goal is to translate ideas into code. Before each edit, write down:

1. **Input and output:** what data comes in, and what must be returned or printed?
2. **State:** which variables do you need, and what does each represent?
3. **Steps:** write 3–5 plain-language sentences, one action per sentence.
4. **Stopping condition and progress:** when does the algorithm finish, and what changes in each iteration?
5. **Manual example:** trace a typical input and one boundary case.

Use a notebook or source comments. Translate one sentence at a time into C. If you get stuck, discuss your plan with a peer or tutor and ask for a hint about the next step instead of a complete solution.

Try two 50–60-minute blocks with a break. Use one block to learn and fix code, and the other to rewrite from memory and explain your reasoning. Increase the time only while you can still follow what you are doing. Advance when you understand the code, rather than after a fixed number of hours.

| Stage | Work | Criterion for moving on |
|---|---|---|
| 1A | Concepts c01–c06: strings, indexes, pointers, ASCII | Pass tests and explain each variable |
| 1B | Concepts c07–c12: conversion, search, two indexes, bits, malloc | Trace an example and explain boundaries |
| 1C | Concepts c13–c18: ranges, bases, Euclid, word state | Turn steps into loops without copying |
| 1D | Concepts c19–c24: terminators, callbacks, recursion | Explain memory, termination, and progress |
| 2A | All 12 level 1 problems | Fix all; rewrite two from scratch the next day |
| 2B | All 19 level 2 problems | Fix all; test empty input, signs, bytes, and limits |
| 2C | All 15 level 3 problems | Fix all; explain parsing and ranges |
| 2D | All 10 level 4 problems | Fix all; draw lists and allocations |
| 3 | Four original mock exam problems, one per level | Implement from scratch without hints or solution references |

Removing one defect is not enough to prove understanding: close the file and rewrite your solution in a scratch file before advancing. For linked lists, read the `.h` first and draw the head, next, and data. The bank uses two list types with different data fields; keep their definitions separate.

## Practice bank

`practice/level_1` through `practice/level_4` contain the 56 modified sources. Each `SUBJECT.md` preserves the original exercise contract. The material is a study bank, not a current official exam specification.

Comments explain concepts and a reasoning approach. Each starter has an introduced defect, and some original sources have other limitations. For example, do not assume a supplied implementation handles `INT_MIN` correctly. Your goal is to meet the contract and understand each failure.

```sh
python3 tester.py list
python3 tester.py ft_strlen
python3 tester.py level1
python3 tester.py all
```

`next` checks concepts before the practice bank. Progress is tied to source contents: changing a passed source makes it pending again. `--watch` reruns tests when you save; `Ctrl+C` stops it. Compilation and executables use temporary directories, leaving your sources in place.

## What the tester checks

Compilation uses `-Wall -Wextra -Werror`. Tests check function results, exact program output including spaces and newlines, execution timeouts, and AddressSanitizer/UndefinedBehaviorSanitizer diagnostics. Expectations were written separately from the supplied practice code. Function harnesses are in `tests/`; program cases and oracles are in `tests/programs.py`.

Sanitizers help detect out-of-bounds access and undefined behavior; they do not prove the absence of every memory leak or every invalid operation. Harnesses free returned allocations where applicable. Cases include empty strings, spaces/tabs, int extremes in itoa, ranges in both directions, empty lists, head removal, and repeated values. Bit reversal and nibble swapping test all 256 byte values.

If your compiler does not support sanitizers, `--no-sanitize` runs with reduced memory checking. The tester does not certify Norminette compliance, allowed function usage, injected malloc failures, or equivalence with the official grader. Check permitted functions in the subject: libraries used by the harness are not automatically allowed in your submission. Inputs stay within the documented contracts and representable ranges.

**PASSED means passed these local tests.** Preparation also requires rewriting, explaining, and trying examples of your own.

## Mock exam with a tutor

After completing both initial stages, run:

```sh
python3 mock_exam.py
```

The command checks your progress and creates four original challenges with empty implementations. There are no implementation hints in this stage. Its suggested 180-minute duration is a training choice, not an official exam rule.

Attempt one level at a time and ask for feedback after your attempt. Use the local tests to check your code; a peer or tutor can help review the reasoning.
