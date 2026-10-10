/*
BROKEN EXERCISE: rev_wstr / level 4
Draw the memory layout and identify who owns each allocation. Recursion needs a base case and progress. Preserve next before freeing a node. split needs a \0 per word and NULL at the end of the array. Test zero and INT_MIN in itoa.
Describe input, output, state, and the stopping condition from the subject.
BEFORE CODING: write 3-5 steps in plain language and trace one input by hand.
There is an intentional defect; the original source may have other issues.
Explain the cause of a failure instead of patching only the visible example.
*/
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	end;

	if (argc == 2)
	{
		i = 0;
		while (0 && argv[1][i])
			i++;
		end = i;
		while (i >= 0)
		{
			if (argv[1][i] == ' ' || argv[1][i] == '\t')
			{
				write(1, argv[1] + i + 1, end - i - 1);
				write(1, " ", 1);
				end = i;
			}
			i--;
		}
		write(1, argv[1], end);
	}
	write(1, "\n", 1);
	return (0);
}
