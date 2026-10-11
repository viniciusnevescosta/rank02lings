#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	char *s[] = {"", "abc", "abd", "ab", "z", "\200", "\377"};
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
		{
			CASE("int a = ft_strcmp(s[i], s[j]), b = strcmp(s[i], s[j])");
			int a = ft_strcmp(s[i], s[j]), b = strcmp(s[i], s[j]);
			CHECK_INT((a > 0) - (a < 0), (b > 0) - (b < 0));
		}
	return 0;
}
