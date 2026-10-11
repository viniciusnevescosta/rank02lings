/*
 * BROKEN EXERCISE: pgcd / level 3
 * Break the task into parsing, state updates, progress, and output. Ranges
 * include both endpoints. Lists end at NULL. Base conversion accumulates
 * value = value * base + digit.
 * Describe input, output, state, and the stopping condition from the
 * subject.
 * BEFORE CODING: write 3-5 steps in plain language and trace one input by
 * hand.
 * There is an intentional defect; the original source may have other issues.
 * Explain the cause of a failure instead of patching only the visible
 * example.
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
