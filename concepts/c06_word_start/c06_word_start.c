/*
 * c06_word_start: An index can represent a boundary
 *
 * A position in a string is a zero-based index, not a pointer. Skipping a
 * prefix means moving the index across characters that belong to that
 * prefix, then preserving the first position outside it.
 *
 * Trace:
 *     text:   "  hi"
 *     index:   0 1 2 3
 *     bytes:   space, space, 'h', 'i'
 * The first word starts at index 2. The characters of that word do not need
 * to be counted for this task.
 *
 * Check the end marker as well as the separator rule. If the entire string
 * consists of spaces and tabs, there is no word; the stopping position is
 * the index of '\0'. Reading beyond it would inspect memory outside the
 * string.
 *
 * GOAL: Make word_start return the index after all leading spaces and tabs.
 * Examples: "  hi" -> 2; "hi" -> 0; "  " -> 2; "" -> 0.
 */

int	word_start(char *s)
{
	(void)s;
	return (0);
}
