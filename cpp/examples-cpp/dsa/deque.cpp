#include <iostream>
#include <deque>

/* Double sided queue has front and back operations */

int main()
{
	std::deque<int> myDeque;

	myDeque.push_back(5);
	myDeque.push_front(3);
	myDeque.push_back(10);

	myDeque.pop_front();
	myDeque.pop_back();
	myDeque.pop_back();

	for (auto value : myDeque)
	{
		std::cout << value << std::endl;
	}

	if (myDeque.empty()) 
	{
		std::cout << "I am empty!" << std::endl;
	}

	std::cout << myDeque.size() << std::endl;

	return 0;
}
