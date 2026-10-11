/*
 * c10_reverse: Two ends of the same writable array
 *
 * Reversing in place means changing the existing array rather than
 * allocating a second one. A pair of indexes can refer to opposite ends of
 * the text. Each exchange places two characters into their final positions.
 *
 * Trace:
 *     "abcd" -> "dbca" after exchanging the outside pair.
 *     "dbca" -> "dcba" after exchanging the inside pair.
 * A middle character in an odd-length string needs no exchange.
 *
 * The final text character precedes '\0'; the terminator should remain where
 * it is. Empty strings have no character pair. The operation must stop when
 * the indexes meet or cross, otherwise already reversed characters could be
 * swapped back.
 *
 * GOAL: Make reverse reverse the characters of a writable string in place
 * while preserving its terminator. Examples: "abcd" -> "dcba"; "a" -> "a";
 * "" -> "".
 */

void	reverse(char *s)
{
	(void)s;
}
