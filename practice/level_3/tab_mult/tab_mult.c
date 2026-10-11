/*
 * tab_mult: Numeric calculation and a fixed textual layout
 *
 * A multiplication table combines an increasing multiplier, a fixed input
 * number, and the product. Their numeric values must be converted to text;
 * the spaces and symbols in each line are literal output bytes.
 *
 * Example for the number 4:
 *     1 x 4 = 4
 *     2 x 4 = 8
 *     ...
 *     9 x 4 = 36
 * The multiplier changes between lines, while the input number stays the
 * same.
 *
 * Read the decimal argument before beginning the table. Keep the repetition
 * counter independent of any counter used to print a multi-digit integer.
 * Boundaries matter: the requested table starts at 1 and ends at 9, with a
 * newline after every line.
 *
 * GOAL: Repair tab_mult to print the nine multiplication-table lines for its
 * positive integer argument using the subject's exact spacing. Follow
 * SUBJECT.md for missing arguments and allowed functions.
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
