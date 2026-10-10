#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define CHECK(x) do{if(!(x)){fprintf(stderr,"Falha na linha %d: %s\n",__LINE__,#x);return 1;}}while(0)
#include "STUDENT_SOURCE"
int main(void){CHECK(valor_base('f')==15);CHECK(valor_base('A')==10);CHECK(valor_base('0')==0);CHECK(valor_base('g')==-1);return 0;}
