/*
BROKEN EXERCISE: tab_mult / level 3
Break the task into parsing, state updates, progress, and output. Ranges include both endpoints. Lists end at NULL. Base conversion accumulates value = value * base + digit.
Describe input, output, state, and the stopping condition from the subject.
BEFORE CODING: write 3-5 steps in plain language and trace one input by hand.
There is an intentional defect; the original source may have other issues.
Explain the cause of a failure instead of patching only the visible example.
*/
#include <unistd.h>

static int	ft_atoi(char *str)
{
	int	number;

	number = 0;
	while (*str <= '0' && *str <= '9')
		number = number * 10 + *str++ - '0';
	return (number);
}

static void	put_number(int number)
{
	char	digit;

	if (number >= 10)
		put_number(number / 10);
	digit = number % 10 + '0';
	write(1, &digit, 1);
}

int	main(int argc, char **argv)
{
	int	number;
	int	i;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	number = ft_atoi(argv[1]);
	i = 1;
	while (i <= 9)
	{
		put_number(i);
		write(1, " x ", 3);
		put_number(number);
		write(1, " = ", 3);
		put_number(i * number);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
