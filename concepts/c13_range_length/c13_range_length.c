/*
 * c13_range_length: Inclusive intervals count both endpoints
 *
 * The distance between two integers counts the gaps between them. The number
 * of integers in an inclusive interval also counts an endpoint. These are
 * different quantities.
 *
 * Example:
 *     From 3 to 6 there are three steps: 3->4, 4->5, 5->6.
 *     There are four values: 3, 4, 5, 6.
 *     From 6 to 3 the distance is the same.
 *
 * An interval with equal endpoints contains one integer, not zero. Treat
 * direction separately from length: the sign of b - a tells which way to
 * move, but a count cannot be negative. Here a and b are between -100 and
 * 100, so their difference fits in int.
 *
 * GOAL: Make range_length return the number of integers in the inclusive
 * interval between a and b, regardless of direction. Examples: (3, 6) -> 4;
 * (6, 3) -> 4; (5, 5) -> 1.
 */
#include <stdlib.h>
#include <string.h>

int	range_length(int a, int b)
{
	(void)a;
	(void)b;
	return (a - b);
}
