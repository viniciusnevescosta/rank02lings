#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define CHECK(x) do { if (!(x)) { fprintf(stderr,"Failure: line %d: %s\n",__LINE__,#x); return 1; } } while(0)
#include "STUDENT_SOURCE"

int main(void){CHECK(ft_list_size(NULL)==0);t_list a={0},b={0},c={0};a.next=&b;b.next=&c;CHECK(ft_list_size(&a)==3);CHECK(a.next==&b);return 0;}
