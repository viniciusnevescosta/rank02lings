#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define CHECK(x) do { if (!(x)) { fprintf(stderr,"Failure: line %d: %s\n",__LINE__,#x); return 1; } } while(0)
#include "STUDENT_SOURCE"

int main(void){int a[]={-8,-2,-9},b[]={1,9,3};CHECK(max(a,3)==-2);CHECK(max(b,3)==9);CHECK(max(NULL,0)==0);CHECK(max(a,1)==-8);return 0;}
