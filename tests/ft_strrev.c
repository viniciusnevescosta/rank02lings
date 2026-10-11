#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	char a[] = "abcd", b[] = "abc", c[] = "", d[] = "a";
	CHECK_POINTER(ft_strrev(a), a);
	CHECK_STRING(a, "dcba");
	CASE("ft_strrev(b)");
	ft_strrev(b);
	CHECK_STRING(b, "cba");
	CASE("ft_strrev(c)");
	ft_strrev(c);
	CHECK_STRING(c, "");
	CASE("ft_strrev(d)");
	ft_strrev(d);
	CHECK_STRING(d, "a");
	return 0;
}
