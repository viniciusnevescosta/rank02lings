/*
 * ft_putstr: Byte output has no automatic string behavior
 *
 * write takes a file descriptor, an address, and a byte count. Descriptor 1
 * is standard output. It does not inspect '\0' to decide a string's length
 * and does not add a newline.
 *
 * Example:
 *     char message[] = "cat";
 *     write(1, &message[1], 1);  // writes only 'a'
 *     write(1, message, 2);      // writes "ca"
 * The address selects where reading begins; the count selects how much to
 * write.
 *
 * A C string's terminator identifies where the text ends, but normally
 * should not be sent as an output byte. The empty string contains no text
 * bytes. Consider which information your loop inspects and which position
 * changes after an output operation.
 *
 * GOAL: Repair ft_putstr to write every text character of str to stdout,
 * without the terminator or an added newline. Use only write; the tester
 * provides main().
 */
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
