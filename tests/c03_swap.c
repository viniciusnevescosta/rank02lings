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

	a = 3;
	b = 9;
	CASE("swap(&a, &b)");
	swap(&a, &b);
	CHECK_INT(a, 9);
	CHECK_INT(b, 3);
	return (0);
}
