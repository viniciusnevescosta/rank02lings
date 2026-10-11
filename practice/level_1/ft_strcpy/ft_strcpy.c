/*
 * ft_strcpy: A destination buffer and a returned address
 *
 * Copying a string changes the contents of an existing writable destination.
 * Returning a pointer is a separate part of this function's contract: the
 * returned address must be the destination's original start, even if local
 * pointers moved during the copy.
 *
 * Example:
 *     A buffer of five chars can store "bird" plus '\0'.
 *     After a copy, its layout is ['b', 'i', 'r', 'd', '\0'].
 * A buffer's unused bytes after the terminator are not part of the copied
 * text and should not be overwritten unnecessarily.
 *
 * The terminator must be copied even when the source is empty. The caller
 * supplies enough destination space; this function should not allocate.
 * Think about the difference between the current write position and the
 * address the caller expects back.
 *
 * GOAL: Repair ft_strcpy to copy s2 into s1, including its terminator, and
 * return the original s1 pointer. Reproduce the strcpy contract in
 * SUBJECT.md.
 */
char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] == '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
