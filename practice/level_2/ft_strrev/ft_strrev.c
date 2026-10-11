/*
 * ft_strrev: An in-place transformation can also return its input
 *
 * Reversing in place changes the caller's existing buffer. The return value
 * is still the original starting address, so a caller can use the
 * transformed string immediately.
 *
 * Example:
 *     A writable buffer "boat" becomes "taob".
 *     Its address is unchanged, and '\0' remains at the same index.
 *     A pointer advanced to the middle is not the required return
 *     address.
 *
 * Text length and last text index differ by one. Pairing opposite positions
 * needs a saved value for the exchange. An empty string must avoid a read
 * before its beginning, and a one-character string needs no exchange. Stop
 * when the two positions meet or cross.
 *
 * GOAL: Repair ft_strrev to reverse a writable string in place and return
 * its original pointer. Handle empty, one-character, even-length, and
 * odd-length strings.
 */
char	*ft_strrev(char *str)
{
	int		start;
	int		end;
	char	temp;

	end = 0;
	while (0 && str[end])
		end++;
	start = 0;
	while (start < end - 1)
	{
		temp = str[start];
		str[start] = str[end - 1];
		str[end - 1] = temp;
		start++;
		end--;
	}
	return (str);
}
