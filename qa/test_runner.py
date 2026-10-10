"""Integration checks for the runner, not student solutions."""
import contextlib
import io
import json
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch
import sys

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import tester
import simulado


class RunnerTests(unittest.TestCase):
    def setUp(self):
        self.directory = tempfile.TemporaryDirectory(prefix="rank02lings-qa-")
        self.root = Path(self.directory.name)
        (self.root / "tests").mkdir()
        (self.root / "exercises/sample").mkdir(parents=True)
        self.source = self.root / "exercises/sample/sample.c"
        self.entry = {"id": "sample", "level": 1, "kind": "function",
                      "path": "exercises/sample"}
        (self.root / "tests/function_output.json").write_text('{}')
        (self.root / "tests/sample.c").write_text(
            '#include "STUDENT_SOURCE"\nint main(void){return add(2,3)!=5;}\n')
        self.root_patch = patch.object(tester, "ROOT", self.root)
        self.root_patch.start()

    def tearDown(self):
        self.root_patch.stop()
        self.directory.cleanup()

    def test_correct_function_and_content_change(self):
        self.source.write_text('int add(int a,int b){return a+b;}')
        self.assertTrue(tester.run(self.entry)[0])
        before = tester.fingerprint(self.entry)
        tester.save_progress({"sample": before})
        self.assertEqual(tester.load_progress()["sample"], before)
        self.source.write_text('int add(int a,int b){return a-b;}')
        self.assertNotEqual(before, tester.fingerprint(self.entry))
        self.assertFalse(tester.run(self.entry)[0])

    def test_compilation_failure_has_diagnostic(self):
        self.source.write_text('this is invalid C;')
        ok, message = tester.run(self.entry)
        self.assertFalse(ok)
        self.assertIn('COMPILAÇÃO', message)

    def test_memory_error_is_rejected(self):
        self.source.write_text(
            '#include <stdlib.h>\nint add(int a,int b){'
            'volatile int *p=malloc(sizeof(int));p[100]=a;free((void*)p);return a+b;}')
        ok, message = tester.run(self.entry)
        self.assertFalse(ok)
        self.assertIn('EXECUÇÃO/MEMÓRIA', message)

    def test_nonterminating_function_times_out(self):
        self.source.write_text('int add(int a,int b){(void)a;(void)b;while(1){}}')
        ok, message = tester.run(self.entry)
        self.assertFalse(ok)
        self.assertIn('TEMPO ESGOTADO', message)

    def test_program_output_is_compared_exactly(self):
        self.entry['kind'] = 'program'
        self.source.write_text('#include <stdio.h>\nint main(void){puts("hello");return 0;}')
        with patch.object(tester, 'cases', return_value=[[]]), \
                patch.object(tester, 'oracle', return_value='hello\n'):
            self.assertTrue(tester.run(self.entry)[0])
        with patch.object(tester, 'cases', return_value=[[]]), \
                patch.object(tester, 'oracle', return_value='hello'):
            ok, message = tester.run(self.entry)
            self.assertFalse(ok)
            self.assertIn('esperado=', message)

    def test_unknown_id_returns_argument_error(self):
        with patch.object(tester, 'ALL', [self.entry]), \
                patch.object(sys, 'argv', ['tester.py', 'unknown']), \
                contextlib.redirect_stderr(io.StringIO()):
            with self.assertRaises(SystemExit) as raised:
                tester.main()
            self.assertEqual(raised.exception.code, 2)

    def test_success_saves_progress_and_next_is_complete(self):
        self.source.write_text('int add(int a,int b){return a+b;}')
        with patch.object(tester, 'ALL', [self.entry]), \
                patch.object(sys, 'argv', ['tester.py', 'next']), \
                contextlib.redirect_stdout(io.StringIO()):
            self.assertEqual(tester.main(), 0)
            self.assertEqual(tester.load_progress()['sample'], tester.fingerprint(self.entry))
            self.assertEqual(tester.main(), 0)

    def test_mock_exam_unlock_and_repeated_command(self):
        self.source.write_text('int add(int a,int b){return a+b;}')
        with patch.object(tester, 'ALL', [self.entry]), \
                patch.object(simulado, 'R', self.root), \
                contextlib.redirect_stdout(io.StringIO()):
            simulado.main()
            self.assertFalse((self.root / 'simulation.json').exists())
            tester.save_progress({'sample': tester.fingerprint(self.entry)})
            simulado.main()
            entries = json.loads((self.root / 'simulation.json').read_text())
            self.assertEqual([e['level'] for e in entries], [1,2,3,4])
            first = self.root / entries[0]['path'] / (entries[0]['id'] + '.c')
            first.write_text('my attempt')
            simulado.main()
            self.assertEqual(first.read_text(), 'my attempt')


if __name__ == '__main__':
    unittest.main()
