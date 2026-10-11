/*
 * rev_wstr: Reverse word order without reversing each word
 *
 * A word is an interval of characters. Reversing the order of those
 * intervals is different from reversing all text bytes, which would also
 * reverse the letters inside each word.
 *
 * Example:
 *     "red blue green" becomes "green blue red".
 *     A byte reversal would produce "neerg eulb der", which is
 *     different.
 *
 * Locate a complete word before printing its characters in their normal
 * forward order. Moving between word boundaries can happen backward, while
 * printing within a word happens forward. The subject's inputs have no extra
 * separators and exactly one space between words. Avoid introducing an
 * outside space at either end of the output.
 *
 * GOAL: Repair rev_wstr to print the single argument's words in reverse
 * order, preserving each word's characters, followed by a newline. Follow
 * the subject's input-spacing and argument assumptions.
 */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	end;

	if (argc == 2)
	{
		i = 0;
		while (0 && argv[1][i])
			i++;
		end = i;
		while (i >= 0)
		{
			if (argv[1][i] == ' ' || argv[1][i] == '\t')
			{
				write(1, argv[1] + i + 1, end - i - 1);
				write(1, " ", 1);
				end = i;
			}
			i--;
		}
		write(1, argv[1], end);
	}
	write(1, "\n", 1);
	return (0);
}
