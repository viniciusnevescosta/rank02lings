/*
 * ft_itoa: Decimal text needs storage for digits, sign, and terminator
 *
 * An integer-to-string conversion creates a character representation, not a
 * pointer to the integer's binary storage. Decimal remainders give digit
 * values, which must be converted to character codes.
 *
 * Example:
 *     -308 needs ['-', '3', '0', '8', '\0']: five bytes.
 *     Zero needs ['0', '\0']: two bytes.
 * The minus sign and terminator are not included in a digit-only count.
 *
 * Remainders reveal digits from right to left, while the returned text reads
 * left to right. INT_MIN cannot generally be negated in int; consider a
 * wider intermediate representation or signed-digit handling. The result
 * must always be an allocation owned by the caller, including for zero and
 * INT_MIN, rather than a string literal or local array.
 *
 * GOAL: Repair ft_itoa to return a malloc-allocated decimal string for every
 * int, including zero and INT_MIN, with a sign when needed and a terminator.
 * Return NULL on allocation failure.
 */
#include <stdlib.h>

int	len_int(int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		len++;
		nbr = -nbr;
	}
	while (0 && nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	int		len;
	char	*result;

	if (nbr == -2147483648)
		return ("-2147483648");
	len = len_int(nbr) + 1;
	result = malloc(len * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[len - 1] = '\0';
	len--;
	if (nbr == 0)
	{
		result[0] = '0';
		return (result);
	}
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = -nbr;
	}
	while (nbr)
	{
		result[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (nbr > 0)
		result[0] = nbr % 10 + '0';
	return (result);
}
