#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define CHECK(x) do{if(!(x)){fprintf(stderr,"Failure on line %d: %s\n",__LINE__,#x);return 1;}}while(0)
#include "STUDENT_SOURCE"
int main(void){CHECK(word_count("  a	b  c ")==3);CHECK(word_count("")==0);CHECK(word_count(" 	 ")==0);return 0;}
