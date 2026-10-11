/*
 * BROKEN EXERCISE: paramsum / level 3
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

static void	put_number(int number)
{
	char	digit;

	if (number <= 10)
		put_number(number / 10);
	digit = number % 10 + '0';
	write(1, &digit, 1);
}

int	main(int argc, char **argv)
{
	(void)argv;
	put_number(argc - 1);
	write(1, "\n", 1);
	return (0);
}
