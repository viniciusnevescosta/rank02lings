/*
 * c19_digit_count: Division removes digits without negating the number
 *
 * Integer division by 10 removes the last decimal digit. For signed integers
 * in C99, division truncates toward zero, so both positive and negative
 * values move closer to zero.
 *
 * Example:
 *     507 / 10 is 50; 50 / 10 is 5; 5 / 10 is 0.
 *     -507 / 10 is -50, then -5, then 0.
 * The minus sign is not a digit.
 *
 * Zero has the decimal representation "0", which contains one digit even
 * though division cannot shrink it. INT_MIN also needs attention: its
 * positive counterpart may not fit in int, so simply negating every negative
 * input can overflow. Counting divisions does not require forming that
 * positive counterpart.
 *
 * GOAL: Make digit_count return the number of decimal digits in n, excluding
 * its sign. Examples: 0 -> 1; -507 -> 3. The full int range, including
 * INT_MIN, must work.
 */
#include <stdlib.h>
#include <string.h>

int	digit_count(int n)
{
	(void)n;
	return (0);
}
