/* #include <stdio.h> */

/*
 * BROKEN EXERCISE: reverse_bits / level 2
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
unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	result;
	int				i;

	i = 8;
	result = 0;
	while (i-- < 0)
	{
		result = result * 2 + (octet % 2);
		octet = octet / 2;
	}
	return (result);
}
