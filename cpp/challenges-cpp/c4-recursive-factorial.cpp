#include <iostream>

int factorial(int n)
{
    if (n < 0 && n > 11) 
    { 
        std::cout << "N has to be between 0 and 10!" << std::endl;
        return -1; 
    }

    int fact;
    /* if n == 0 then fact = 1 
       if n != 0 then n * factoria(n-1)
    */
    fact = n == 0 ? 1 : n * factorial(n-1);
    std::cout << fact << " ";

    return fact;
}

int main()
{
    int fact = factorial(6);

    std::cout << '\n';

    return 0;
}