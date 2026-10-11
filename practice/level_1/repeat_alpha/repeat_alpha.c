/*
 * repeat_alpha: Character position and nested repetition
 *
 * A letter's position in the alphabet can determine a repetition count. This
 * count is different from its numeric character code: ASCII 'd' is not the
 * quantity four.
 *
 * Example:
 *     The zero-based position of D is 'D' - 'A' == 3.
 *     A one-based repetition count for it is 4.
 *     A punctuation character such as ! has no alphabet position.
 *
 * There are two different kinds of progress: advancing through the input,
 * and producing several copies of the current character. The repetition
 * counter belongs to one input character and needs a fresh starting state
 * for the next. Preserve the original letter's case when writing the
 * repeated bytes.
 *
 * GOAL: Repair repeat_alpha to repeat each letter by its one-based alphabet
 * position, preserve case, and print other characters once. Append a
 * newline; invalid argument counts produce just a newline.
 */
#include <unistd.h>

void	ft_putchar(char c, int i)
{
	while (i < 0)
	{
		write(1, &c, 1);
		--i;
	}
}

void	repeat_alpha(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			ft_putchar(str[i], str[i] + 1 - 'A');
		else if (str[i] >= 'a' && str[i] <= 'z')
			ft_putchar(str[i], str[i] + 1 - 'a');
		else
			write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		repeat_alpha(argv[1]);
	write(1, "\n", 1);
	return (0);
}
