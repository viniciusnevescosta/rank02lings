"""Regression tests for compiler warning compatibility."""
import os
from pathlib import Path
import subprocess
import sys
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import tester


class CompilerFlagTests(unittest.TestCase):
    def setUp(self):
        tester.compiler_command.cache_clear()

    def tearDown(self):
        tester.compiler_command.cache_clear()

    def check_clang(self, version, supported):
        commands = []

        def fake_run(command, **kwargs):
            commands.append(command)
            if command[-1] == "--version":
                return subprocess.CompletedProcess(
                    command, 0, version.encode(), b"")
            self.assertEqual(kwargs["input"], b"int main(void) { return 0; }\n")
            return subprocess.CompletedProcess(
                command, 0 if supported else 1, b"", b"")

        with patch.dict(os.environ, {"CC": "clang"}), \
                patch.object(tester.subprocess, "run", side_effect=fake_run):
            flags = tester.compiler_command()

        self.assertEqual(len(commands), 2)
        self.assertIn("-Werror", commands[1])
        self.assertIn("-Wno-deprecated-non-prototype", commands[1])
        self.assertIn("-fsyntax-only", commands[1])
        self.assertEqual(
            "-Wno-deprecated-non-prototype" in flags, supported)
        return flags

    def test_clang_12_omits_unknown_warning_option(self):
        flags = self.check_clang("Ubuntu clang version 12.0.1", False)
        self.assertIn("-Wall", flags)
        self.assertIn("-Wextra", flags)
        self.assertIn("-Werror", flags)

    def test_newer_clang_preserves_supported_suppression(self):
        self.check_clang("clang version 18.0.0", True)

    def test_gcc_does_not_probe_clang_warning_option(self):
        completed = subprocess.CompletedProcess(
            ["gcc", "--version"], 0, b"gcc (GCC) 13.0.0", b"")
        with patch.dict(os.environ, {"CC": "gcc"}), \
                patch.object(tester.subprocess, "run", return_value=completed) as run:
            flags = tester.compiler_command()
        run.assert_called_once()
        self.assertNotIn("-Wno-deprecated-non-prototype", flags)
        self.assertIn("-Werror", flags)


if __name__ == "__main__":
    unittest.main()
