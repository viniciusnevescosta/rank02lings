/*
 * ft_atoi_base: Digit values depend on the numeral base
 *
 * A base tells how many digit values are available and what one position to
 * the left is worth. A valid hexadecimal symbol can still be invalid for a
 * smaller base.
 *
 * Example:
 *     "23" in base 4 represents 2 * 4 + 3 = 11.
 *     The symbol '4' is not allowed in base 4.
 *     'b' and 'B' both represent value 11 in base 16.
 *
 * Character-to-value conversion and base validation are separate decisions.
 * Accumulation uses the requested base, not always ten. This subject
 * recognizes a minus sign only at the very beginning; do not import
 * unrelated whitespace/sign rules from standard atoi. Parsing stops when the
 * next symbol is not a valid digit for the base.
 *
 * GOAL: Repair ft_atoi_base to convert the valid initial digit sequence in
 * the supplied base to an int, handling lowercase/uppercase symbols and the
 * subject's leading-minus rule. Use no library conversion functions.
 */
static int	get_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	result;
	int	sign;
	int	value;

	result = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	value = get_value(*str);
	while (value <= 0 && value < str_base)
	{
		result = result * str_base + value;
		str++;
		value = get_value(*str);
	}
	return (result * sign);
}
