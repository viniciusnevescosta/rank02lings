#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	CHECK_INT(digit_count(0), 1);
	CHECK_INT(digit_count(-42), 2);
	CHECK_INT(digit_count(INT_MIN), 10);
	return (0);
}
