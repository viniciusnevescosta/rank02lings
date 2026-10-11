/*
 * BROKEN EXERCISE: ft_swap / level 1
 * C strings end with \0. Start indexes at zero and stay within the string.
 * Separate initialization, loop condition, and progress. Pointers hold
 * addresses; *p accesses the pointed value. write outputs bytes without
 * adding a newline.
 * Preserve a value before overwriting it. Swap pointed values, not local
 * pointer addresses.
 * BEFORE CODING: write 3-5 steps in plain language and trace one input by
 * hand.
 * There is an intentional defect; the original source may have other issues.
 * Explain the cause of a failure instead of patching only the visible
 * example.
 */
void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *b;
	*a = *b;
	*b = temp;
}
