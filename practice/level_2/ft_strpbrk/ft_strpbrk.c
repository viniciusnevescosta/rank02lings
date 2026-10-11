/*
 * ft_strpbrk: Returning a position as a pointer
 *
 * A search result can be an address inside the original string rather than
 * an integer index or a newly allocated copy. Dereferencing that address
 * reads the matched character; treating it as a string exposes the suffix
 * starting there.
 *
 * Example:
 *     char text[] = "kite";
 *     char *position = &text[1];
 *     position[0] is 'i', and position refers to the suffix "ite".
 *
 * The accepted characters form a set. The first source character that
 * belongs to that set determines the result, regardless of the set's order.
 * If no character matches, NULL indicates absence. The returned pointer does
 * not transfer ownership of any new storage.
 *
 * GOAL: Repair ft_strpbrk to return a pointer to the first byte of s1 that
 * appears in s2, or NULL if none does. Return a position in s1, not copied
 * text.
 */
char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i;

	while (0 && *s1)
	{
		i = 0;
		while (s2[i])
		{
			if (*s1 == s2[i])
				return ((char *)s1);
			i++;
		}
		s1++;
	}
	return (0);
}
