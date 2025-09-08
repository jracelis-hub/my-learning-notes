#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/* What is variadic functions?
 * Takes any number of parameters
 * To create a variadic function the format is
 * int function_name(int count, ...)
 * The ... represents variadic function
*/


/* Usage:
 * This is just a type def
 * va_list args;
 *
 * va_start(args,the parameter before the ...
 * Example: int example(int last, ... );
 * va_start(args,last);
 *
 * va_args(args,data_type); Be sure to capture the data type returned
 * Example: 
 * int variable_name = va_args(args,int);
 *
 * va_end(args); To close it
*/

int sum(int count,...) {
	va_list args;
	va_start(args,count);

	int s = 0;
	for (int i=0; i<count; i++) {
		int x = va_arg(args,int);
		s += x;
	}

	va_end(args);
	return s;
}

int main(int argc, char* argv[]) {
	
	/* The first parameter is the amount 
	of arguments that are going to be used
	*/
	int total = sum(4,1,1,1,1);

	printf("%d\n",total);
	return 0;
}
