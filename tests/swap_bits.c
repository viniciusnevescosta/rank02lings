#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	for (unsigned int n = 0; n < 256; n++)
		CHECK_INT(swap_bits(n), (n % 16 * 16 + n / 16));
	return (0);
}
