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
	CHECK(word_start(" 	 abc") == 3);
	CHECK(word_start("abc") == 0);
	CHECK(word_start("  ") == 2);
	return (0);
}
