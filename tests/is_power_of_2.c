#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define CHECK(x) do { if (!(x)) { fprintf(stderr,"Failure: line %d: %s\n",__LINE__,#x); return 1; } } while(0)
#include "STUDENT_SOURCE"

int main(void){for(unsigned int n=0;n<4096;n++){unsigned int x=n;while(x>1&&x%2==0)x/=2;CHECK(!!is_power_of_2(n)==(n!=0&&x==1));}CHECK(is_power_of_2(2147483648u));CHECK(!is_power_of_2(4294967295u));return 0;}
