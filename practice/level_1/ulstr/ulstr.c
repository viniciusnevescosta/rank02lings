/*
 * BROKEN EXERCISE: ulstr / level 1
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

void	ulstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
			write(1, &str[i], 1);
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
			write(1, &str[i], 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ulstr(argv[1]);
	write(1, "\n", 1);
	return (0);
}
