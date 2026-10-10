/*
BROKEN EXERCISE: ft_list_foreach / level 4
Draw the memory layout and identify who owns each allocation. Recursion needs a base case and progress. Preserve next before freeing a node. split needs a \0 per word and NULL at the end of the array. Test zero and INT_MIN in itoa.
Call f with each node data, then advance to next. An empty list needs no callback.
BEFORE CODING: write 3-5 steps in plain language and trace one input by hand.
There is an intentional defect; the original source may have other issues.
Explain the cause of a failure instead of patching only the visible example.
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
