/* c08_accumulate
GOAL: A new digit shifts the previous decimal places: previous * 10 + digit.
1. Describe input, output, and three steps in plain language.
2. Trace a sample input with a state table.
3. Fix the body below while keeping the signature.
The supplied includes are allowed in the concept stage.
*/
#include <stdlib.h>
#include <string.h>
int accumulate(int atual,int d){(void)atual;(void)d;return atual+d;}
