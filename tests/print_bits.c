#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	CASE("print_bits(0)");
	print_bits(0);
	CASE("print_bits(255)");
	print_bits(255);
	CASE("print_bits(128)");
	print_bits(128);
	CASE("print_bits(1)");
	print_bits(1);
	return (0);
}
