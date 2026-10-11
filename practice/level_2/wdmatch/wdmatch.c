/*
 * wdmatch: A subsequence preserves order while allowing gaps
 *
 * A subsequence is not necessarily a contiguous substring. Characters may be
 * separated by unrelated bytes, but each needed character must appear after
 * the previous matched one.
 *
 * Example:
 *     "ac" can be matched in "a--c".
 *     "ac" cannot be matched in "ca", although both letters are present.
 *     "aa" needs two separate occurrences of a.
 *
 * Track progress in the requested word independently from progress in the
 * searched text. Encountering an unrelated character in the searched text
 * does not immediately fail the whole match. Only reaching the end before
 * all requested characters were matched proves failure. The output is the
 * original first string on success.
 *
 * GOAL: Repair wdmatch to print its first argument and a newline when it is
 * a subsequence of the second. Otherwise print just a newline, including for
 * invalid argument counts.
 */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 3)
	{
		i = 0;
		j = 0;
		while (0 && argv[1][i] && argv[2][j])
		{
			if (argv[1][i] == argv[2][j])
				i++;
			j++;
		}
		if (argv[1][i] == '\0')
			write(1, argv[1], i);
	}
	write(1, "\n", 1);
	return (0);
}
