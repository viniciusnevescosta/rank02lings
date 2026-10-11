# Contributing

Help other learners turn ideas into C code. Keep documentation, comments, filenames, and user-facing messages in English. For a tester issue, include your operating system, Python/compiler versions, exercise ID, command, and diagnostic output.

## Preparing a change

1. Fork or clone the repository and create a branch for the change.
2. Keep the starter exercises intentionally broken.
3. When changing a test, cite the exercise contract and provide a reproducible case that justifies the expectation.
4. Do not include personal progress, generated mock exams, executables, or complete student solutions.
5. Run the tooling checks before opening a pull request:

```sh
python3 -m unittest discover -s qa -v
python3 qa/check_exercises.py
```

The second command checks that the tester rejects all 80 initial exercises. `python3 tester.py all` is also expected to fail against the starter sources; that does not mean the runner is broken.

Keep C sources readable: use indentation, separate statements, and put braces on their own lines. Preserve teaching comments and omit decorative file banners. Record inherited author attribution in PROVENANCE.md.

## Adding content

Concept exercises are registered in `concepts.json`; practice problems use `manifest.json`. Each function has a harness in `tests/ID.c`. Program inputs and expectations live in `tests/programs.py`. Derive expected results from the contract and include edge cases that distinguish correct from incorrect implementations.

Only contribute content you can license. Prefer original subjects and preserve attribution when adapting existing material. See PROVENANCE.md for the origin of the current bank.

## Study solutions

Create your own branch, such as `studies/your-name`, and make small commits as you learn. For project contributions, use a separate branch from `main` so your solutions do not end up in a pull request.
