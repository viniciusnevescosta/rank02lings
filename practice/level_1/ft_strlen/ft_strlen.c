/*
 * ft_strlen: Length describes text, not allocated space
 *
 * A string can occupy a larger buffer than its visible text. Its length is
 * determined by the first '\0', not by the size of the containing array or
 * by sizeof on a pointer.
 *
 * Example:
 *     char label[12] = "dog";
 *     The array has 12 char slots, but the string length is 3.
 *     sizeof(label) measures the array; a char * parameter is only a
 *     pointer.
 *
 * Indexes start at zero, so the terminator of "dog" is at index 3. Do not
 * include that byte in the result. The empty string has a terminator at
 * index zero and length zero. Each iteration must inspect a character and
 * make progress to another position.
 *
 * GOAL: Repair ft_strlen to return the number of characters before the first
 * terminator. Examples: "dog" -> 3; "" -> 0. Do not use library functions.
 */
int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] == '\0')
		len++;
	return (len);
}
