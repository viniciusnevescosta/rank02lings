/*
 * BROKEN EXERCISE: rotone / level 1
 * C strings end with \0. Start indexes at zero and stay within the string.
 * Separate initialization, loop condition, and progress. Pointers hold
 * addresses; *p accesses the pointed value. write outputs bytes without
 * adding a newline.
 * Describe input, output, state, and the stopping condition from the
 * subject.
 * BEFORE CODING: write 3-5 steps in plain language and trace one input by
 * hand.
 * There is an intentional defect; the original source may have other issues.
 * Explain the cause of a failure instead of patching only the visible
 * example.
 */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	char	c;

	if (argc == 2)
	{
		i = 0;
		while (0 && argv[1][i])
		{
			c = argv[1][i];
			if (c == 'z' || c == 'Z')
				c -= 25;
			else if ((c >= 'a' && c <= 'y') || (c >= 'A' && c <= 'Y'))
				c++;
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
