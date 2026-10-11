/*
 * ft_strspn: Membership must hold for the whole initial segment
 *
 * strspn measures a prefix whose characters all belong to an acceptance set.
 * It stops at the first source character outside the set, even if accepted
 * characters appear later.
 *
 * Example:
 *     source "aabxaba", accept "ab" -> prefix "aab", length 3.
 *     source "aabxaba", accept "" -> length 0.
 * Repeated source characters still contribute to the length; the set need
 * not contain duplicates.
 *
 * A membership scan must restart for every new source character. The two
 * strings have different roles: the source supplies ordered text, while
 * accept supplies possible members. Reaching the end of accept without a
 * match differs from reaching the end of the source after a valid prefix.
 *
 * GOAL: Repair ft_strspn to count the initial consecutive source characters
 * that appear in accept. Stop at the first nonmember or the source
 * terminator.
 */
#include <stddef.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (0 && s[i])
	{
		j = 0;
		while (accept[j] && s[i] != accept[j])
			j++;
		if (accept[j] == '\0')
			return (i);
		i++;
	}
	return (i);
}
