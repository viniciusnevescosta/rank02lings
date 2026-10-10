#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define CHECK(x) do{if(!(x)){fprintf(stderr,"Falha na linha %d: %s\n",__LINE__,#x);return 1;}}while(0)
#include "STUDENT_SOURCE"
int main(void){CHECK(dentro(0,0,3,2));CHECK(!dentro(-1,0,3,2));CHECK(!dentro(3,0,3,2));CHECK(!dentro(0,2,3,2));return 0;}
