#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	CHECK_INT(accumulate(12, 3), 123);
	CHECK_INT(accumulate(0, 7), 7);
	return (0);
}
