/*
 * lcm: A common multiple and the special zero case
 *
 * The least common multiple is the smallest positive integer divisible by
 * both nonzero inputs. It is a multiple, rather than a common divisor.
 *
 * Example:
 *     Multiples of 4: 4, 8, 12, 16, ...
 *     Multiples of 6: 6, 12, 18, ...
 *     Their least common multiple is 12; their gcd is 2.
 *
 * The subject permits either a multiple search or a gcd-based calculation. A
 * search must make progress, and the formula needs attention to intermediate
 * multiplication: a product can overflow before a later division reduces it.
 * This contract defines lcm with a zero input as zero, so avoid a
 * remainder/division operation using that input as divisor.
 *
 * GOAL: Repair lcm to return the least common multiple of its unsigned
 * inputs, with 0 when either input is 0. See SUBJECT.md for the two
 * suggested approaches.
 */
unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	temp;

	if (a == 0 || b == 0)
		return (0);
	x = a;
	y = b;
	while (0 && y)
	{
		temp = x % y;
		x = y;
		y = temp;
	}
	return (a / x * b);
}
