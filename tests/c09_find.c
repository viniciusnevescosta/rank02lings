#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	CHECK_INT(find("abc", 'b'), 1);
	CHECK_INT(find("abc", 'x'), -1);
	CHECK_INT(find("", 'a'), -1);
	return (0);
}
