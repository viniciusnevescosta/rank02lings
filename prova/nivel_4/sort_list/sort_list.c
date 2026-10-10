/*
BROKEN EXERCISE: sort_list / level 4
Draw the memory layout and identify who owns each allocation. Recursion needs a base case and progress. Preserve next before freeing a node. split needs a \0 per word and NULL at the end of the array. Test zero and INT_MIN in itoa.
The comparator is true when a pair is in order. Preserve the head and make progress with repeated values.
BEFORE CODING: write 3-5 steps in plain language and trace one input by hand.
There is an intentional defect; the original source may have other issues.
Explain the cause of a failure instead of patching only the visible example.
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
