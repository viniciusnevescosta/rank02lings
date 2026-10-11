#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	CHECK_INT(ft_atoi(" \t\n\v\f\r-42x"), -42);
	CHECK_INT(ft_atoi("+17"), 17);
	CHECK_INT(ft_atoi("0"), 0);
	CHECK_INT(ft_atoi(""), 0);
	CHECK_INT(ft_atoi("--2"), 0);
	CHECK_INT(ft_atoi("2147483647"), 2147483647);
	return (0);
}
