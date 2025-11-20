#include <iostream>

/* The modulo operator limits at a specific number
 * Example: 5 % 3                 
 * The number remainder that the value can give is
 * 0 1 2 stopping the modulo number 3
 * It can output 3 numbers starting from 0 not including 3
 */
int main()
{
	int number;
	int modulo;

	std::cout << "Enter number = " << std::flush;
	std::cin >> number;

	std::cout << "Enter modulo = " << std::flush;
	std::cin >> modulo;

	std::cout << "Modulo output = " << number % modulo << std::endl;

	return 0;
}
