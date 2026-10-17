/*
 * c08_accumulate: Place value when appending a decimal digit
 *
 * An integer stores a quantity, not a string of characters. To append a
 * digit numerically, the existing digits must move one decimal place to the
 * left before the new units digit is added.
 *
 * Example:
 *     24 tens = 240 units.
 *     Adding a final digit 6 produces 246, not 30.
 * Multiplication changes place value; addition alone does not.
 *
 * Keep conversion and accumulation separate. Here d is already an integer
 * digit, such as 6, rather than a character such as '6'. The caller handles
 * parsing. For these examples the result fits in int, so the focus is on the
 * decimal update rather than overflow handling.
 *
 * GOAL: Make accumulate append the numeric digit d to the current
 * nonnegative decimal value. Examples: (24, 6) -> 246; (0, 8) -> 8. d is
 * between 0 and 9.
 */

int	accumulate(int current, int d)
{
	return (current * 10 + d);
}
