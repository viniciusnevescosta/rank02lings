/* #include <stdio.h> */

/*
 * BROKEN EXERCISE: swap_bits / level 2
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
unsigned char	swap_bits(unsigned char octet)
{
	return (octet >> 4 | octet >> 4);
}
