/*
 * c11_bit: Bit positions, shifts, and masks
 *
 * A byte has eight binary positions. Position zero is the least significant
 * bit, worth 1; position seven is worth 128. A right shift moves bits toward
 * position zero, and & compares positions against a mask.
 *
 * Example:
 *     10 in binary is 00001010.
 *     Its bits at positions 3 and 1 are set.
 *     A mask 00000001 keeps only the least significant position.
 *
 * A shifted number can still contain several set bits. Testing whether that
 * whole number is nonzero does not isolate a particular position. A mask
 * selects the information you need. pos is restricted to 0 through 7, so
 * there is no need to define out-of-range shifts here.
 *
 * GOAL: Make bit return exactly 0 or 1 for the bit at pos in n. Examples:
 * (10, 3) -> 1; (10, 2) -> 0; (10, 1) -> 1.
 */
#include <stdlib.h>
#include <string.h>

int	bit(unsigned char n, int pos)
{
	(void)n;
	(void)pos;
	return (0);
}
