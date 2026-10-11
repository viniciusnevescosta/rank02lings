/*
 * epur_str: Printing separators between words rather than at the ends
 *
 * Input spacing and output spacing are different things. Runs of spaces or
 * tabs delimit words, but the output must contain a separator only between
 * two actual words.
 *
 * Example:
 *     "  red\t\tblue   " becomes "red blue".
 *     "   " contains no words and contributes no output space.
 * Writing a space as soon as an input separator appears can create an
 * unwanted leading or trailing space.
 *
 * A small state value can describe whether a previous word was printed or
 * whether another separator is pending. Keep whitespace scanning separate
 * from writing word characters. The output separator is an ordinary space
 * even when the input used tabs, and the newline comes after the complete
 * normalized text.
 *
 * GOAL: Repair epur_str to print words in order with exactly one space
 * between them and no leading/trailing separators. Append a newline; no
 * words or an invalid argument count yield just the newline.
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
				write(1, " ", 1);
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
