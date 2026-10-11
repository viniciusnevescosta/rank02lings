#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	for (unsigned int a = 0; a < 30; a++)
		for (unsigned int b = 0; b < 30; b++)
		{
			unsigned int r = 0;
			if (a && b)
			{
				r = 1;
				while (r % a || r % b)
					r++;
			}
			CHECK_INT(lcm(a, b), r);
		}
	return (0);
}
