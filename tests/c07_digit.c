#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	CHECK_INT(digit('7'), 7);
	CHECK_INT(digit('0'), 0);
	CHECK_INT(digit('x'), -1);
	return (0);
}
