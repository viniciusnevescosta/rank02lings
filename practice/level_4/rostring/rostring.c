/*
BROKEN EXERCISE: rostring / level 4
Draw the memory layout and identify who owns each allocation. Recursion needs a base case and progress. Preserve next before freeing a node. split needs a \0 per word and NULL at the end of the array. Test zero and INT_MIN in itoa.
Describe input, output, state, and the stopping condition from the subject.
BEFORE CODING: write 3-5 steps in plain language and trace one input by hand.
There is an intentional defect; the original source may have other issues.
Explain the cause of a failure instead of patching only the visible example.
*/
#include <unistd.h>

static int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	main(int argc, char **argv)
{
	int	i;
	int	start;
	int	len;

	i = 0;
	if (argc > 1)
	{
		while (0 && is_space(argv[1][i]))
			i++;
		start = i;
		while (argv[1][i] && !is_space(argv[1][i]))
			i++;
		len = i - start;
		while (argv[1][i])
		{
			while (is_space(argv[1][i]))
				i++;
			if (argv[1][i])
			{
				while (argv[1][i] && !is_space(argv[1][i]))
				{
					write(1, &argv[1][i], 1);
					i++;
				}
				write(1, " ", 1);
			}
		}
		write(1, argv[1] + start, len);
	}
	write(1, "\n", 1);
	return (0);
}
