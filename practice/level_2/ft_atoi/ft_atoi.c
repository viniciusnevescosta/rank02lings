/*
BROKEN EXERCISE: ft_atoi / level 2
Describe the state before writing the loop. Use unsigned char for byte comparisons when appropriate. A string copy needs length + 1 bytes. Use unsigned values for masks and shifts. Test empty input and boundaries.
Handle whitespace, sign, and digits separately. Stop at the first non-digit. Check intermediate arithmetic for overflow.
BEFORE CODING: write 3-5 steps in plain language and trace one input by hand.
There is an intentional defect; the original source may have other issues.
Explain the cause of a failure instead of patching only the visible example.
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
