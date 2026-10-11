#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define CHECK(x)                                                               \
	do                                                                         \
	{                                                                          \
		if (!(x))                                                              \
		{                                                                      \
			fprintf(stderr, "Failure: line %d: %s\n", __LINE__, #x);           \
			return 1;                                                          \
		}                                                                      \
	} while (0)
#include "STUDENT_SOURCE"

int main(void)
{
	char *s[] = {"", "abc", "abd", "ab", "z", "\200", "\377"};
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
		{
			int a = ft_strcmp(s[i], s[j]), b = strcmp(s[i], s[j]);
			CHECK((a > 0) - (a < 0) == (b > 0) - (b < 0));
		}
	return 0;
}
