#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	int ns[] = {0, 1, -1, 42, -987, INT_MAX, INT_MIN};
	for (int i = 0; i < 7; i++)
	{
		char expected[40];
		snprintf(expected, sizeof(expected), "%d", ns[i]);
		CASE("char *p = ft_itoa(ns[i])");
		char *p = ft_itoa(ns[i]);
		CHECK_NOT_NULL(p);
		CHECK_STRING(p, expected);
		free(p);
	}
	return 0;
}
