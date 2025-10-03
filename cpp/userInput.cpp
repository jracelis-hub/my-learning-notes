#include <iostream>
#include <string>

int main() 
{
	std::string prompt = "Enter a number: ";
	int number = 0;
	/* std::flush makes sure the output is completely
	 * sent onto the terminal                      */
	std::cout << prompt << std::flush;
	std::cin >> number;
	std::cout << "My number is: " << number << std::endl;

	return 0;
}
