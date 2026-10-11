/*
 * sort_int_tab: Ordering neighbors while preserving the array
 *
 * An ascending array satisfies tab[i] <= tab[i + 1] wherever the neighboring
 * pair exists. Fixing one pair can expose another unordered pair, so a local
 * exchange alone may not sort the whole array.
 *
 * Example:
 *     [4, 1, 3] -> [1, 4, 3] fixes the first pair only.
 *     The pair [4, 3] still needs attention.
 *     [2, 2] is already ordered and must keep both elements.
 *
 * The element count is not the final index. Reading i + 1 requires that it
 * is less than size. Empty and one-element arrays need no pair comparisons.
 * In-place sorting changes the supplied objects, not a separate array or
 * merely a local pointer. A second sort should leave the ordered values
 * ordered.
 *
 * GOAL: Repair sort_int_tab to sort the supplied int array in ascending
 * order in place, preserving duplicates. Handle sizes zero and one without
 * invalid accesses.
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
