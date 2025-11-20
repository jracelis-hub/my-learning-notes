#include <iostream>

int main()
{
    int number;
    do 
    {
        std::cout << "Enter a number: " << std::flush;
        std::cin >> number;

        if (number < 1)
        {
            std::cout << "Number has to be greater than 1" << std::endl;
            continue;
        }

    } while (number < 1);

    for (int i = 1; i <= number; i++)
    {
        if (i % 3 == 0 && i % 5 != 0) {
            std::cout << "Fizz" << std::endl;
        } else if (i % 5 == 0 && i % 3 != 0) {
            std::cout << "Buzz" << std::endl;
        } else if (i % 3 == 0 && i % 5 == 0) {
            std::cout << "Fizz Buzz" << std::endl;
        } else {
            std::cout << i << std::endl;
        }
    }

    return 0;
}