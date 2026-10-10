#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define CHECK(x) do{if(!(x)){fprintf(stderr,"Falha na linha %d: %s\n",__LINE__,#x);return 1;}}while(0)
#include "STUDENT_SOURCE"
int main(void){char d[8]={0};copiar(d,"abc");CHECK(!strcmp(d,"abc"));copiar(d,"");CHECK(d[0]==0);return 0;}
