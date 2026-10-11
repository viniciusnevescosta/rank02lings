/*
 * c01_count: Addresses, characters, and the end of a string
 *
 * A char pointer stores an address. The string is the sequence of characters
 * at that address. Testing a pointer asks whether its address is NULL; it
 * does not ask whether the current character is the end marker.
 *
 * Example:
 *     char text[] = "hi";
 *     text[0] is 'h', text[1] is 'i', text[2] is '\0'.
 *     An index of 1 selects text[1]; the address of text stays the same.
 *
 * '\0' is a byte with value zero. It occupies memory but is not part of the
 * text's length. Even "" has storage for this byte. A loop needs both a
 * condition that inspects the right information and progress that eventually
 * changes that condition.
 *
 * GOAL: Make count return the number of characters before the first \0.
 * Examples: "hi" -> 2; "" -> 0. Keep the existing function signature; the
 * tester supplies main().
 */

int	count(char *s)
{
	(void)s;
	return (0);
}
