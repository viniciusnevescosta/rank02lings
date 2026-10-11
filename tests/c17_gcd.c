#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	CHECK_INT(gcd(12, 18), 6);
	CHECK_INT(gcd(17, 13), 1);
	CHECK_INT(gcd(0, 7), 7);
	return (0);
}
