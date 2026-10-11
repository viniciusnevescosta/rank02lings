#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	char *p[3] = {"a", "b", "x"};

	CASE("terminate_array(p, 2)");
	terminate_array(p, 2);
	CHECK_POINTER(p[2], NULL);
	return (0);
}
