#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define CHECK(x) do{if(!(x)){fprintf(stderr,"Failure on line %d: %s\n",__LINE__,#x);return 1;}}while(0)
#include "STUDENT_SOURCE"
int main(void){int a=8,b=-2;sort_pair(&a,&b);CHECK(a==-2&&b==8);sort_pair(&a,&b);CHECK(a==-2&&b==8);return 0;}
