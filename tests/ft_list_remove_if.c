#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define CHECK(x)                                                               \
	do                                                                         \
	{                                                                          \
		if (!(x))                                                              \
		{                                                                      \
			fprintf(stderr, "Failure: line %d: %s\n", __LINE__, #x);           \
			return 1;                                                          \
		}                                                                      \
	} while (0)
#include "STUDENT_SOURCE"

static int eq(void *a, void *b)
{
	return *(int *)a - *(int *)b;
}

int main(void)
{
	ft_list_remove_if(NULL, NULL, eq);
	int vals[] = {2, 2, 1, 2, 3, 2}, ref = 2;
	t_list *head = NULL;
	for (int i = 5; i >= 0; i--)
	{
		t_list *n = malloc(sizeof(*n));
		CHECK(n != NULL);
		n->data = &vals[i];
		n->next = head;
		head = n;
	}
	ft_list_remove_if(&head, &ref, eq);
	CHECK(head && *(int *)head->data == 1);
	CHECK(head->next && *(int *)head->next->data == 3);
	CHECK(head->next->next == NULL);
	while (head)
	{
		t_list *n = head->next;
		free(head);
		head = n;
	}
	ft_list_remove_if(&head, &ref, eq);
	return 0;
}
