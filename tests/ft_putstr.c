#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	char a[] = "abc", b[] = "";
	CASE("ft_putstr(a)");
	ft_putstr(a);
	CASE("ft_putstr(b)");
	ft_putstr(b);
	return 0;
}
