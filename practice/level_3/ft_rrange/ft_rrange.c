/*
 * ft_rrange: The output starts at the second endpoint
 *
 * Two endpoint names do not force the output to begin with the first
 * argument. This contract requests traversal from end toward start, which is
 * the reverse of ft_range's requested order.
 *
 * Example:
 *     start = -2, end = 1 requests [1, 0, -1, -2].
 *     start = 1, end = -2 requests [-2, -1, 0, 1].
 * Both have the same inclusive length, but opposite directions.
 *
 * Determine length independently from the first value and the direction of
 * subsequent values. Storage indexes still move forward from zero even when
 * the stored numbers decrease. Reserve sizeof(int) bytes per value, handle
 * malloc failure, and remember that equal endpoints still form a one-element
 * result.
 *
 * GOAL: Repair ft_rrange to return an allocated inclusive range beginning at
 * end and finishing at start. Follow SUBJECT.md for the signature and
 * allowed functions.
 */
#include <stdlib.h>

int	*ft_rrange(int start, int end)
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
		range[i++] = end;
		if (end < start)
			end++;
		else
			end--;
	}
	return (range);
}
