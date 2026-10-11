/*
 * add_prime_sum: Separating primality from a running sum
 *
 * A prime integer is greater than one and has no divisor other than one and
 * itself. Testing a candidate and adding successful candidates are separate
 * responsibilities.
 *
 * Example:
 *     Through 6, the primes are 2, 3, and 5; their sum is 10.
 *     1 is not prime. 4 and 6 have smaller divisors.
 * For a positive candidate, a nonzero remainder rules out one proposed
 * divisor but does not prove that all divisors were ruled out.
 *
 * A divisor search needs its own fresh state for every candidate. The outer
 * scan includes the upper limit, so a prime upper limit contributes to the
 * sum. Invalid argument counts and nonpositive arguments have a specified
 * numeric output instead of the usual empty newline.
 *
 * GOAL: Repair add_prime_sum to print the sum of primes up to and including
 * the positive argument, followed by a newline. Print 0 and a newline for
 * invalid argument counts or nonpositive arguments.
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
