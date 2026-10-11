/*
 * rotone: The boundary case of a one-step rotation
 *
 * Most letters have a following letter within their ASCII interval. The
 * final letter is special because its successor must wrap to the beginning
 * of that interval, not to the following ASCII punctuation byte.
 *
 * Example:
 *     A short circular sequence a, b, c has c followed by a.
 *     Ordinary numeric addition would instead leave the sequence.
 *
 * Treat uppercase and lowercase as separate circular sequences. A nonletter
 * should pass through unchanged. When a transformation uses several
 * conditions, make sure that a byte changed by one branch is not transformed
 * again by a later independent branch in the same iteration.
 *
 * GOAL: Repair rotone to replace each ASCII letter with its next alphabet
 * letter, wrapping z to a and Z to A. Keep other bytes unchanged and follow
 * the subject's newline and argument rules.
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
			if (c == 'z' || c == 'Z')
				c -= 25;
			else if ((c >= 'a' && c <= 'y') || (c >= 'A' && c <= 'Y'))
				c++;
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
