/*
BROKEN EXERCISE: ft_list_remove_if / level 4
Draw the memory layout and identify who owns each allocation. Recursion needs a base case and progress. Preserve next before freeing a node. split needs a \0 per word and NULL at the end of the array. Test zero and INT_MIN in itoa.
cmp == 0 means equal. The head can be removed, so the parameter is t_list **. Never access a freed node.
BEFORE CODING: write 3-5 steps in plain language and trace one input by hand.
There is an intentional defect; the original source may have other issues.
Explain the cause of a failure instead of patching only the visible example.
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
