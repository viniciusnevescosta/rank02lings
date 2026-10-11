#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define CHECK(x) do { if (!(x)) { fprintf(stderr,"Failure: line %d: %s\n",__LINE__,#x); return 1; } } while(0)
#include "STUDENT_SOURCE"

int main(void){int a=1,b=-7;ft_swap(&a,&b);CHECK(a==-7&&b==1);ft_swap(&a,&a);CHECK(a==-7);return 0;}
