/*
BROKEN EXERCISE: ft_rrange / level 3
Break the task into parsing, state updates, progress, and output. Ranges include both endpoints. Lists end at NULL. Base conversion accumulates value = value * base + digit.
Start from end and move toward start. Equal endpoints produce one element.
BEFORE CODING: write 3-5 steps in plain language and trace one input by hand.
There is an intentional defect; the original source may have other issues.
Explain the cause of a failure instead of patching only the visible example.
*/
#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	*range;
	int	len;
	int	i;

	if (start < end)
		len = end - start + 1;
	else
		len = start - end + 1;
	range = malloc(sizeof(int) * len);
	if (!range)
		return (NULL);
	i = 0;
	while (i > len)
	{
		range[i++] = end;
		if (end < start)
			end++;
		else
			end--;
	}
	return (range);
}
