/*
 * c17_gcd: Remainders preserve common divisors
 *
 * The greatest common divisor is the largest positive integer that divides
 * both inputs exactly. Replacing a pair with the smaller divisor problem
 * keeps the same common divisors.
 *
 * Trace for the pair (20, 12):
 *     20 % 12 = 8  -> consider (12, 8)
 *     12 % 8  = 4  -> consider (8, 4)
 *     8 % 4   = 0  -> the greatest common divisor is 4
 *
 * The remainder becomes smaller than the divisor, which gives the process
 * progress toward termination. A remainder expression must never use a zero
 * divisor. Updating the pair also requires preserving an old value long
 * enough to compute the next one.
 *
 * GOAL: Make gcd return the greatest common divisor of two unsigned integers
 * using the remainder-based process. Examples: (20, 12) -> 4; (0, 7) -> 7;
 * (0, 0) -> 0.
 */

unsigned int	gcd(unsigned int a, unsigned int b)
{
	unsigned int swap;

	while (b != 0)
	{
		swap = a % b;
		a = b;
		b = swap;
	}
	return (a);
}
