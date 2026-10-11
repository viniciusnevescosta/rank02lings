#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	for (int a = -5; a <= 5; a++)
		for (int b = -5; b <= 5; b++)
		{
			int len = abs(a - b) + 1;
			CASE("int *p = ft_rrange(a, b)");
			int *p = ft_rrange(a, b);
			CHECK_NOT_NULL(p);
			int v = b;
			for (int i = 0; i < len; i++)
			{
				CHECK_INT(p[i], v);
				if (b < a)
					v += 1;
				else
					v += -1;
			}
			free(p);
		}
	return (0);
}
