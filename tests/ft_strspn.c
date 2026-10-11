#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	char *s[] = {"", "abc", "aaabz", "xyz"};
	char *q[] = {"", "ab", "z", "xyz"};
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			CHECK_INT(ft_strspn(s[i], q[j]), strspn(s[i], q[j]));
	return 0;
}
