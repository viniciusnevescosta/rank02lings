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
	char *inputs[] = {"", " \t\n ", "one", "  one\ttwo\nthree  ", "a  b"};
	char *expected[][4] = {{NULL},
						   {NULL},
						   {"one", NULL},
						   {"one", "two", "three", NULL},
						   {"a", "b", NULL}};
	for (int k = 0; k < 5; k++)
	{
		char **p = ft_split(inputs[k]);
		CHECK(p != NULL);
		int j = 0;
		while (expected[k][j])
		{
			CHECK(p[j] != NULL);
			CHECK(!strcmp(p[j], expected[k][j]));
			free(p[j]);
			j++;
		}
		CHECK(p[j] == NULL);
		free(p);
	}
	return 0;
}
