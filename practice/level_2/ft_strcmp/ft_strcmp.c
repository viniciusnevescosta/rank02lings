/*
 * ft_strcmp: Lexicographic ordering depends on the first difference
 *
 * Lexicographic comparison examines characters from left to right. Equal
 * prefixes do not decide the result; the first different byte does. A
 * shorter string also differs at its terminator if the other string
 * continues.
 *
 * Example:
 *     "car" precedes "cat" because r precedes t.
 *     "car" precedes "cargo" because '\0' precedes g at index 3.
 *
 * The contract uses the sign of the returned int: negative, zero, or
 * positive. Compare bytes as unsigned char values, because plain char may
 * represent bytes above 127 as negative values on some systems. Do not keep
 * comparing after a decisive mismatch or read beyond an ended string.
 *
 * GOAL: Repair ft_strcmp to return zero for equal strings and the correct
 * negative or positive ordering otherwise, following strcmp's unsigned-byte
 * behavior.
 */
int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 != *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
