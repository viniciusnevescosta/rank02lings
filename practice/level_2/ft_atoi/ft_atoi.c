/*
 * ft_atoi: Parsing has whitespace, sign, and digit phases
 *
 * An integer parser first decides where the numeric text begins, then
 * handles an optional sign, then consumes consecutive decimal digits. A
 * later unrelated character ends the numeric part; it is not another digit.
 *
 * Example:
 *     "  -28tail" represents -28.
 *     "--28" has no valid digit sequence after its first sign.
 *     Reading digits 2 and 8 builds a magnitude of 28, not 10.
 *
 * The whitespace accepted by atoi includes more than spaces and tabs. A
 * digit character must become its numeric value before accumulation. Think
 * about intermediate representation as well as the final result: forming a
 * positive magnitude can need more range than a negative int of the same
 * decimal digits.
 *
 * GOAL: Repair ft_atoi to reproduce atoi-style parsing: leading whitespace,
 * one optional sign, consecutive decimal digits, and stopping at the first
 * nondigit. See SUBJECT.md; do not call library parsing functions.
 */
int	ft_atoi(const char *str)
{
	int	number;
	int	sign;

	while ((*str <= 9 && *str <= 13) || *str == ' ')
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	number = 0;
	while (*str >= '0' && *str <= '9')
		number = number * 10 + *str++ - '0';
	return (number * sign);
}
