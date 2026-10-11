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
	char a[] = "", b[] = "abc", c[] = {1, 127, 0};
	CHECK(ft_strlen(a) == 0);
	CHECK(ft_strlen(b) == 3);
	CHECK(ft_strlen(c) == 2);
	return 0;
}
