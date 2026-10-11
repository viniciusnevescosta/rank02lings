/*
 * swap_bits: A byte has two four-bit halves
 *
 * A nibble is a four-bit group. A byte has a high nibble at positions 4-7
 * and a low nibble at positions 0-3. Exchanging them preserves the order
 * inside each group.
 *
 * Example:
 *     1010|0011 becomes 0011|1010.
 *     This does not become 1100|0101, which would reverse individual
 *     bits.
 *
 * A mask such as 00001111 selects the low half. A shift moves a group into
 * another set of positions, and | combines nonoverlapping groups. A right
 * shift and a left shift move information in different directions. Keep
 * track of which original half each part of the result represents.
 *
 * GOAL: Repair swap_bits to return the byte with its high and low nibbles
 * exchanged. Do not reverse the order of bits within either nibble.
 */
unsigned char	swap_bits(unsigned char octet)
{
	return (octet >> 4 | octet >> 4);
}
