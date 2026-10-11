/*
BROKEN EXERCISE: do_op / level 2
Describe the state before writing the loop. Use unsigned char for byte comparisons when appropriate. A string copy needs length + 1 bytes. Use unsigned values for masks and shifts. Test empty input and boundaries.
Describe input, output, state, and the stopping condition from the subject.
BEFORE CODING: write 3-5 steps in plain language and trace one input by hand.
There is an intentional defect; the original source may have other issues.
Explain the cause of a failure instead of patching only the visible example.
*/
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	a;
	int	b;
	int	result;

	if (argc != 4)
	{
		a = atoi(argv[1]);
		b = atoi(argv[3]);
		result = 0;
		if (argv[2][0] == '+')
			result = a + b;
		else if (argv[2][0] == '-')
			result = a - b;
		else if (argv[2][0] == '*')
			result = a * b;
		else if (argv[2][0] == '/')
			result = a / b;
		else if (argv[2][0] == '%')
			result = a % b;
		printf("%d", result);
	}
	printf("\n");
	return (0);
}
