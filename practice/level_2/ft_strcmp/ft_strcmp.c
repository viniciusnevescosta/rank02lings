/*
 * BROKEN EXERCISE: ft_strcmp / level 2
 * Describe the state before writing the loop. Use unsigned char for byte
 * comparisons when appropriate. A string copy needs length + 1 bytes. Use
 * unsigned values for masks and shifts. Test empty input and boundaries.
 * Describe input, output, state, and the stopping condition from the
 * subject.
 * BEFORE CODING: write 3-5 steps in plain language and trace one input by
 * hand.
 * There is an intentional defect; the original source may have other issues.
 * Explain the cause of a failure instead of patching only the visible
 * example.
 */
int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 != *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
