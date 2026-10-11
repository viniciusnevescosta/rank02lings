#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define CHECK(x) do{if(!(x)){fprintf(stderr,"Failure on line %d: %s\n",__LINE__,#x);return 1;}}while(0)
#include "STUDENT_SOURCE"
int main(void){char d[8]={0};copy(d,"abc");CHECK(!strcmp(d,"abc"));copy(d,"");CHECK(d[0]==0);return 0;}
