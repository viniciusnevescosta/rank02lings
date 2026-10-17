/*
 * c12_duplicate: Allocated storage and ownership
 *
 * Returning a pointer does not extend the lifetime of a local array. Storage
 * obtained from malloc survives the function call until somebody frees it.
 * The returned pointer transfers responsibility for that allocation to the
 * caller.
 *
 * Example:
 *     char *buffer = malloc(4 * sizeof(char));
 *     if (buffer == NULL) return NULL; // allocation failed
 *     free(buffer);         // after the caller finishes using it
 * Do not use the buffer after free. A pointer assignment alone would alias
 * the original string rather than create new storage.
 *
 * The allocation must fit the text and its '\0'. An empty duplicate still
 * needs one byte. strlen is allowed in this concept exercise to measure the
 * text length; it does not include the terminator.
 *
 * GOAL: Make duplicate return a separately allocated copy of s, including
 * its terminator. Return NULL if allocation fails. The caller must be able
 * to free the result.
 */
#include <stdlib.h>
#include <string.h>

char	*duplicate(char *s)
{
	int i;
	char *heap;

	i = 0;
	while (s[i])
		i++;

	heap = malloc(sizeof(char) * i + 1);
	if (!heap)
		return (NULL);

	i = 0;
	while (s[i])
	{
		heap[i] = s[i];
		i++;
	}
	heap[i] = '\0';

	return (heap);
}
