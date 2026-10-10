#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define CHECK(x) do{if(!(x)){fprintf(stderr,"Falha na linha %d: %s\n",__LINE__,#x);return 1;}}while(0)
#include "STUDENT_SOURCE"
int main(void){CHECK(buscar("abc",'b')==1);CHECK(buscar("abc",'x')==-1);CHECK(buscar("",'a')==-1);return 0;}
