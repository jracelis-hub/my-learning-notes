#include <iostream>
#include <string>

/* Standard Template Library (STL) 
   String is a built in class in C++
   it is declared by using std::string
*/

int main()
{
	std::string first_name = "Jarron";
	std::string last_name = "Racelis";
	std::string full_name = first_name + last_name;

	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Full name: " << full_name << std::endl;

	return 0;
}
