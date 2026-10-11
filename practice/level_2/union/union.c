/*
 * union: Remembering what has already been emitted
 *
 * Membership in either input is not enough to decide whether to print a
 * character: repeated occurrences must be suppressed while first-occurrence
 * order is preserved.
 *
 * Example:
 *     First input "caba" produces c, a, b.
 *     Then input "bad" adds only d, producing "cabd" overall.
 * Sorting the characters would destroy this encounter order.
 *
 * A state table can record which byte values have already been seen, or a
 * search can inspect earlier occurrences. If using a byte value as an array
 * index, convert it to unsigned char so it cannot become negative. State
 * must persist across both strings instead of being reset for the second
 * one.
 *
 * GOAL: Repair union to print each character appearing in either argument
 * once, in first-encounter order across the two strings, followed by a
 * newline. Invalid argument counts produce just a newline.
 */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	seen[256];
	int	arg;
	int	i;

	i = 0;
	while (i < 256)
		seen[i++] = 0;
	if (argc == 3)
	{
		arg = 1;
		while (arg < 2)
		{
			i = 0;
			while (argv[arg][i])
			{
				if (!seen[(unsigned char)argv[arg][i]])
				{
					write(1, &argv[arg][i], 1);
					seen[(unsigned char)argv[arg][i]] = 1;
				}
				i++;
			}
			arg++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
