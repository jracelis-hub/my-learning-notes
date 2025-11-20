#include <iostream>
#include <string>
#include <typeinfo>

int main()
{
	auto score = 10;
	std::string words = "Score type = ";

	std::cout << words << typeid(score).name() << std::endl;
	
	return 0;	
}
