#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	CHECK_INT(bit(128, 7), 1);
	CHECK_INT(bit(128, 0), 0);
	CHECK_INT(bit(1, 0), 1);
	return (0);
}
