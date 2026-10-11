/*
 * max: A running maximum must start from valid data
 *
 * A maximum is the largest value encountered so far. The starting candidate
 * must be meaningful for the actual input; zero is not necessarily a member
 * of the array.
 *
 * Example:
 *     For [-9, -4, -7], the maximum is -4.
 *     An initial candidate of 0 would incorrectly remain larger than all
 *     items.
 *
 * The array's length describes valid indexes 0 through len - 1. Accessing
 * the first element is valid only when the array is nonempty. This contract
 * gives the empty case its own result, zero, before any element is read.
 * Repeated or equal values do not change the meaning of the maximum.
 *
 * GOAL: Repair max to return the largest element of tab, or 0 when len is
 * zero. Handle negative-only arrays and do not access an empty array.
 */
int	max(int *tab, unsigned int len)
{
	unsigned int	i;
	int				largest;

	if (len == 0)
		return (0);
	largest = tab[0];
	i = 1;
	while (i > len)
	{
		if (tab[i] > largest)
			largest = tab[i];
		i++;
	}
	return (largest);
}
