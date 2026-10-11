#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

static int ascending(int a, int b)
{
	return a <= b;
}

static int descending(int a, int b)
{
	return a >= b;
}

int main(void)
{
	CHECK_POINTER(sort_list(NULL, ascending), NULL);
	t_list a = {0}, b = {0}, c = {0}, d = {0};
	a.data = 3;
	b.data = -1;
	c.data = 3;
	d.data = 0;
	a.next = &b;
	b.next = &c;
	c.next = &d;
	CASE("sort_list(&a, ascending)");
	t_list *head = sort_list(&a, ascending);
	t_list *p = head;
	int e[] = {-1, 0, 3, 3};
	for (int i = 0; i < 4; i++)
	{
		CHECK_NOT_NULL(p);
		CHECK_INT(p->data, e[i]);
		p = p->next;
	}
	CHECK_POINTER(p, NULL);
	CASE("sort_list(head, descending)");
	p = sort_list(head, descending);
	int reversed[] = {3, 3, 0, -1};
	for (int i = 0; i < 4; i++)
	{
		CHECK_NOT_NULL(p);
		CHECK_INT(p->data, reversed[i]);
		p = p->next;
	}
	CHECK_POINTER(p, NULL);
	return 0;
}
