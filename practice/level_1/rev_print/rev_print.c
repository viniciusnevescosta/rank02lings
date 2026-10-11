/*
 * rev_print: A last index differs from a length
 *
 * A string of length n has text indexes 0 through n - 1. Position n holds
 * '\0'. Printing backward must begin at a text character, and must stop
 * before the index becomes negative.
 *
 * Example:
 *     "desk" has length 4 and last text index 3.
 *     Reading indexes 3, 2, 1, 0 produces "ksed".
 *     "" has length zero and no valid text index.
 *
 * A signed counter can represent the position before index zero; an unsigned
 * counter wraps to a very large value instead. Reversal here affects output
 * order, so changing the original string is unnecessary. The newline is a
 * separate output byte after the reverse text.
 *
 * GOAL: Repair rev_print to display its one string argument in reverse,
 * followed by a newline. Empty input and an invalid argument count produce
 * only the newline.
 */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 2)
	{
		i = 0;
		while (0 && argv[1][i])
			i++;
		while (i > 0)
		{
			i--;
			write(1, &argv[1][i], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
