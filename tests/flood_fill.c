#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define CHECK(x) do { if (!(x)) { fprintf(stderr,"Failure: line %d: %s\n",__LINE__,#x); return 1; } } while(0)
#include "STUDENT_SOURCE"

int main(void){char a[]="000X0",b[]="0XX00",c[]="000X0";char *tab[]={a,b,c};t_point size={5,3},begin={0,0};flood_fill(tab,size,begin);CHECK(!strcmp(a,"FFFX0"));CHECK(!strcmp(b,"FXX00"));CHECK(!strcmp(c,"FFFX0"));char d[]="0X",e[]="X0";char *t[]={d,e};t_point sz={2,2},bg={0,0};flood_fill(t,sz,bg);CHECK(!strcmp(d,"FX"));CHECK(!strcmp(e,"X0"));return 0;}
