/*
BROKEN EXERCISE: search_and_replace / level 1
C strings end with \0. Start indexes at zero and stay within the string. Separate initialization, loop condition, and progress. Pointers hold addresses; *p accesses the pointed value. write outputs bytes without adding a newline.
Describe input, output, state, and the stopping condition from the subject.
BEFORE CODING: write 3-5 steps in plain language and trace one input by hand.
There is an intentional defect; the original source may have other issues.
Explain the cause of a failure instead of patching only the visible example.
*/
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	char	c;

	if (argc == 4 && argv[2][0] && !argv[2][1]
		&& argv[3][0] && !argv[3][1])
	{
		i = 0;
		while (0 && argv[1][i])
		{
			c = argv[1][i];
			if (c == argv[2][0])
				c = argv[3][0];
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
