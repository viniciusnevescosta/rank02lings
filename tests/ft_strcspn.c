#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define CHECK(x) do { if (!(x)) { fprintf(stderr,"Falha: linha %d: %s\n",__LINE__,#x); return 1; } } while(0)
#include "STUDENT_SOURCE"

int main(void){char *s[]={"","abc","aaabz","xyz"};char *q[]={"","ab","z","xyz"};for(int i=0;i<4;i++)for(int j=0;j<4;j++)CHECK(ft_strcspn(s[i],q[j])==strcspn(s[i],q[j]));return 0;}
