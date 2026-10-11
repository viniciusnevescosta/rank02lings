#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	char d[8] = {0};

	CASE("copy(d, \"abc\")");
	copy(d, "abc");
	CHECK_STRING(d, "abc");
	CASE("copy(d, \"\")");
	copy(d, "");
	CHECK_INT(d[0], 0);
	return (0);
}
