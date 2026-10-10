#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define CHECK(x) do{if(!(x)){fprintf(stderr,"Falha na linha %d: %s\n",__LINE__,#x);return 1;}}while(0)
#include "STUDENT_SOURCE"
static void inc_int(int *p){(*p)++;}
int main(void){int a[]={1,2,3};visitar(a,3,inc_int);CHECK(a[0]==2&&a[2]==4);return 0;}
