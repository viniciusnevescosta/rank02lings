/*
BROKEN EXERCISE: ft_strrev / level 2
Describe the state before writing the loop. Use unsigned char for byte comparisons when appropriate. A string copy needs length + 1 bytes. Use unsigned values for masks and shifts. Test empty input and boundaries.
Move two indexes toward each other. An empty string has no last character.
BEFORE CODING: write 3-5 steps in plain language and trace one input by hand.
There is an intentional defect; the original source may have other issues.
Explain the cause of a failure instead of patching only the visible example.
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
