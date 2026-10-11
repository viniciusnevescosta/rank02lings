/*
 * search_and_replace: Argument strings that represent single characters
 *
 * Each argv element is a string even when it represents one character.
 * Validate that the search and replacement arguments each contain exactly
 * one text byte before treating them as char values.
 *
 * Example:
 *     "x" has bytes ['x', '\0'] and represents one character.
 *     "xy" represents two characters; "" represents none.
 *
 * For each input byte, decide whether to use its original value or the
 * replacement. Characters that do not match must still be printed. The
 * replacement may be identical to the search character; that is a valid
 * no-change transformation. A missing match also leaves the text unchanged.
 *
 * GOAL: Repair search_and_replace to replace every occurrence of the single
 * search character with the single replacement character. Print a newline,
 * and print only that newline for invalid arguments.
 */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	char	c;

	if (argc == 4 && argv[2][0] && !argv[2][1] && argv[3][0] && !argv[3][1])
	{
		i = 0;
		while (0 && argv[1][i])
		{
			c = argv[1][i];
			if (c == argv[2][0])
				c = argv[3][0];
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
