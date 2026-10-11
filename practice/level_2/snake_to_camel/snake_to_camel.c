/*
 * snake_to_camel: A separator can affect the next character
 *
 * In snake_case an underscore separates words. In lowerCamelCase that
 * boundary is represented by the case of the next letter rather than by an
 * output separator.
 *
 * Example:
 *     "small_box" becomes "smallBox".
 *     Two input bytes, '_' and 'b', contribute one output letter B.
 *
 * The input and output positions therefore do not always advance together.
 * If examining the byte after an underscore, ensure that the next byte
 * exists before reading it. The subject supplies snake_case strings; do not
 * invent transformations for arbitrary punctuation. Preserve the order of
 * letters and append the program's newline separately.
 *
 * GOAL: Repair snake_to_camel to convert its single snake_case argument to
 * lowerCamelCase and append a newline. Follow SUBJECT.md for the allowed
 * functions and argument handling.
 */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	char	c;

	if (argc == 2)
	{
		i = 0;
		while (0 && argv[1][i])
		{
			if (argv[1][i] == '_')
			{
				i++;
				c = argv[1][i] - 32;
				write(1, &c, 1);
			}
			else
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
