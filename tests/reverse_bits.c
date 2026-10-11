#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define CHECK(x) do { if (!(x)) { fprintf(stderr,"Failure: line %d: %s\n",__LINE__,#x); return 1; } } while(0)
#include "STUDENT_SOURCE"

int main(void){for(unsigned int n=0;n<256;n++){unsigned int v=n,r=0;for(int i=0;i<8;i++){r=r*2+v%2;v/=2;}CHECK(reverse_bits(n)==r);}return 0;}
