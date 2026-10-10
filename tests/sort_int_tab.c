#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define CHECK(x) do { if (!(x)) { fprintf(stderr,"Falha: linha %d: %s\n",__LINE__,#x); return 1; } } while(0)
#include "STUDENT_SOURCE"

int main(void){sort_int_tab(NULL,0);int a[]={3,-1,3,0,-8},e[]={-8,-1,0,3,3};sort_int_tab(a,5);for(int i=0;i<5;i++)CHECK(a[i]==e[i]);sort_int_tab(a,5);for(int i=0;i<5;i++)CHECK(a[i]==e[i]);int b[]={7};sort_int_tab(b,1);CHECK(b[0]==7);return 0;}
