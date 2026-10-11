#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	CHECK_INT(ft_atoi_base("-2A", 16), -42);
	CHECK_INT(ft_atoi_base("12f", 16), 303);
	CHECK_INT(ft_atoi_base("12F", 16), 303);
	CHECK_INT(ft_atoi_base("10101", 2), 21);
	CHECK_INT(ft_atoi_base("1234", 4), 27);
	CHECK_INT(ft_atoi_base("", 16), 0);
	CHECK_INT(ft_atoi_base("g", 16), 0);
	return (0);
}
