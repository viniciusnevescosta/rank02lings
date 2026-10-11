#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	int a[] = {-8, -2, -9}, b[] = {1, 9, 3};
	CHECK_INT(max(a, 3), -2);
	CHECK_INT(max(b, 3), 9);
	CHECK_INT(max(NULL, 0), 0);
	CHECK_INT(max(a, 1), -8);
	return 0;
}
