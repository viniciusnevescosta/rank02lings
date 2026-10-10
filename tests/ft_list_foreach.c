#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define CHECK(x) do { if (!(x)) { fprintf(stderr,"Falha: linha %d: %s\n",__LINE__,#x); return 1; } } while(0)
#include "STUDENT_SOURCE"
static void inc(void *p){(*(int*)p)++;}
int main(void){int x=1,y=2;t_list a={0},b={0};a.data=&x;b.data=&y;a.next=&b;ft_list_foreach(NULL,inc);ft_list_foreach(&a,inc);CHECK(x==2&&y==3);CHECK(a.next==&b);return 0;}
