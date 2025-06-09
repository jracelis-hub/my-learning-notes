#include <stdio.h>

/* Instructions:
 * Create a char type variable and initialize it to the value 100
 * Print the address of the above variable.
 * Create a pointer variable and store the adrress of the above variable
 * Preform read operation on the pointer variable to fetch 1 byte of data from the pointer
 * Print the data obtained from the read operation on the pointer
 * Preform write operation on the pointer to store the value 65
 * Print the value of the variable define in step 1
*/ 

int main() {

	char variable = 100;
	printf("The data of variable is: %d\n", variable);
	printf("The address of variable is: %p \n", variable);

	/* pvariable is holding the address of variable */
	char* pvariable = &variable;
	/* Here dereferencing the address of *pvariable which is -> &variable to read the stored
	 * value at that point
	*/
	char value = *pvariable;
	
	printf("The data of value is: %d\n", value);
	
	/* Here dereferencing the address of *pvariable to write the value 65 into variable address */
	*pvariable = 65;
	printf("The data of variable is: %d\n", variable);

	return 0;
}
