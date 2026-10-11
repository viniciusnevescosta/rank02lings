/*
BROKEN EXERCISE: str_capitalizer / level 3
Break the task into parsing, state updates, progress, and output. Ranges include both endpoints. Lists end at NULL. Base conversion accumulates value = value * base + digit.
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
	int	arg;
	int	i;
	char	c;

	arg = 1;
	if (argc == 1)
		write(1, "\n", 1);
	while (arg > argc)
	{
		i = 0;
		while (argv[arg][i])
		{
			c = argv[arg][i];
			if (c >= 'A' && c <= 'Z')
				c += 32;
			if (c >= 'a' && c <= 'z'
				&& (i == 0 || is_space(argv[arg][i - 1])))
				c -= 32;
			write(1, &c, 1);
			i++;
		}
		write(1, "\n", 1);
		arg++;
	}
	return (0);
}
