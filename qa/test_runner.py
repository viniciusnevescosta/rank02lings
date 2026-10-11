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
import mock_exam


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
        (self.root / "tests/checks.h").write_bytes(
            (Path(__file__).resolve().parents[1] / "tests/checks.h").read_bytes())
        (self.root / "tests/sample.c").write_text(
            '#include "checks.h"\n#include "STUDENT_SOURCE"\n'
            'int main(void){CHECK_INT(add(2,3),5);return 0;}\n')
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
        self.assertIn('COMPILATION', message)
        self.assertIn(str(self.source), message)

    def test_memory_error_is_rejected(self):
        self.source.write_text(
            '#include <stdlib.h>\nint add(int a,int b){'
            'volatile int *p=malloc(sizeof(int));p[100]=a;free((void*)p);return a+b;}')
        ok, message = tester.run(self.entry)
        self.assertFalse(ok)
        self.assertIn('RUNTIME/MEMORY', message)

    def test_nonterminating_function_times_out(self):
        self.source.write_text('int add(int a,int b){(void)a;(void)b;while(1){}}')
        ok, message = tester.run(self.entry)
        self.assertFalse(ok)
        self.assertIn('TIMEOUT', message)

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
            self.assertIn('Expected: "hello"', message)
            self.assertIn('Obtained: "hello\\n"', message)

    def test_c_values_distinguish_assertions_from_memory_errors(self):
        self.source.write_text('int add(int a,int b){return a-b;}')
        ok, message = tester.run(self.entry)
        self.assertFalse(ok)
        self.assertIn('C CHECK FAILED', message)
        self.assertNotIn('RUNTIME/MEMORY', message)
        self.assertIn('Expected: 5', message)
        self.assertIn('Obtained: -1', message)
        self.assertIn('C test: tests/sample.c:3', message)

    def test_reporting_does_not_evaluate_a_call_twice(self):
        self.source.write_text('int add(int a,int b){return a+b;}')
        (self.root / 'tests/sample.c').write_text(
            '#include "checks.h"\n#include "STUDENT_SOURCE"\n'
            'int main(void){int n=0;CHECK_INT(++n,1);CHECK_INT(n,1);return 0;}\n')
        ok, message = tester.run(self.entry)
        self.assertTrue(ok, message)
        self.assertEqual(message.count('Obtained: 1'), 2)

    def test_string_values_keep_quotes_tabs_and_newlines(self):
        self.source.write_text('int add(int a,int b){return a+b;}')
        (self.root / 'tests/sample.c').write_text(
            '#include "checks.h"\n#include "STUDENT_SOURCE"\n'
            r'int main(void){CHECK_STRING("a\t\"\\\n", "a\t\"\\\n");return 0;}' + '\n')
        ok, message = tester.run(self.entry)
        self.assertTrue(ok, message)
        self.assertIn('Expected: ' + json.dumps('a\t"\\\n'), message)
        self.assertIn('Obtained: ' + json.dumps('a\t"\\\n'), message)

    def test_large_reports_include_values_after_allocation_guards(self):
        self.source.write_text('int add(int a,int b){return a+b;}')
        (self.root / 'tests/sample.c').write_text(
            '#include "checks.h"\n#include "STUDENT_SOURCE"\n'
            'int main(void){int n=0;for(int i=0;i<7;i++){CHECK_NOT_NULL(&n);}'
            'CHECK_INT(add(2,3),5);return 0;}\n')
        ok, message = tester.run(self.entry)
        self.assertTrue(ok, message)
        self.assertIn('Obtained: 5', message)
        self.assertEqual(message.count('  PASS '), 6)
        ok, message = tester.run(self.entry, verbose=True)
        self.assertTrue(ok, message)
        self.assertEqual(message.count('  PASS '), 8)

    def second_exercise(self, correct=False):
        folder = self.root / 'exercises/second'
        folder.mkdir()
        source = folder / 'second.c'
        source.write_text('int add(int a,int b){return a' + ('+' if correct else '-') + 'b;}')
        (self.root / 'tests/second.c').write_bytes((self.root / 'tests/sample.c').read_bytes())
        return {'id': 'second', 'level': 1, 'kind': 'function', 'path': 'exercises/second'}, source

    def test_default_run_advances_to_the_next_failure_and_uses_colors(self):
        self.source.write_text('int add(int a,int b){return a+b;}')
        second, _ = self.second_exercise()
        third = {**second, 'id': 'third'}
        output = io.StringIO()
        with patch.object(tester, 'ALL', [self.entry, second, third]), \
                patch.object(sys, 'argv', ['tester.py', '--color', 'always']), \
                patch.object(tester, 'run', wraps=tester.run) as executed, \
                contextlib.redirect_stdout(output):
            self.assertEqual(tester.main(), 1)
        self.assertEqual([c.args[0]['id'] for c in executed.call_args_list], ['sample', 'second'])
        self.assertEqual(set(tester.load_progress()), {'sample'})
        self.assertIn('\033[32mPASSED sample', output.getvalue())
        self.assertIn('\033[31mFAILED second', output.getvalue())
        self.assertIn('Expected: 5', output.getvalue())
        self.assertIn('Obtained: -1', output.getvalue())

    def test_only_keeps_one_exercise_and_color_never_omits_escapes(self):
        self.source.write_text('int add(int a,int b){return a+b;}')
        second, _ = self.second_exercise()
        output = io.StringIO()
        with patch.object(tester, 'ALL', [self.entry, second]), \
                patch.object(sys, 'argv', ['tester.py', 'sample', '--only', '--color', 'never']), \
                contextlib.redirect_stdout(output):
            self.assertEqual(tester.main(), 0)
        self.assertNotIn('FAILED second', output.getvalue())
        self.assertNotIn('\033[', output.getvalue())

    def test_source_changed_during_a_run_is_not_saved_or_advanced(self):
        self.source.write_text('int add(int a,int b){return a+b;}')
        second, _ = self.second_exercise()

        def edited_during_execution(*args, **kwargs):
            self.source.write_text('int add(int a,int b){return a-b;}')
            return True, 'The previous contents passed.'

        output = io.StringIO()
        with patch.object(tester, 'ALL', [self.entry, second]), \
                patch.object(sys, 'argv', ['tester.py']), \
                patch.object(tester, 'run', side_effect=edited_during_execution) as executed, \
                contextlib.redirect_stdout(output):
            self.assertEqual(tester.main(), 1)
        self.assertEqual(executed.call_count, 1)
        self.assertEqual(tester.load_progress(), {})
        self.assertIn('Source changed during the run', output.getvalue())

    def test_watch_follows_the_next_exercise_after_success(self):
        self.source.write_text('int add(int a,int b){return a+b;}')
        second, source = self.second_exercise()
        with patch.object(tester, 'ALL', [self.entry, second]), \
                patch.object(sys, 'argv', ['tester.py', '--watch']), \
                patch.object(tester.time, 'sleep', side_effect=lambda _: source.write_text('int add(int a,int b){return a+b;}')), \
                patch.object(tester, 'run', wraps=tester.run) as executed, \
                contextlib.redirect_stdout(io.StringIO()):
            self.assertEqual(tester.main(), 0)
        self.assertEqual([c.args[0]['id'] for c in executed.call_args_list], ['sample', 'second', 'second'])
        self.assertEqual(set(tester.load_progress()), {'sample', 'second'})

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
                patch.object(mock_exam, 'R', self.root), \
                contextlib.redirect_stdout(io.StringIO()):
            mock_exam.main()
            self.assertFalse((self.root / 'simulation.json').exists())
            tester.save_progress({'sample': tester.fingerprint(self.entry)})
            mock_exam.main()
            entries = json.loads((self.root / 'simulation.json').read_text())
            self.assertEqual([e['level'] for e in entries], [1,2,3,4])
            # These deliberately wrong stubs check that every generated C
            # harness compiles and reports values; they are not solutions.
            stubs = [
                'int first_word_length(char *s){(void)s;return 0;}',
                'unsigned char swap_adjacent_bits(unsigned char n){return n;}',
                '#include <stdlib.h>\nint *even_range(int a,int b,int *n){(void)a;(void)b;*n=0;return NULL;}',
                '#include "list.h"\nt_list *compact_list(t_list *lst){return lst;}',
            ]
            for entry, stub in zip(entries, stubs):
                source = self.root / entry['path'] / (entry['id'] + '.c')
                source.write_text(stub)
                ok, message = tester.run(entry)
                self.assertFalse(ok, entry['id'])
                self.assertNotIn('COMPILATION', message, entry['id'])
                self.assertIn('Expected:', message, entry['id'])
                self.assertIn('Obtained:', message, entry['id'])
            first = self.root / entries[0]['path'] / (entries[0]['id'] + '.c')
            first.write_text('my attempt')
            mock_exam.main()
            self.assertEqual(first.read_text(), 'my attempt')


if __name__ == '__main__':
    unittest.main()
