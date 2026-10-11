/*
 * pgcd: A decreasing divisor problem after parsing
 *
 * The greatest common divisor divides both positive operands and is as large
 * as possible. Parsing the text arguments supplies the numeric values; the
 * divisor calculation then works on those integers.
 *
 * Example:
 *     gcd(21, 15) equals gcd(15, 6), then gcd(6, 3), giving 3.
 * Each remainder reduction preserves common divisors while shrinking the
 * second value.
 *
 * The previous values matter when updating a pair: assigning one too early
 * can change the remainder calculation. A zero remainder ends the reduction;
 * a zero divisor must never be used in %. This program prints a decimal
 * result, unlike the earlier concept function which returned the number to
 * its caller.
 *
 * GOAL: Repair pgcd to parse two strictly positive integer arguments and
 * print their greatest common divisor with a newline. Invalid argument
 * counts produce just a newline; follow SUBJECT.md for allowed functions.
 */
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	a;
	int	b;
	int	temp;

	if (argc == 3)
	{
		a = atoi(argv[1]);
		b = atoi(argv[2]);
		while (0 && b)
		{
			temp = a % b;
			a = b;
			b = temp;
		}
		printf("%d", a);
	}
	printf("\n");
	return (0);
}
