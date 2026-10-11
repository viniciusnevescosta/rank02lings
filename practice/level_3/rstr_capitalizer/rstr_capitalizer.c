/*
 * rstr_capitalizer: A word end is a boundary, not every letter
 *
 * Words in this subject are delimited by spaces or tabs. Punctuation inside
 * a word remains part of it. Lowercasing text and selecting the character at
 * a word boundary are separate operations.
 *
 * Example:
 *     "hELLo wORLD" becomes "hellO worlD".
 *     A one-letter word "a" becomes "A".
 * The final character can be recognized because the next position is a
 * separator or '\0'. Check that final character is a letter before
 * uppercasing it.
 *
 * A look-ahead is safe only while the current position is a text byte.
 * Process every user argument, each with its own newline. Preserve the
 * spacing already present rather than normalizing it. The no-argument case
 * still needs one newline.
 *
 * GOAL: Repair rstr_capitalizer to lowercase letters and uppercase the final
 * character of each word when it is a letter. Preserve other bytes and
 * process all arguments as described in SUBJECT.md.
 */
#include <unistd.h>

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\0');
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
			if (c >= 'a' && c <= 'z' && is_space(argv[arg][i + 1]))
				c -= 32;
			write(1, &c, 1);
			i++;
		}
		write(1, "\n", 1);
		arg++;
	}
	return (0);
}
