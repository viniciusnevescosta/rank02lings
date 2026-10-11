/*
 * camel_to_snake: One input byte can produce two output bytes
 *
 * A naming conversion does not necessarily preserve string length. An
 * uppercase letter in lowerCamelCase marks the start of another word; its
 * snake_case representation adds a separator and changes case.
 *
 * Example:
 *     "smallBox" becomes "small_box".
 *     The input B corresponds to the output pair '_' and 'b'.
 * The input position still advances by one even when two bytes are emitted.
 *
 * If writing directly, output expansion does not require an allocated
 * buffer. If building a result string instead, reserve enough space for
 * inserted characters and the terminator. The contract supplies
 * lowerCamelCase input, so focus on that format rather than inventing rules
 * for unrelated naming styles.
 *
 * GOAL: Repair camel_to_snake to convert the single lowerCamelCase argument
 * to snake_case and append a newline. Preserve the order of all words and
 * follow SUBJECT.md for argument handling.
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
			c = argv[1][i];
			if (c >= 'A' && c <= 'Z')
			{
				write(1, "_", 1);
				c += 32;
			}
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
