#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	CHECK_INT(word_count("  a	b  c "), 3);
	CHECK_INT(word_count(""), 0);
	CHECK_INT(word_count(" 	 "), 0);
	return (0);
}
