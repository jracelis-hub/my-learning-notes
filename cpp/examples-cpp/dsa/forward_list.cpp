#include <iostream>
#include <forward_list>
#include <string>

int main()
{
	std::forward_list<std::string> myList;

	myList.push_front("Jarron");
	myList.push_front("Hayeon");
	myList.push_front("Cliffy");
	auto it = myList.begin();

	while (it != myList.end())
	{
		std::cout << *it++ << std::endl;
	}

	if (myList.empty())
	{
		std::cout << "I am empty" << std::endl;
	}

	return 0;
}
