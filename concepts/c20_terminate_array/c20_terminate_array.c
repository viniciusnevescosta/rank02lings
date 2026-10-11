/*
 * c20_terminate_array: A pointer terminator is not a character terminator
 *
 * A char ** can point to an array whose elements are char pointers. There
 * are two levels of data: the pointer slots, and the character sequences
 * those pointers refer to.
 *
 * Example:
 *     char *words[3] = {"red", "blue", NULL};
 *     words[1] is the address of "blue".
 *     words[1][0] is the character 'b'.
 *     words[2] is a NULL pointer, marking the end of the pointer array.
 *
 * Each word has its own '\0' byte. The pointer array instead ends with a
 * NULL pointer slot. Writing a zero character into a word changes that word;
 * it does not terminate the array of words. Here slot n exists and is
 * writable.
 *
 * GOAL: Make terminate_array place a NULL pointer in p[n], leaving the
 * preceding pointer slots unchanged. Do not alter the characters inside the
 * strings.
 */
#include <stddef.h>

void	terminate_array(char **p, int n)
{
	(void)p;
	(void)n;
}
