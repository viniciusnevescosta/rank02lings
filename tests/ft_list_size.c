#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	CHECK_INT(ft_list_size(NULL), 0);
	t_list a = {0};
	t_list b = {0};
	t_list c = {0};

	a.next = &b;
	b.next = &c;
	CHECK_INT(ft_list_size(&a), 3);
	CHECK_POINTER(a.next, &b);
	return (0);
}
