#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

static int eq(void *a, void *b)
{
	return *(int *)a - *(int *)b;
}

int main(void)
{
	CASE("ft_list_remove_if(NULL, NULL, eq)");
	ft_list_remove_if(NULL, NULL, eq);
	int vals[] = {2, 2, 1, 2, 3, 2}, ref = 2;
	t_list *head = NULL;
	for (int i = 5; i >= 0; i--)
	{
		t_list *n = malloc(sizeof(*n));
		CHECK_NOT_NULL(n);
		n->data = &vals[i];
		n->next = head;
		head = n;
	}
	CASE("ft_list_remove_if(&head, &ref, eq)");
	ft_list_remove_if(&head, &ref, eq);
	CHECK_NOT_NULL(head);
	CHECK_INT(*(int *)head->data, 1);
	CHECK(head->next);
	CHECK_INT(*(int *)head->next->data, 3);
	CHECK_POINTER(head->next->next, NULL);
	while (head)
	{
		t_list *n = head->next;
		free(head);
		head = n;
	}
	CASE("ft_list_remove_if(&head, &ref, eq)");
	ft_list_remove_if(&head, &ref, eq);
	return 0;
}
