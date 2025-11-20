#include <stdio.h>

/* Fibinaci sequence is the current number plus the number behind is the sum of the next number
 * Fibinaci(1) = 0
 * Fibinaci(2) = 1
 * Fibinaci(3) = 1
 * Fibinanci(4) = 2 */

 int fibinanci(int count)
 {
    /* Base case is */
    if (count == 1) { return 0; }
    else if (count == 2) { return 1; }
    else if (count == 3) { return 1; }
    else if (count < 1) { return -1; }

    return fibinanci(count - 1) + fibinanci(count - 2);
 }

 int main()
 {
    int fib = fibinanci(0);

    printf("%d\n", fib);

    return 0;
 }