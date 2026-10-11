#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define CHECK(x) do { if (!(x)) { fprintf(stderr,"Failure: line %d: %s\n",__LINE__,#x); return 1; } } while(0)
#include "STUDENT_SOURCE"

int main(void){char *s[]={"","abc","aaabz","xyz"};char *q[]={"","ab","z","xyz"};for(int i=0;i<4;i++)for(int j=0;j<4;j++)CHECK(ft_strspn(s[i],q[j])==strspn(s[i],q[j]));return 0;}
