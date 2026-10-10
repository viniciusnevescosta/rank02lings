#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define CHECK(x) do{if(!(x)){fprintf(stderr,"Falha na linha %d: %s\n",__LINE__,#x);return 1;}}while(0)
#include "STUDENT_SOURCE"
int main(void){char a[]="abc",b[]="";inverter(a);CHECK(!strcmp(a,"cba"));inverter(b);CHECK(!strcmp(b,""));return 0;}
