/*
 * sort_list: The comparator defines the requested order
 *
 * A sorting callback lets the caller choose an order. This subject's cmp
 * returns nonzero when two values are already in the correct order and zero
 * otherwise; it is not a strcmp-style three-way comparator.
 *
 * Example:
 *     An ascending predicate accepts (2, 5).
 *     A descending predicate accepts (5, 2).
 *     Equal values can be in the correct order and must both remain.
 *
 * Walk through next pointers rather than assuming contiguous memory. Sorting
 * can exchange node payloads or rearrange links, but the returned pointer
 * must identify the resulting first node. Any changed link must keep every
 * original node reachable exactly once. Empty and one-node lists already
 * require no ordering operations.
 *
 * GOAL: Repair sort_list to return the list ordered according to cmp,
 * preserving duplicates and all nodes. Use the supplied list.h type and do
 * not hardcode ascending order.
 */
#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*start;
	int		temp;

	start = lst;
	while (lst && lst->next)
	{
		if ((*cmp)(lst->data, lst->next->data) != 0)
		{
			temp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = temp;
			lst = start;
		}
		else
			lst = lst->next;
	}
	return (start);
}
