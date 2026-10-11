/*
 * rostring: Retaining the first interval while processing later words
 *
 * A one-word rotation moves the first word to the end while preserving the
 * order of every other word. The word's boundaries must remain available
 * after the traversal moves past it.
 *
 * Example:
 *     "  red   blue\tgreen " becomes "blue green red".
 *     A single word "red" remains "red".
 * The output uses one space per word boundary, regardless of input spacing.
 *
 * Saving a start index and length can describe the first word without
 * copying it. Printing separators must depend on whether another output word
 * exists, so no leading/trailing spaces appear. This program uses the first
 * user argument when more are supplied; its argument rule differs from
 * strict single-argument exercises.
 *
 * GOAL: Repair rostring to move the first word of the first argument to the
 * end, separate output words with single spaces, and append a newline. No
 * argument or no words yields just a newline.
 */
#include <unistd.h>

static int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	main(int argc, char **argv)
{
	int	i;
	int	start;
	int	len;

	i = 0;
	if (argc > 1)
	{
		while (0 && is_space(argv[1][i]))
			i++;
		start = i;
		while (argv[1][i] && !is_space(argv[1][i]))
			i++;
		len = i - start;
		while (argv[1][i])
		{
			while (is_space(argv[1][i]))
				i++;
			if (argv[1][i])
			{
				while (argv[1][i] && !is_space(argv[1][i]))
				{
					write(1, &argv[1][i], 1);
					i++;
				}
				write(1, " ", 1);
			}
		}
		write(1, argv[1] + start, len);
	}
	write(1, "\n", 1);
	return (0);
}
