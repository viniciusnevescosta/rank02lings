/*
 * ft_list_foreach: The callback consumes payloads rather than nodes
 *
 * A list node holds both a link and a payload pointer. The callback's void *
 * parameter receives the payload, so the callback can choose how to
 * interpret and modify that data.
 *
 * Example:
 *     node.data = &score;
 *     Calling a suitable callback on node.data can update score.
 *     Passing the node address instead would give it the wrong object.
 *
 * Traversal still follows node->next, independently of what the callback
 * does to a payload. A NULL head is an empty list and makes no callback
 * calls. Preserve the links and head; this function visits existing data,
 * rather than allocating nodes or selecting a hardcoded arithmetic
 * operation.
 *
 * GOAL: Repair ft_list_foreach to invoke f once on each node's data pointer,
 * in list order. Handle an empty list and preserve the list structure.
 */
#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (0 && begin_list)
	{
		(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}
