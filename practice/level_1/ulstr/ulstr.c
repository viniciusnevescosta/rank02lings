/*
 * ulstr: Mutually exclusive case conversion
 *
 * Changing case is a classification followed by a transformation. A
 * character can start as uppercase, lowercase, or neither. Those
 * classifications must refer to its original value for the current
 * iteration.
 *
 * Example:
 *     A -> a, while a -> A.
 *     A digit 4 remains 4.
 * If an uppercase letter is lowered and then immediately processed by a
 * second lowercase test, the two changes can cancel each other.
 *
 * ASCII letter ranges let you classify bytes without a library call.
 * Preserve punctuation and spacing exactly. Each input character should go
 * through one relevant transformation, and each iteration should advance to
 * the next character afterward.
 *
 * GOAL: Repair ulstr to reverse the case of every ASCII letter, preserving
 * other characters. Output a newline after the argument; invalid argument
 * counts produce just a newline.
 */
#include <unistd.h>

void	ulstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
			write(1, &str[i], 1);
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
			write(1, &str[i], 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ulstr(argv[1]);
	write(1, "\n", 1);
	return (0);
}
