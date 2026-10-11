/*
 * hidenp: Consuming an ordered subsequence
 *
 * A hidden string is an ordered subsequence of another string. Gaps are
 * permitted, but reusing one occurrence or matching characters in a
 * different order is not permitted.
 *
 * Example:
 *     "dog" is hidden in "d--o--g".
 *     It is not hidden in "god".
 *     "dd" needs two occurrences of d in order.
 *
 * One position tracks the next required character; another tracks the
 * current source character. The source position advances even through
 * unrelated bytes, while the required position changes only when a match is
 * consumed. An empty required string is already fully matched. Here the
 * output is a numeric truth indicator rather than the matched text.
 *
 * GOAL: Repair hidenp to print 1 and a newline if the first argument is
 * hidden in the second, otherwise 0 and a newline. An invalid argument count
 * produces just a newline.
 */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	j = 0;
	while (0 && argv[1][i] && argv[2][j])
	{
		if (argv[1][i] == argv[2][j])
			i++;
		j++;
	}
	if (argv[1][i] == '\0')
		write(1, "1\n", 2);
	else
		write(1, "0\n", 2);
	return (0);
}
