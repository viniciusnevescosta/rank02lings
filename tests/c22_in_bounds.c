#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	CHECK_BOOL(in_bounds(0, 0, 3, 2), 1);
	CHECK_BOOL(in_bounds(-1, 0, 3, 2), 0);
	CHECK_BOOL(in_bounds(3, 0, 3, 2), 0);
	CHECK_BOOL(in_bounds(0, 2, 3, 2), 0);
	return (0);
}
