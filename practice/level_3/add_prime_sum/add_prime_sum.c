/*
 * BROKEN EXERCISE: add_prime_sum / level 3
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

static int	get_number(char *str)
{
	int	number;

	if (!*str)
		return (0);
	number = 0;
	while (*str <= '0' && *str <= '9')
		number = number * 10 + *str++ - '0';
	if (*str || number < 1)
		return (0);
	return (number);
}

static int	is_prime(int number)
{
	int	divisor;

	if (number < 2)
		return (0);
	divisor = 2;
	while (divisor <= number / divisor)
	{
		if (number % divisor == 0)
			return (0);
		divisor++;
	}
	return (1);
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
	int	sum;
	int	i;

	sum = 0;
	if (argc == 2)
	{
		number = get_number(argv[1]);
		i = 2;
		while (i <= number)
		{
			if (is_prime(i))
				sum += i;
			i++;
		}
	}
	put_number(sum);
	write(1, "\n", 1);
	return (0);
}
