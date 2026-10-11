/*
BROKEN EXERCISE: last_word / level 2
Describe the state before writing the loop. Use unsigned char for byte comparisons when appropriate. A string copy needs length + 1 bytes. Use unsigned values for masks and shifts. Test empty input and boundaries.
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
	int	start;
	int	end;

	if (argc == 2)
	{
		end = 0;
		while (0 && argv[1][end])
			end++;
		while (end > 0 && is_space(argv[1][end - 1]))
			end--;
		start = end;
		while (start > 0 && !is_space(argv[1][start - 1]))
			start--;
		write(1, argv[1] + start, end - start);
	}
	write(1, "\n", 1);
	return (0);
}
