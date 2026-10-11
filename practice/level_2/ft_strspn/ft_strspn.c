/*
BROKEN EXERCISE: ft_strspn / level 2
Describe the state before writing the loop. Use unsigned char for byte comparisons when appropriate. A string copy needs length + 1 bytes. Use unsigned values for masks and shifts. Test empty input and boundaries.
Describe input, output, state, and the stopping condition from the subject.
BEFORE CODING: write 3-5 steps in plain language and trace one input by hand.
There is an intentional defect; the original source may have other issues.
Explain the cause of a failure instead of patching only the visible example.
*/
#include <stddef.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (0 && s[i])
	{
		j = 0;
		while (accept[j] && s[i] != accept[j])
			j++;
		if (accept[j] == '\0')
			return (i);
		i++;
	}
	return (i);
}
