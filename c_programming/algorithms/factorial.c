#include <stdio.h>

/* factorial number is 5! where 5 * 4 * 3 * 2 * 1 = 
*/

int factorial(int number)
{
    /* base case */
    if (number == 1) { return 1; }

    return number * factorial(number - 1);
}

int main()
{
    int fact = factorial(3);

    printf("%d\n", fact);
    return 0;
}