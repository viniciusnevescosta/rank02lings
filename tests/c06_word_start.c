#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	CHECK_INT(word_start(" 	 abc"), 3);
	CHECK_INT(word_start("abc"), 0);
	CHECK_INT(word_start("  "), 2);
	return (0);
}
