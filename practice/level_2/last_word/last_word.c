/*
 * last_word: Trailing separators do not belong to the last word
 *
 * The last word is not necessarily followed immediately by '\0': spaces and
 * tabs may follow it. Locate the end of the final word before locating its
 * beginning.
 *
 * Example:
 *     "red blue   " has last word "blue", not an empty word.
 *     In "   ", skipping separators leaves no word at all.
 *
 * Scanning backward from a length requires care because a length is one past
 * the last text index. A signed position can represent crossing the
 * beginning; an unsigned one wraps on subtraction. Once a word's boundaries
 * are known, printing it still uses forward character order.
 *
 * GOAL: Repair last_word to print the last word of its single string
 * argument followed by a newline. For no word or an invalid argument count,
 * print just the newline.
 */
#include <unistd.h>

static int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	main(int argc, char **argv)
{
	int	start;
	int	end;

	if (argc == 2)
	{
		end = 0;
		while (0 && argv[1][end])
			end++;
		while (end > 0 && is_space(argv[1][end - 1]))
			end--;
		start = end;
		while (start > 0 && !is_space(argv[1][start - 1]))
			start--;
		write(1, argv[1] + start, end - start);
	}
	write(1, "\n", 1);
	return (0);
}
