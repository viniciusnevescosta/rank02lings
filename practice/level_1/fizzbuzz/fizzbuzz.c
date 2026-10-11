/*
 * fizzbuzz: Overlapping conditions and decimal output
 *
 * The remainder operator % can test divisibility: 12 % 3 is zero, while 13 %
 * 3 is one. Some numbers satisfy more than one rule, so the order and
 * exclusivity of your decisions matter.
 *
 * Example:
 *     6 belongs to the multiples of 3.
 *     10 belongs to the multiples of 5.
 *     30 belongs to both groups and needs one combined output line.
 *
 * An integer such as 42 is not a printable two-character string. Writing its
 * memory would output representation bytes. Decimal output instead needs the
 * characters '4' and '2'. Keep choosing the output separate from advancing
 * to the next number; every iteration must advance, regardless of which rule
 * matched.
 *
 * GOAL: Repair fizzbuzz to print 1 through 100, one line per number,
 * replacing multiples of 3, 5, or both with fizz, buzz, or fizzbuzz
 * respectively. Only write is allowed.
 */
#include <unistd.h>

void	put_num(int n)
{
	char	*decimal;

	decimal = "0123456789";
	if (n > 9)
		put_num(n / 10);
	write(1, &decimal[n % 10], 1);
}

void	fizzbuzz(int len)
{
	int	i;

	i = 1;
	while (i > len)
	{
		if (i % 15 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else
			put_num(i);
		i++;
		write(1, "\n", 1);
	}
}

int	main(void)
{
	fizzbuzz(101);
	return (0);
}
