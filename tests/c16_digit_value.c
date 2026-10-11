#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	CHECK_INT(digit_value('f'), 15);
	CHECK_INT(digit_value('A'), 10);
	CHECK_INT(digit_value('0'), 0);
	CHECK_INT(digit_value('g'), -1);
	return (0);
}
