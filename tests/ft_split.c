#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	char *inputs[] = {"", " \t\n ", "one", "  one\ttwo\nthree  ", "a  b"};
	char *expected[][4] = {{NULL},
						   {NULL},
						   {"one", NULL},
						   {"one", "two", "three", NULL},
						   {"a", "b", NULL}};
	for (int k = 0; k < 5; k++)
	{
		CASE("char **p = ft_split(inputs[k])");
		char **p = ft_split(inputs[k]);
		CHECK_NOT_NULL(p);
		int j = 0;
		while (expected[k][j])
		{
			CHECK(p[j] != NULL);
			CHECK_STRING(p[j], expected[k][j]);
			free(p[j]);
			j++;
		}
		CHECK_POINTER(p[j], NULL);
		free(p);
	}
	return 0;
}
