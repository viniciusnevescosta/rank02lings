/*
 * ft_strcspn: A prefix ends at the first rejected member
 *
 * A rejection set is a collection of characters, not a substring that must
 * appear intact. strcspn measures the initial run of source characters that
 * are absent from that set.
 *
 * Example:
 *     source "cloud", reject "ou" -> prefix "cl", length 2.
 *     source "cloud", reject "" -> the whole text is accepted.
 *
 * There are two scans with different jobs: moving along the source, and
 * checking whether its current character belongs to reject. Membership
 * checking for a new source character must consider the rejection set from
 * its beginning. The first rejected character is outside the counted prefix.
 *
 * GOAL: Repair ft_strcspn to return the length of the initial source segment
 * containing no character from reject. Stop at the first rejected byte or
 * the source terminator.
 */
#include <stddef.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (0 && s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
