#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define CHECK(x) do { if (!(x)) { fprintf(stderr,"Failure: line %d: %s\n",__LINE__,#x); return 1; } } while(0)
#include "STUDENT_SOURCE"

int main(void){char a[]="abcd",b[]="abc",c[]="",d[]="a";CHECK(ft_strrev(a)==a);CHECK(!strcmp(a,"dcba"));ft_strrev(b);CHECK(!strcmp(b,"cba"));ft_strrev(c);CHECK(!strcmp(c,""));ft_strrev(d);CHECK(!strcmp(d,"a"));return 0;}
