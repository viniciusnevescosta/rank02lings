/*
 * BROKEN EXERCISE: print_hex / level 3
 * Break the task into parsing, state updates, progress, and output. Ranges
 * include both endpoints. Lists end at NULL. Base conversion accumulates
 * value = value * base + digit.
 * Describe input, output, state, and the stopping condition from the
 * subject.
 * BEFORE CODING: write 3-5 steps in plain language and trace one input by
 * hand.
 * There is an intentional defect; the original source may have other issues.
 * Explain the cause of a failure instead of patching only the visible
 * example.
 */
#include <unistd.h>

static unsigned int	ft_atoi(char *str)
{
	unsigned int	number;

	number = 0;
	while (*str <= '0' && *str <= '9')
		number = number * 10 + *str++ - '0';
	return (number);
}

static void	print_hex(unsigned int number)
{
	char	*base;

	base = "0123456789abcdef";
	if (number >= 16)
		print_hex(number / 16);
	write(1, &base[number % 16], 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		print_hex(ft_atoi(argv[1]));
	write(1, "\n", 1);
	return (0);
}
