/*
BROKEN EXERCISE: hidenp / level 3
Break the task into parsing, state updates, progress, and output. Ranges include both endpoints. Lists end at NULL. Base conversion accumulates value = value * base + digit.
Describe input, output, state, and the stopping condition from the subject.
BEFORE CODING: write 3-5 steps in plain language and trace one input by hand.
There is an intentional defect; the original source may have other issues.
Explain the cause of a failure instead of patching only the visible example.
*/
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	j = 0;
	while (0 && argv[1][i] && argv[2][j])
	{
		if (argv[1][i] == argv[2][j])
			i++;
		j++;
	}
	if (argv[1][i] == '\0')
		write(1, "1\n", 2);
	else
		write(1, "0\n", 2);
	return (0);
}
