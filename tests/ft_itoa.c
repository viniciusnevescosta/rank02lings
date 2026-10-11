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
	int ns[] = {0, 1, -1, 42, -987, INT_MAX, INT_MIN};
	for (int i = 0; i < 7; i++)
	{
		char expected[40];
		snprintf(expected, sizeof(expected), "%d", ns[i]);
		char *p = ft_itoa(ns[i]);
		CHECK(p != NULL);
		CHECK(!strcmp(p, expected));
		free(p);
	}
	return 0;
}
