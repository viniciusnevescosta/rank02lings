#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define CHECK(x) do{if(!(x)){fprintf(stderr,"Failure on line %d: %s\n",__LINE__,#x);return 1;}}while(0)
#include "STUDENT_SOURCE"
int main(void){CHECK(digit('7')==7);CHECK(digit('0')==0);CHECK(digit('x')==-1);return 0;}
