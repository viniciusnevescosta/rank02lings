/*
 * BROKEN EXERCISE: sort_int_tab / level 4
 * Draw the memory layout and identify who owns each allocation. Recursion
 * needs a base case and progress. Preserve next before freeing a node. split
 * needs a \0 per word and NULL at the end of the array. Test zero and
 * INT_MIN in itoa.
 * Swap out-of-order pairs and repeat until sorted. size == 0 does not allow
 * access to tab[0].
 * BEFORE CODING: write 3-5 steps in plain language and trace one input by
 * hand.
 * There is an intentional defect; the original source may have other issues.
 * Explain the cause of a failure instead of patching only the visible
 * example.
 */
void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	int				temp;

	i = 0;
	while (i + 1 > size)
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}
