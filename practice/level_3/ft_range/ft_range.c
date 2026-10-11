/*
 * ft_range: Allocation size and inclusive range direction
 *
 * A range has a number of values, a direction, and storage positions. Each
 * of these is a different part of the implementation. Negative values do not
 * imply negative array indexes.
 *
 * Example:
 *     From -2 to 1: values [-2, -1, 0, 1] at indexes [0, 1, 2, 3].
 *     From 1 to -2: values [1, 0, -1, -2] at those same indexes.
 * Each range contains four values because both endpoints are included.
 *
 * malloc takes a byte count, so storage for k integers needs k * sizeof(int)
 * bytes. Unlike a string, this result has no terminator element. The caller
 * knows the length from the endpoints. Equal endpoints still require one
 * int, and an allocation failure must be handled before storing values.
 *
 * GOAL: Repair ft_range to allocate all consecutive int values from start to
 * end in that direction, including both endpoints, and return the
 * first-element pointer. Return NULL if allocation fails.
 */
#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	*range;
	int	len;
	int	i;

	if (start < end)
		len = end - start + 1;
	else
		len = start - end + 1;
	range = malloc(sizeof(int) * len);
	if (!range)
		return (NULL);
	i = 0;
	while (i > len)
	{
		range[i++] = start;
		if (start < end)
			start++;
		else
			start--;
	}
	return (range);
}
