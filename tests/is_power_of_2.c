#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	for (unsigned int n = 0; n < 4096; n++)
	{
		unsigned int x = n;
		while (x > 1 && x % 2 == 0)
			x /= 2;
		CHECK_INT(!!is_power_of_2(n), (n != 0 && x == 1));
	}
	CHECK_BOOL(is_power_of_2(2147483648u), 1);
	CHECK_BOOL(is_power_of_2(4294967295u), 0);
	return (0);
}
