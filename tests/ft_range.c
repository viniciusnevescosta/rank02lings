#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define CHECK(x) do { if (!(x)) { fprintf(stderr,"Falha: linha %d: %s\n",__LINE__,#x); return 1; } } while(0)
#include "STUDENT_SOURCE"

int main(void){for(int a=-5;a<=5;a++)for(int b=-5;b<=5;b++){int len=abs(a-b)+1;int *p=ft_range(a,b);CHECK(p!=NULL);int v=a;for(int i=0;i<len;i++){CHECK(p[i]==v);v+=(a<b?1:-1);}free(p);}return 0;}
