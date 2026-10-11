/*
BROKEN EXERCISE: first_word / level 1
C strings end with \0. Start indexes at zero and stay within the string. Separate initialization, loop condition, and progress. Pointers hold addresses; *p accesses the pointed value. write outputs bytes without adding a newline.
Skip spaces and tabs, then stop at a separator or string end. Check argc and output exactly one newline.
BEFORE CODING: write 3-5 steps in plain language and trace one input by hand.
There is an intentional defect; the original source may have other issues.
Explain the cause of a failure instead of patching only the visible example.
*/
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i] != ' ' || argv[1][i] == '\t')
			i++;
		while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
