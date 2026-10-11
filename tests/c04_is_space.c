#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	CHECK_BOOL(is_space(' '), 1);
	CHECK_BOOL(is_space('\t'), 1);
	CHECK_BOOL(is_space('a'), 0);
	CHECK_BOOL(is_space('\n'), 0);
	return (0);
}
