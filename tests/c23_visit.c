#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

static void inc_int(int *p)
{
	(*p)++;
}

int main(void)
{
	int a[] = {1, 2, 3};
	CASE("visit(a, 3, inc_int)");
	visit(a, 3, inc_int);
	CHECK_INT(a[0], 2);
	CHECK_INT(a[2], 4);
	return 0;
}
