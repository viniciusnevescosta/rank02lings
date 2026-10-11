/*
 * do_op: Text parsing and integer arithmetic are different stages
 *
 * Command-line numbers arrive as text. Convert each numeric operand before
 * computing; a character such as '7' is not the integer seven. The operator
 * argument selects which arithmetic operation to perform.
 *
 * Example:
 *     Integer -8 / 3 is -2 in C99: division truncates toward zero.
 *     The remainder satisfies a == (a / b) * b + (a % b).
 *     Accordingly, -8 % 3 is -2.
 *
 * Keep reading operands, selecting an operation, and displaying the result
 * separate. Signed results may need a leading minus sign. The subject
 * guarantees valid operand/operator text and an int-sized result; division
 * and remainder still require a nonzero divisor to be defined in C.
 *
 * GOAL: Repair do_op to evaluate the three user arguments as integer
 * operand, operator, integer operand, and print the result with a newline.
 * Follow the allowed functions and parameter rules in SUBJECT.md.
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
