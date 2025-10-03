#include <stdio.h>
#include <stdlib.h>

/* Fibinaci Number - the last two numbers = the next number
 * 1 1 2 3 5 8 13 ...
 * where 1 + 1 = 2 + 1 = 3 + 5 = 8 and soo on
 * pass n number and get the value at that n index
 * fib(4) = 3 because
 * 1 1 2 3 <-- 4th value
 */

 int fibinaci(int n)
 {
	if (n >= 3) { return fibinaci(n-1) + fibinaci(n-2); }
	else if (n < 0) { return -1; }
	else { return 1; }

 }

 int main(int argc, char *argv[])
 {
 	if (argc != 2) {
		fprintf(stderr, "Opps\n");
		return -2;
	}

	int fib = fibinaci(atoi(argv[1]));
	printf("The fib number %s is = %d\n", argv[1], fib);

	return 0;
 }
