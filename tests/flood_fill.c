#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "checks.h"
#include "STUDENT_SOURCE"

int main(void)
{
	char a[] = "000X0", b[] = "0XX00", c[] = "000X0";
	char *tab[] = {a, b, c};
	t_point size = {5, 3}, begin = {0, 0};
	CASE("flood_fill(tab, size, begin)");
	flood_fill(tab, size, begin);
	CHECK_STRING(a, "FFFX0");
	CHECK_STRING(b, "FXX00");
	CHECK_STRING(c, "FFFX0");
	char d[] = "0X", e[] = "X0";
	char *t[] = {d, e};
	t_point sz = {2, 2}, bg = {0, 0};
	CASE("flood_fill(t, sz, bg)");
	flood_fill(t, sz, bg);
	CHECK_STRING(d, "FX");
	CHECK_STRING(e, "X0");
	return 0;
}
