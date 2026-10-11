#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define CHECK(x) do{if(!(x)){fprintf(stderr,"Failure on line %d: %s\n",__LINE__,#x);return 1;}}while(0)
#include "STUDENT_SOURCE"
int main(void){int *p=range(2,-1);CHECK(p);for(int i=0;i<4;i++)CHECK(p[i]==2-i);free(p);return 0;}
