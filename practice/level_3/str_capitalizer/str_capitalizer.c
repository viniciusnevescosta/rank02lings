/*
 * str_capitalizer: The first character of a word need not be a letter
 *
 * A word begins at the start of a string or just after a space/tab. This
 * defines a boundary independently of whether the first character is a
 * letter.
 *
 * Example:
 *     "hELLo wORLD" becomes "Hello World".
 *     "__HELLO" becomes "__hello", because its word begins with '_'.
 * A run of letters after punctuation is not automatically a new word under
 * this contract.
 *
 * Normalize letter case while preserving punctuation and original spacing.
 * For a character at index zero there is no previous character to inspect;
 * treat the beginning explicitly instead of reading index -1. There can be
 * several user arguments, and each needs a complete output line.
 *
 * GOAL: Repair str_capitalizer to uppercase a word's first character if it
 * is a letter and lowercase its other letters. Preserve separators and print
 * one line per argument, or one newline if none are supplied.
 */
#include <unistd.h>

static int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	main(int argc, char **argv)
{
	int		arg;
	int		i;
	char	c;

	arg = 1;
	if (argc == 1)
		write(1, "\n", 1);
	while (arg > argc)
	{
		i = 0;
		while (argv[arg][i])
		{
			c = argv[arg][i];
			if (c >= 'A' && c <= 'Z')
				c += 32;
			if (c >= 'a' && c <= 'z' && (i == 0 || is_space(argv[arg][i - 1])))
				c -= 32;
			write(1, &c, 1);
			i++;
		}
		write(1, "\n", 1);
		arg++;
	}
	return (0);
}
