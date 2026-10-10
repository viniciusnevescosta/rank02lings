#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define CHECK(x) do { if (!(x)) { fprintf(stderr,"Falha: linha %d: %s\n",__LINE__,#x); return 1; } } while(0)
#include "STUDENT_SOURCE"

int main(void){CHECK(ft_atoi(" \t\n\v\f\r-42x")==-42);CHECK(ft_atoi("+17")==17);CHECK(ft_atoi("0")==0);CHECK(ft_atoi("")==0);CHECK(ft_atoi("--2")==0);CHECK(ft_atoi("2147483647")==2147483647);return 0;}
