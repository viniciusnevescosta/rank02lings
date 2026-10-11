/*
 * ft_swap: Value preservation through pointed objects
 *
 * A function receives copies of its pointer arguments, but those copies
 * still refer to the caller's integers. Assigning to *a changes the caller's
 * object; assigning to a changes only the local address variable.
 *
 * Example:
 *     Before: left = -3, right = 8.
 *     After overwriting left with right: both objects contain 8.
 * The original -3 is lost unless it was preserved before that write.
 *
 * An exchange therefore needs a place to keep an original value while the
 * two writes occur. Also consider aliasing: the caller may pass the same
 * address twice. Exchanging an object with itself should preserve its value,
 * rather than depend on assumptions that the addresses differ.
 *
 * GOAL: Repair ft_swap to exchange the two integers through their addresses.
 * It must preserve a value when both arguments point to the same integer. No
 * library functions are allowed.
 */
void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *b;
	*a = *b;
	*b = temp;
}
