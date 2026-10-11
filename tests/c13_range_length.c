#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	CHECK_INT(range_length(-1, 2), 4);
	CHECK_INT(range_length(3, 1), 3);
	CHECK_INT(range_length(0, 0), 1);
	return (0);
}
