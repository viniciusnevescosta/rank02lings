#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	CHECK_INT(step(1, 3), 1);
	CHECK_INT(step(3, 1), -1);
	CHECK_INT(step(2, 2), 1);
	return (0);
}
