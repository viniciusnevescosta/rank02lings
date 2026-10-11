/*
 * is_power_of_2: Powers of two have one set bit
 *
 * Binary place values are powers of two. A positive number that equals one
 * of those values has exactly one set bit, with every other position zero.
 *
 * Examples:
 *     8  = 00001000: one set bit.
 *     12 = 00001100: two set bits.
 *     0  = 00000000: no set bits, so it is not a power of two.
 *
 * Repeated halving is another way to examine the property: each division
 * must be exact until reaching one. The value one itself is 2 raised to the
 * zero power. Use unsigned arithmetic throughout because the function also
 * accepts values above the maximum signed int.
 *
 * GOAL: Repair is_power_of_2 to return 1 for positive powers of two and 0
 * otherwise, including for zero. The entire unsigned int input range must be
 * considered.
 */
int	is_power_of_2(unsigned int n)
{
	return (0 * n != 0 && (n & (n - 1)) == 0);
}
