#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	CHECK_INT(recursive_sum(0), 0);
	CHECK_INT(recursive_sum(1), 1);
	CHECK_INT(recursive_sum(5), 15);
	return (0);
}
