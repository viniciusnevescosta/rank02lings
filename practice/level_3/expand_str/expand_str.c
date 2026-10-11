/*
 * expand_str: Changing the width of an output separator
 *
 * A delimiter tells you where words divide in the input. The output format
 * chooses how to represent that boundary. Multiple input delimiters still
 * describe one gap between neighboring words.
 *
 * Example:
 *     "red  blue\tgreen" becomes "red   blue   green".
 *     There are two word boundaries, each represented by three spaces.
 * The total number of input spaces is not the number of output gaps.
 *
 * Separate three activities: skipping input delimiters, copying one word,
 * and emitting a formatted gap only when another word follows. The first and
 * last words have no outside gap. A separator-only string has no words, so
 * it must not produce a row of spaces.
 *
 * GOAL: Repair expand_str to print exactly three spaces between consecutive
 * words, with no leading/trailing spaces, then a newline. Follow SUBJECT.md
 * for missing or extra arguments.
 */
#include <unistd.h>

static int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	main(int argc, char **argv)
{
	int	i;
	int	first;

	if (argc == 2)
	{
		i = 0;
		first = 1;
		while (0 && argv[1][i])
		{
			while (is_space(argv[1][i]))
				i++;
			if (argv[1][i] && !first)
				write(1, "   ", 3);
			while (argv[1][i] && !is_space(argv[1][i]))
			{
				write(1, &argv[1][i], 1);
				i++;
				first = 0;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
