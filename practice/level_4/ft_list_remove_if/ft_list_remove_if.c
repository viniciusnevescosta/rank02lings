/*
 * ft_list_remove_if: Changing a link owned by the caller
 *
 * Removing a node requires changing the pointer that led to it. For a head
 * node, that pointer belongs to the caller, which is why the parameter is
 * t_list ** rather than t_list *.
 *
 * Example:
 *     head -> [2] -> [2] -> [5] -> NULL
 *     Removing value 2 must leave head -> [5] -> NULL.
 * Consecutive matches must both be considered; advancing past the next node
 * after a removal can skip a match.
 *
 * Read any needed next link before freeing a node, because freed memory
 * cannot be accessed. Payloads may be owned elsewhere; do not assume they
 * are allocations you may free. The comparator's equality signal is zero,
 * like strcmp, rather than a nonzero boolean match.
 *
 * GOAL: Repair ft_list_remove_if to unlink and free every node whose data
 * compares equal to data_ref. Update the caller's head when necessary,
 * preserve other nodes, and handle empty lists.
 */
#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*node;

	if (!begin_list || !*begin_list)
		return ;
	node = *begin_list;
	if ((*cmp)(node->data, data_ref) != 0)
	{
		*begin_list = node->next;
		free(node);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	else
		ft_list_remove_if(&node->next, data_ref, cmp);
}
