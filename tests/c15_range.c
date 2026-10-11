#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	int *p;

	CASE("p = range(2, -1)");
	p = range(2, -1);
	CHECK_NOT_NULL(p);
	for (int i = 0; i < 4; i++)
		CHECK_INT(p[i], 2 - i);
	free(p);
	return (0);
}
