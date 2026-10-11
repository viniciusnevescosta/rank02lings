#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	char a[] = "", b[] = "abc", c[] = {1, 127, 0};
	CHECK_INT(ft_strlen(a), 0);
	CHECK_INT(ft_strlen(b), 3);
	CHECK_INT(ft_strlen(c), 2);
	return 0;
}
