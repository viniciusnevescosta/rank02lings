/*
BROKEN EXERCISE: lcm / level 3
Break the task into parsing, state updates, progress, and output. Ranges include both endpoints. Lists end at NULL. Base conversion accumulates value = value * base + digit.
Describe input, output, state, and the stopping condition from the subject.
BEFORE CODING: write 3-5 steps in plain language and trace one input by hand.
There is an intentional defect; the original source may have other issues.
Explain the cause of a failure instead of patching only the visible example.
*/
unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	temp;

	if (a == 0 || b == 0)
		return (0);
	x = a;
	y = b;
	while (0 && y)
	{
		temp = x % y;
		x = y;
		y = temp;
	}
	return (a / x * b);
}
