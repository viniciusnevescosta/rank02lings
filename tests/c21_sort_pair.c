#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	int a;
	int b;

	a = 8;
	b = -2;
	CASE("sort_pair(&a, &b)");
	sort_pair(&a, &b);
	CHECK_INT(a, -2);
	CHECK_INT(b, 8);
	CASE("sort_pair(&a, &b)");
	sort_pair(&a, &b);
	CHECK_INT(a, -2);
	CHECK_INT(b, 8);
	return (0);
}
