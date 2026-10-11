#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define CHECK(x)                                                               \
	do                                                                         \
	{                                                                          \
		if (!(x))                                                              \
		{                                                                      \
			fprintf(stderr, "Failure on line %d: %s\n", __LINE__, #x);         \
			return 1;                                                          \
		}                                                                      \
	} while (0)
#include "STUDENT_SOURCE"

int main(void)
{
	CHECK(is_space(' '));
	CHECK(is_space('\t'));
	CHECK(!is_space('a'));
	CHECK(!is_space('\n'));
	return (0);
}
