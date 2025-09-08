#include <stdio.h>

/* To type cast a pointer to a different data type 
   Example: 
   int* pnumber <--- this is int pointer
   (float *)pnumber <-- Type casing to a float pointer 
   To dereference above 
   *(float *)pnumber                               */

int main() {

	int* pnumber = NULL;
	int number = 5;

	pnumber = &number;

	printf("%f\n",*(float *)(pnumber));

	return 0;
}
