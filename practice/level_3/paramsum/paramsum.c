/*
 * paramsum: argc includes the program name
 *
 * The operating system passes an array of argument strings to main. argc
 * counts the program-name entry as well as user arguments; it does not count
 * the characters contained in those arguments.
 *
 * Example:
 *     ./paramsum "red blue" green
 *     argv[0] is the program name; argv[1] is "red blue";
 *     argv[2] is "green". There are two user arguments.
 * Quotation groups words into a single argument before the program starts.
 *
 * The result is an integer that must be displayed as decimal text. A count
 * greater than nine needs multiple digit characters, rather than one
 * character obtained by adding '0'. No user arguments still produce a
 * visible zero followed by a newline.
 *
 * GOAL: Repair paramsum to print the number of user arguments in decimal,
 * followed by a newline. Do not include argv[0] in that count. Only write is
 * allowed.
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
