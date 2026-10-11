#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define CHECK(x) do { if (!(x)) { fprintf(stderr,"Failure: line %d: %s\n",__LINE__,#x); return 1; } } while(0)
#include "STUDENT_SOURCE"

int main(void){CHECK(ft_atoi_base("-2A",16)==-42);CHECK(ft_atoi_base("12f",16)==303);CHECK(ft_atoi_base("12F",16)==303);CHECK(ft_atoi_base("10101",2)==21);CHECK(ft_atoi_base("1234",4)==27);CHECK(ft_atoi_base("",16)==0);CHECK(ft_atoi_base("g",16)==0);return 0;}
