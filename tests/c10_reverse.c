#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	char a[] = "abc", b[] = "";
	CASE("reverse(a)");
	reverse(a);
	CHECK_STRING(a, "cba");
	CASE("reverse(b)");
	reverse(b);
	CHECK_STRING(b, "");
	return 0;
}
