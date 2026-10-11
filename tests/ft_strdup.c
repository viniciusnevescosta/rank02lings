#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	char *s[] = {"", "abc", "a b"};
	for (int i = 0; i < 3; i++)
	{
		CASE("char *p = ft_strdup(s[i])");
		char *p = ft_strdup(s[i]);
		CHECK_NOT_NULL(p);
		CHECK(p != s[i]);
		CHECK_STRING(p, s[i]);
		p[0] = 0;
		free(p);
	}
	return 0;
}
