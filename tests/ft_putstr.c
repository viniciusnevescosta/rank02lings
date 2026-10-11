#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define CHECK(x) do { if (!(x)) { fprintf(stderr,"Failure: line %d: %s\n",__LINE__,#x); return 1; } } while(0)
#include "STUDENT_SOURCE"

int main(void){char a[]="abc",b[]="";ft_putstr(a);ft_putstr(b);return 0;}
