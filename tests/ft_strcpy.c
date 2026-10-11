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
	char d[20];
	memset(d, 63, sizeof(d));
	char s[] = "abc";
	CHECK(ft_strcpy(d, s) == d);
	CHECK(!strcmp(d, "abc"));
	CHECK(d[4] == 63);
	char e[] = "";
	ft_strcpy(d, e);
	CHECK(d[0] == 0);
	return 0;
}
