/*
 * c09_find: Search results and an absent-value sentinel
 *
 * A search must distinguish finding a character at position zero from not
 * finding it at all. Returning zero for both cases would lose information. A
 * negative value can represent absence because valid string indexes are
 * nonnegative.
 *
 * Example:
 *     "banana" has 'a' at indexes 1, 3, and 5.
 *     The first match is at index 1.
 *     'x' has no matching index.
 *
 * Keep the scan inside the text, ending at '\0'. A match should finish the
 * search immediately if the contract asks for the first occurrence.
 * Continuing to overwrite a saved position would instead produce the last
 * occurrence. This exercise searches text characters, not the terminator.
 *
 * GOAL: Make find return the first index containing c, or -1 if it is
 * absent. Examples: ("banana", 'a') -> 1; ("banana", 'x') -> -1; ("", 'a')
 * -> -1.
 */
#include <stdlib.h>
#include <string.h>

int	find(char *s, char c)
{
	(void)s;
	(void)c;
	return (-1);
}
