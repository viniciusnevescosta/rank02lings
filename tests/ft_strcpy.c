#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	char d[20];
	memset(d, 63, sizeof(d));
	char s[] = "abc";
	CHECK_POINTER(ft_strcpy(d, s), d);
	CHECK_STRING(d, "abc");
	CHECK_INT(d[4], 63);
	char e[] = "";
	CASE("ft_strcpy(d, e)");
	ft_strcpy(d, e);
	CHECK_INT(d[0], 0);
	return 0;
}
