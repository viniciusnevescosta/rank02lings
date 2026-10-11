#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	for (unsigned int n = 0; n < 256; n++)
	{
		unsigned int v = n, r = 0;
		for (int i = 0; i < 8; i++)
		{
			r = r * 2 + v % 2;
			v /= 2;
		}
		CHECK_INT(reverse_bits(n), r);
	}
	return 0;
}
