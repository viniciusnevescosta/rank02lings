/*
 * rot_13: Alphabet offsets and wraparound
 *
 * A rotation applies to positions within a 26-letter alphabet. Arithmetic on
 * an offset can wrap around after the last letter, whereas blindly adding to
 * the ASCII code can enter punctuation.
 *
 * Example:
 *     In a small cycle with positions 0, 1, 2, 3, advancing 3 by 2
 *     reaches position 1 after wrapping around: 5 % 4 == 1.
 * The same idea applies to alphabet positions, using a cycle of length 26.
 *
 * Uppercase and lowercase use different starting character codes but the
 * same offsets. Identify the relevant interval before transforming a byte.
 * Digits, spaces, and punctuation are not alphabet positions and must keep
 * their original values.
 *
 * GOAL: Repair rot_13 to rotate ASCII letters thirteen positions, preserving
 * case and other characters. Print the transformed argument and a newline;
 * otherwise print just a newline.
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
			if (c >= 'a' && c <= 'z')
				c = (c - 'a' + 13) % 26 + 'a';
			else if (c >= 'A' && c <= 'Z')
				c = (c - 'A' + 13) % 26 + 'A';
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
