#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define CHECK(x) do{if(!(x)){fprintf(stderr,"Falha na linha %d: %s\n",__LINE__,#x);return 1;}}while(0)
#include "STUDENT_SOURCE"
int main(void){CHECK(tamanho_intervalo(-1,2)==4);CHECK(tamanho_intervalo(3,1)==3);CHECK(tamanho_intervalo(0,0)==1);return 0;}
