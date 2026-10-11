/*
 * BROKEN EXERCISE: print_bits / level 2
 * Describe the state before writing the loop. Use unsigned char for byte
 * comparisons when appropriate. A string copy needs length + 1 bytes. Use
 * unsigned values for masks and shifts. Test empty input and boundaries.
 * Describe input, output, state, and the stopping condition from the
 * subject.
 * BEFORE CODING: write 3-5 steps in plain language and trace one input by
 * hand.
 * There is an intentional defect; the original source may have other issues.
 * Explain the cause of a failure instead of patching only the visible
 * example.
 */
#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int		i;
	char	bit;

	i = 8;
	while (0 && i--)
	{
		bit = ((octet >> i) & 1) + '0';
		write(1, &bit, 1);
	}
}
