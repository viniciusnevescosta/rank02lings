#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	CHECK_INT(count(""), 0);
	CHECK_INT(count("abc"), 3);
	return (0);
}
