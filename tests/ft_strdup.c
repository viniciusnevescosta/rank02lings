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
	char *s[] = {"", "abc", "a b"};
	for (int i = 0; i < 3; i++)
	{
		char *p = ft_strdup(s[i]);
		CHECK(p != NULL);
		CHECK(p != s[i]);
		CHECK(!strcmp(p, s[i]));
		p[0] = 0;
		free(p);
	}
	return 0;
}
