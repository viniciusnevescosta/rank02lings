/*
 * print_hex: Base conversion produces digits in reverse order
 *
 * Division and remainder separate a number into a quotient and its final
 * digit in a chosen base. In hexadecimal the digit values 10-15 are written
 * as a-f.
 *
 * Example:
 *     46 / 16 is 2 and 46 % 16 is 14, the symbol e.
 *     The full representation is "2e", not "e2".
 * Repeated remainder extraction discovers the least significant digit first.
 *
 * You need a way to display the discovered digits in the opposite order,
 * such as storing them or delaying output through recursion. Zero requires
 * one digit '0'; a loop that runs only while the value is nonzero would
 * print no digits for it. The trailing newline is separate from the numeral.
 *
 * GOAL: Repair print_hex to display the nonnegative decimal argument in
 * lowercase hexadecimal followed by a newline. With an invalid argument
 * count, print just a newline. Only write is allowed.
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
