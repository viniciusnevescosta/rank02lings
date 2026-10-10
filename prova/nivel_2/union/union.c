/*
BROKEN EXERCISE: union / level 2
Describe the state before writing the loop. Use unsigned char for byte comparisons when appropriate. A string copy needs length + 1 bytes. Use unsigned values for masks and shifts. Test empty input and boundaries.
Describe input, output, state, and the stopping condition from the subject.
BEFORE CODING: write 3-5 steps in plain language and trace one input by hand.
There is an intentional defect; the original source may have other issues.
Explain the cause of a failure instead of patching only the visible example.
*/
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	seen[256];
	int	arg;
	int	i;

	i = 0;
	while (i < 256)
		seen[i++] = 0;
	if (argc == 3)
	{
		arg = 1;
		while (arg < 2)
		{
			i = 0;
			while (argv[arg][i])
			{
				if (!seen[(unsigned char)argv[arg][i]])
				{
					write(1, &argv[arg][i], 1);
					seen[(unsigned char)argv[arg][i]] = 1;
				}
				i++;
			}
			arg++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
