#include <iostream>
#include <forward_list>
#include <string>

/* Forward_list Singly Linked List
   Lookup takes O(n) 
   Always needs to traverse through the linked list
   to get the corresponding value 

   O(1) prepend since elements do not need to be shifted

   O(n) insert to get to the specified value to insert
   O(n) appending since singly linked list has to traverse till the end

   Does not support .size() method or
   index lookups myList[n]
   index lookups myList.at(n)
 */

int main()
{
	std::forward_list<std::string> myList;
	std::forward_list<std::string> yourList = {"Joe", "John"};

	myList.push_front("Jarron");
	myList.push_front("Hayeon");
	myList.push_front("Cliffy");

	auto it = myList.begin();

	std::advance(it, 2);

	std::cout << "This function " << *it << std::endl;

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
