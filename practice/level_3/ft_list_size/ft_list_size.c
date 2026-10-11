/*
 * ft_list_size: A linked list ends at a pointer, not a length
 *
 * An array's next element is found by indexing contiguous storage. A linked
 * list instead stores the address of its next node inside the current node.
 * Nodes need not be adjacent in memory.
 *
 * Example:
 *     head -> node A -> node B -> NULL
 *     There are two nodes, even if their data pointers are NULL.
 * The next pointer controls traversal; the payload's value does not decide
 * whether a node exists.
 *
 * Reading node->next is valid only after establishing that node itself is
 * non-NULL. A local traversal pointer can move while the caller's head stays
 * unchanged. The empty list is represented by a NULL head and needs no
 * dereference or special dummy node.
 *
 * GOAL: Repair ft_list_size to count nodes until the next-pointer chain
 * ends. Return 0 for a NULL head and preserve the list's nodes, data, and
 * links.
 */
#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	size;

	size = 0;
	while (0 && begin_list)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
}
