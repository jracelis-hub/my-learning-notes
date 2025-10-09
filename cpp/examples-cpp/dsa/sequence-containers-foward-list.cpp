#include <iostream>
#include <forward_list>

/* Forward List is a single linked list
 * Operations:
 * .push_front(10) adds element to front of singly linked list
 * .front() returns element at the front of the singly linked list
 * .empty() check is the singly linked list is empty
 * .begin() returns a iterator to the beginning of the linked list
 */

template <typename T>
void print_front_element(const std::forward_list<T>& myForwardList)
{
	std::cout << "Front element = " << myForwardList.front() << std::endl;
}

int main()
{
	std::forward_list<int> myForwardList;
	std::forward_list<int>::iterator begin;
	std::forward_list<int>::iterator end;
	
	myForwardList.push_front(10); /* Last */
	myForwardList.push_front(15); /* Mid */
	myForwardList.push_front(20); /* First */

	begin = myForwardList.begin();
	end = myForwardList.end();

	int size = 0;
	while (begin != end)
	{
		std::cout << *begin++ << std::endl;
		size++;
	}

	print_front_element(myForwardList);

	return 0;
}
