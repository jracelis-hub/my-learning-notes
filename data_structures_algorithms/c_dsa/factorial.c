#include <stdio.h>
#include <stdlib.h>

/* Factorial
 * n! = n(n-1)(n-2)...3*2*1
 * can be rewritten as
 * (n-1)! = (n-1)(n-2)...3*2*1
 * there are two conditions that meet that requrement
 *      --> n(n-1)!    if n >= 1
 * n! = |
 *      -->   1        if n = 0
 */

int factorial(int n)
{
	/* Condition one */
	if (n >= 1) { return n * factorial(n - 1); }
	/* Condition two */
	else { return 1; }
	/* How this works behind the scenes is lets say
	 * results = f(4); ---------------> 24
	 * 4 * f(4 - 1) = 4 * f(3) = 4 * 6 = 24
	 * 3 * f(3 - 1) = 3 * f(2) = 3 * 2 = 6
	 * 2 * f(2 - 1) = 2 * f(1) = 2 * 1 = 2
	 * 1 * f(1 - 1) = 1 * f(0) = 1 * 1 = 1
	 * 0 return 1   = f(0) = 1
	 */
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Error\n");
		return -1;
	}

	int fact = factorial(atoi(argv[1]));
	printf("The factorial for %s is: %d\n", argv[1], fact);
	
	return 0;
}
