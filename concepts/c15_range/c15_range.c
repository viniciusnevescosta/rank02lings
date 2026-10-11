/*
 * c15_range: Array indexes and the values stored at them
 *
 * An array index describes a storage position. A range value describes the
 * integer to store there. The two need not match, especially for negative or
 * descending ranges.
 *
 * Example:
 *     values:  4, 3, 2
 *     indexes: 0, 1, 2
 *     malloc(3 * sizeof(int)) reserves space for these three integers.
 * Three bytes would not normally hold three int objects.
 *
 * Plan three things independently: the number of slots, the direction of the
 * values, and which slot is being filled. This int array has a known length;
 * it does not use a string terminator. Check allocation failure before
 * writing through the returned pointer. Inputs are between -100 and 100.
 *
 * GOAL: Make range allocate and return all integers from a to b, including
 * both endpoints, in that direction. Examples: (4, 2) -> [4, 3, 2]; (0, 0)
 * -> [0]. Return NULL on allocation failure.
 */
#include <stdlib.h>

int	*range(int a, int b)
{
	(void)a;
	(void)b;
	return (NULL);
}
