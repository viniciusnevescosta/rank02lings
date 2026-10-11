/*
 * fprime: Repeated factors and a shrinking remaining number
 *
 * Prime factorization decomposes a positive integer into prime factors whose
 * product equals the original number. A factor may occur several times;
 * duplicates are part of the representation.
 *
 * Example:
 *     20 = 2 * 2 * 5, so the output is "2*2*5".
 *     13 is prime, so its output is "13".
 * After dividing by a discovered factor, that same factor may still divide
 * the remaining number.
 *
 * Progress occurs through reducing the remaining quantity or advancing the
 * candidate divisor. Output separators belong between factors, without a
 * leading or trailing '*'. The value one has the explicit representation "1"
 * even though it has no prime factors. Add one newline after the full
 * expression.
 *
 * GOAL: Repair fprime to print the positive argument's prime factors in
 * ascending order, separated by *, then a newline. Preserve repeated factors
 * and the subject's special case for 1.
 */
#include <stdlib.h>
#include <stdio.h>

void	fprime(int nbr)
{
	int	div;

	div = 1;
	if (nbr < 0)
		return ;
	if (nbr == 1)
		printf("1");
	while (nbr < div++)
	{
		if (nbr % div == 0)
		{
			printf("%d", div);
			if (nbr == div)
				break ;
			printf("*");
			nbr /= div;
			div = 1;
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		fprime(atoi(argv[1]));
	printf("\n");
	return (0);
}
