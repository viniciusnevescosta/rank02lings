#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	int a;
	int b;

	a = 1;
	b = -7;
	CASE("ft_swap(&a, &b)");
	ft_swap(&a, &b);
	CHECK_INT(a, -7);
	CHECK_INT(b, 1);
	CASE("ft_swap(&a, &a)");
	ft_swap(&a, &a);
	CHECK_INT(a, -7);
	return (0);
}
