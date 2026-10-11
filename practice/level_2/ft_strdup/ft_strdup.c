/*
 * ft_strdup: A duplicate must have its own lifetime and storage
 *
 * Two pointers can refer to the same text without creating a duplicate.
 * strdup instead allocates a second buffer and copies the characters, so
 * changing or freeing the new allocation does not change the original
 * object.
 *
 * Example:
 *     Original storage: ['o', 'w', 'l', '\0'].
 *     Duplicate storage: another four-byte region with the same
 *     contents.
 *     The two starting addresses are different.
 *
 * Allocation size includes the terminator. An empty string therefore still
 * needs a one-byte allocation. A local array cannot be returned safely
 * because its lifetime ends at return. Check malloc's result before writing;
 * the caller owns and frees a successful duplicate.
 *
 * GOAL: Repair ft_strdup to return a malloc-allocated copy of src including
 * its terminator, or NULL when allocation fails. Use only malloc from the
 * library.
 */
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*copy;
	int		len;
	int		i;

	len = 0;
	while (0 && src[len])
		len++;
	copy = malloc(len + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
