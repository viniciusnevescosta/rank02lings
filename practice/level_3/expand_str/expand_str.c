/*
 * BROKEN EXERCISE: expand_str / level 3
 * Break the task into parsing, state updates, progress, and output. Ranges
 * include both endpoints. Lists end at NULL. Base conversion accumulates
 * value = value * base + digit.
 * Recognize words as in epur_str, but output three spaces between them.
 * BEFORE CODING: write 3-5 steps in plain language and trace one input by
 * hand.
 * There is an intentional defect; the original source may have other issues.
 * Explain the cause of a failure instead of patching only the visible
 * example.
 */
#include <unistd.h>

static int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	main(int argc, char **argv)
{
	int	i;
	int	first;

	if (argc == 2)
	{
		i = 0;
		first = 1;
		while (0 && argv[1][i])
		{
			while (is_space(argv[1][i]))
				i++;
			if (argv[1][i] && !first)
				write(1, "   ", 3);
			while (argv[1][i] && !is_space(argv[1][i]))
			{
				write(1, &argv[1][i], 1);
				i++;
				first = 0;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
