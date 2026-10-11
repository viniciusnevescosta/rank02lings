#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	CHECK_INT(lowercase('A'), 'a');
	CHECK_INT(lowercase('Z'), 'z');
	CHECK_INT(lowercase('?'), '?');
	return (0);
}
