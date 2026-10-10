#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define CHECK(x) do{if(!(x)){fprintf(stderr,"Falha na linha %d: %s\n",__LINE__,#x);return 1;}}while(0)
#include "STUDENT_SOURCE"
int main(void){CHECK(soma_recursiva(0)==0);CHECK(soma_recursiva(1)==1);CHECK(soma_recursiva(5)==15);return 0;}
