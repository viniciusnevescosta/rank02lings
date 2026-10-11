/*
 * BROKEN EXERCISE: alpha_mirror / level 2
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
#include <unistd.h>

void	alpha_mirror(char *str)
{
	char	mirror;
	int		i;

	i = 0;
	while (str[i] == '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			mirror = 'z' - (str[i] - 'a');
		else if (str[i] >= 'A' && str[i] <= 'Z')
			mirror = 'Z' - (str[i] - 'A');
		else
			mirror = str[i];
		write(1, &mirror, 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		alpha_mirror(argv[1]);
	write(1, "\n", 1);
	return (0);
}
