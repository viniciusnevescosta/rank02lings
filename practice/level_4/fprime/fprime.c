/*
 * BROKEN EXERCISE: fprime / level 4
 * Draw the memory layout and identify who owns each allocation. Recursion
 * needs a base case and progress. Preserve next before freeing a node. split
 * needs a \0 per word and NULL at the end of the array. Test zero and
 * INT_MIN in itoa.
 * Describe input, output, state, and the stopping condition from the
 * subject.
 * BEFORE CODING: write 3-5 steps in plain language and trace one input by
 * hand.
 * There is an intentional defect; the original source may have other issues.
 * Explain the cause of a failure instead of patching only the visible
 * example.
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
