#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	char *p;

	CASE("p = duplicate(\"abc\")");
	p = duplicate("abc");
	CHECK_NOT_NULL(p);
	CHECK_STRING(p, "abc");
	free(p);
	return (0);
}
