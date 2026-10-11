#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	CASE("sort_int_tab(NULL, 0)");
	sort_int_tab(NULL, 0);
	int a[] = {3, -1, 3, 0, -8}, e[] = {-8, -1, 0, 3, 3};
	CASE("sort_int_tab(a, 5)");
	sort_int_tab(a, 5);
	for (int i = 0; i < 5; i++)
		CHECK_INT(a[i], e[i]);
	CASE("sort_int_tab(a, 5)");
	sort_int_tab(a, 5);
	for (int i = 0; i < 5; i++)
		CHECK_INT(a[i], e[i]);
	int b[] = {7};
	CASE("sort_int_tab(b, 1)");
	sort_int_tab(b, 1);
	CHECK_INT(b[0], 7);
	return 0;
}
