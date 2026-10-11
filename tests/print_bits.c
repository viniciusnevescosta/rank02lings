#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define CHECK(x) do { if (!(x)) { fprintf(stderr,"Failure: line %d: %s\n",__LINE__,#x); return 1; } } while(0)
#include "STUDENT_SOURCE"

int main(void){print_bits(0);print_bits(255);print_bits(128);print_bits(1);return 0;}
