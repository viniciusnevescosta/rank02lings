/*
 * BROKEN EXERCISE: ft_strcpy / level 1
 * C strings end with \0. Start indexes at zero and stay within the string.
 * Separate initialization, loop condition, and progress. Pointers hold
 * addresses; *p accesses the pointed value. write outputs bytes without
 * adding a newline.
 * Copy the terminator too. Return the original destination address.
 * BEFORE CODING: write 3-5 steps in plain language and trace one input by
 * hand.
 * There is an intentional defect; the original source may have other issues.
 * Explain the cause of a failure instead of patching only the visible
 * example.
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
