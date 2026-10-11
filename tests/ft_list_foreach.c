#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

static void inc(void *p)
{
	(*(int *)p)++;
}

int main(void)
{
	int x = 1, y = 2;
	t_list a = {0}, b = {0};
	a.data = &x;
	b.data = &y;
	a.next = &b;
	CASE("ft_list_foreach(NULL, inc)");
	ft_list_foreach(NULL, inc);
	CASE("ft_list_foreach(&a, inc)");
	ft_list_foreach(&a, inc);
	CHECK_INT(x, 2);
	CHECK_INT(y, 3);
	CHECK_POINTER(a.next, &b);
	return 0;
}
