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
	CHECK(sort_list(NULL, ascending) == NULL);
	t_list a = {0}, b = {0}, c = {0}, d = {0};
	a.data = 3;
	b.data = -1;
	c.data = 3;
	d.data = 0;
	a.next = &b;
	b.next = &c;
	c.next = &d;
	t_list *p = sort_list(&a, ascending);
	int e[] = {-1, 0, 3, 3};
	for (int i = 0; i < 4; i++)
	{
		CHECK(p != NULL);
		CHECK(p->data == e[i]);
		p = p->next;
	}
	CHECK(p == NULL);
	p = sort_list(&a, descending);
	int prev = INT_MAX;
	for (int i = 0; i < 4; i++)
	{
		CHECK(p);
		CHECK(p->data <= prev);
		prev = p->data;
		p = p->next;
	}
	CHECK(!p);
	return 0;
}
