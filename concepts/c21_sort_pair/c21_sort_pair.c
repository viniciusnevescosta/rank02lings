/*
 * c21_sort_pair: Ordering differs from always swapping
 *
 * An ascending pair means the first value is less than or equal to the
 * second. A swap is an operation; ordering is the condition you want that
 * operation to establish. An already ordered pair should remain ordered
 * after another call.
 *
 * Example:
 *     [8, 2] needs to become [2, 8].
 *     [2, 8] already satisfies the condition.
 *     [2, 2] also satisfies it; equal values are allowed.
 *
 * Read the integers through the provided pointers. If you need an exchange,
 * preserve the first original value before overwriting it. Merely changing
 * which addresses the local pointers contain will not update the caller's
 * pair.
 *
 * GOAL: Make sort_pair arrange the two pointed integers in ascending order.
 * It must also handle equal values and an already ordered pair without
 * reversing them.
 */

void	sort_pair(int *a, int *b)
{
	(void)a;
	(void)b;
}
