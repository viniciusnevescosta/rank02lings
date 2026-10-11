/*
 * reverse_bits: Bit position reversal changes place value
 *
 * Reversing bits maps each of the eight input positions to the opposite
 * output position. This is different from reversing decimal digits or
 * swapping just two groups of bits.
 *
 * Example:
 *     Input 00000110 becomes 01100000.
 *     The input bits at positions 1 and 2 move to positions 6 and 5.
 * The returned value is a byte, not a printed string of binary characters.
 *
 * An output accumulator represents the bits placed so far and must start
 * with known contents. A counter controls how many positions have been
 * processed; zero bits still count as positions. Exactly eight positions
 * exist regardless of the input's numeric magnitude.
 *
 * GOAL: Repair reverse_bits to return the byte obtained by reversing all
 * eight bits. Examples: 00000001 -> 10000000; 00000000 -> 00000000.
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
