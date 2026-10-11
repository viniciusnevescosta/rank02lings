#!/usr/bin/env python3
"""Unlock four original mock exam problems after the learning track."""
from pathlib import Path
import datetime
import json
import tester

R = Path(__file__).resolve().parent
TASKS = [
    ('s01_first_word_length', 1, 'int\tfirst_word_length(char *s)',
     (
         'Implement int first_word_length(char *s). Return the length of the '
         'first word, skipping leading spaces and tabs. A word ends at a space, '
         'tab, or string terminator. Return 0 if there are no words. Allowed '
         'functions: none. '
     ),
     r"""
    CHECK(first_word_length("") == 0);
    CHECK(first_word_length(" \t ") == 0);
    CHECK(first_word_length(" \t abc de") == 3);
    CHECK(first_word_length("hello") == 5);
    CHECK(first_word_length("a\tb") == 1);
"""),
    ('s02_swap_adjacent_bits', 2, 'unsigned char\tswap_adjacent_bits(unsigned char n)',
     (
         'Implement unsigned char swap_adjacent_bits(unsigned char n). Swap each '
         'adjacent pair of bits: positions 0 and 1, 2 and 3, 4 and 5, 6 and 7. '
         'Position 0 is the least significant bit. Examples: 1 becomes 2; 2 '
         'becomes 1; 3 stays 3; 128 becomes 64. Allowed functions: none. '
     ),
     r"""
    for (unsigned int n = 0; n < 256; n++)
    {
        unsigned int r = 0;
        for (int i = 0; i < 8; i += 2)
        {
            r += ((n >> i) & 1) << (i + 1);
            r += ((n >> (i + 1)) & 1) << i;
        }
        CHECK(swap_adjacent_bits(n) == r);
    }
"""),
    ('s03_even_range', 3, 'int\t*even_range(int start, int end, int *count)',
     (
         'Implement int *even_range(int start, int end, int *count). Return an '
         'allocated array containing only the even integers from start to end, '
         'inclusive, in the direction from start toward end. Store the number of '
         'elements in *count. If there are no even integers, return NULL and set '
         'count to 0. On malloc failure, return NULL and set count to 0. start '
         'and end are between -10000 and 10000; count is a valid pointer. '
         'Examples: (1,6) => [2,4,6]; (4,-1) => [4,2,0]; (3,3) => NULL. Allowed '
         'functions: malloc. '
     ),
     r"""
    for (int a = -5; a <= 5; a++)
        for (int b = -5; b <= 5; b++)
        {
            int count = -1;
            int *p = even_range(a, b, &count);
            int v = a, k = 0;
            while (1)
            {
                if (v % 2 == 0)
                    k++;
                if (v == b)
                    break;
                v += a <= b ? 1 : -1;
            }
            CHECK(count == k);
            if (!k)
            {
                CHECK(p == NULL);
                continue;
            }
            CHECK(p);
            v = a;
            int j = 0;
            while (1)
            {
                if (v % 2 == 0)
                    CHECK(p[j++] == v);
                if (v == b)
                    break;
                v += a <= b ? 1 : -1;
            }
            free(p);
        }
"""),
    ('s04_compact_list', 4, 't_list\t*compact_list(t_list *lst)',
     (
         'Implement t_list *compact_list(t_list *lst) using the type provided in '
         'list.h. Remove and free nodes that repeat the value of the immediately '
         'preceding node, keeping the first node in each run of equal values. '
         'Return the resulting head. Do not remove repetitions separated by '
         'another value. Example: [1,1,2,1,1,3,3] => [1,2,1,3]. An empty list '
         'returns NULL. Nodes were allocated individually; data is int. Allowed '
         'functions: free. '
     ),
     r"""
    CHECK(compact_list(NULL) == NULL);
    int vals[] = {1, 1, 2, 1, 1, 3, 3}, expected[] = {1, 2, 1, 3};
    t_list *head = NULL;
    for (int i = 6; i >= 0; i--)
    {
        t_list *p = malloc(sizeof(*p));
        CHECK(p);
        p->data = vals[i];
        p->next = head;
        head = p;
    }
    t_list *original = head;
    head = compact_list(head);
    CHECK(head == original);
    for (int i = 0; i < 4; i++)
    {
        CHECK(head);
        CHECK(head->data == expected[i]);
        t_list *next = head->next;
        free(head);
        head = next;
    }
    CHECK(head == NULL);
"""),
]

def main():
    state = json.loads((R / "progress.json").read_text()) if (R / "progress.json").exists() else {}
    required = [e for e in tester.ALL if not e["id"].startswith("s0")]
    pending = [e["id"] for e in required if state.get(e["id"]) != tester.fingerprint(e)]
    if pending:
        print(f"Mock exam locked: {len(pending)} exercises still need to pass with their current contents. Next: {pending[0]}.")
        return
    if (R / "simulation.json").exists():
        print("Mock exam already unlocked. Sources are in mock_exam/. Run python3 tester.py s01_first_word_length.")
        return
    entries = []
    for identifier, level, signature, subject, test in TASKS:
        folder = R / "mock_exam" / identifier
        folder.mkdir(parents=True, exist_ok=True)
        include = "#include <stdlib.h>\n" if level >= 3 else ""
        if level == 4:
            include += '#include "list.h"\n'
            (folder / "list.h").write_text("typedef struct s_list\n{\n\tint\t\t\t\tdata;\n\tstruct s_list\t*next;\n}\tt_list;\n")
        (folder / (identifier + ".c")).write_text(
            include + ("\n" if include else "") + signature + "\n{\n}\n")
        (folder / "SUBJECT.md").write_text(f"# Level {level}\n\n{subject}\n")
        harness = r"""#include <stdio.h>
#include <stdlib.h>
#define CHECK(x)                                                               \
	do                                                                         \
	{                                                                          \
		if (!(x))                                                              \
		{                                                                      \
			fprintf(stderr, "Failure: %s\n", #x);                              \
			return 1;                                                          \
		}                                                                      \
	} while (0)
#include "STUDENT_SOURCE"
""" + "\nint\tmain(void)\n{\n" + test.strip("\n").replace("    ", "\t") + "\n\treturn (0);\n}\n"
        (R / "tests" / (identifier + ".c")).write_text(harness)
        entries.append({"id": identifier, "level": level, "path": str(folder.relative_to(R)), "kind": "function"})
    (R / "simulation.json").write_text(json.dumps(entries, indent=2))
    (R / "mock_exam/START.txt").write_text(
        datetime.datetime.now(datetime.timezone.utc).isoformat()
        + "\nSuggested practice: 180 minutes, without references. This is not an official exam duration.\n")
    print("Mock exam unlocked: four exercises in mock_exam/. Start with level 1. Suggested duration: 180 minutes. Practice with a peer or tutor.")


if __name__ == "__main__":
    main()
