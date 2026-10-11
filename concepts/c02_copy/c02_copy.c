/*
 * c02_copy: Copying contents instead of copying an address
 *
 * Two arrays can contain identical text while living at different addresses.
 * Assigning one char pointer to another only makes them refer to the same
 * storage; it does not copy any characters into the destination array.
 *
 * Example:
 *     char source[] = "hi";
 *     char target[4];
 *     target[0] = source[0];
 * This writes one character into target. The other positions are still
 * unspecified until you write them.
 *
 * A complete C string includes its final '\0'. "hi" needs three bytes,
 * although its text length is two. Without that marker, a reader can
 * continue past the copied text. An empty string still requires writing its
 * terminator. Here the caller already provides enough writable destination
 * space; allocation is not your task.
 *
 * GOAL: Make copy(d, s) copy the contents of s into d, including \0. The
 * destination must become an independent copy. Examples: "hi" -> "hi"; "" ->
 * "".
 */

void	copy(char *d, char *s)
{
	(void)d;
	(void)s;
}
