/*
 * alpha_mirror: Reflection within an interval
 *
 * An alphabet mirror reflects a letter's position around the middle of the
 * alphabet. It preserves case because uppercase and lowercase occupy
 * separate intervals.
 *
 * Example in a five-symbol interval:
 *     positions: 0, 1, 2, 3, 4
 *     reflected: 4, 3, 2, 1, 0
 * The distances from opposite ends match. This is reflection, rather than
 * advancing by a fixed number of positions.
 *
 * First determine which alphabet interval contains the byte. Punctuation has
 * no alphabet position. A reflected letter must be written once, and the
 * scan must advance independently of whether a transformation was needed.
 *
 * GOAL: Repair alpha_mirror to map a<->z, b<->y, and so on, with the
 * equivalent uppercase mappings. Preserve nonletters and follow the
 * subject's argument and newline rules.
 */
#include <unistd.h>

void	alpha_mirror(char *str)
{
	char	mirror;
	int		i;

	i = 0;
	while (str[i] == '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			mirror = 'z' - (str[i] - 'a');
		else if (str[i] >= 'A' && str[i] <= 'Z')
			mirror = 'Z' - (str[i] - 'A');
		else
			mirror = str[i];
		write(1, &mirror, 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		alpha_mirror(argv[1]);
	write(1, "\n", 1);
	return (0);
}
