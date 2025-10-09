#include <iostream>
#include <list>

/* List is a doubly linked list 
 * Doubly Linked List can traverse forward and backward
 * .push_front(value) prepends value at the beginning
 * .push_back(value) appends value at the end
 * .front() returns value at front of list
 * .back() returns value at back of list
 * .begin() returns ::iterator at 1 element
 * .end() returns ::iterator 1 after last element 
 * .rend() returns reverse::iterator 1 before first element
 * .rbegin() returns reverse::iterator at last element
 * .insert(iterator, value) or .insert(iterator, count, value) or .insert(iterator, range, range)
 * .empty() returns bool value if empty or not
 * */

/* 
 *
 *
 *
 * */

int main()
{
	std::list<int> myList;

	myList.push_front(4);
	myList.push_front(3);
	myList.push_front(5);
	myList.push_back(7);

	std::list<int> myOtherList = {0, 2, 3};

	/* 5 3 4 7 */
	auto it = myList.begin();
	std::cout << "Beginning = " << *it << std::endl;
	advance(it, 2);
	myList.insert(it, myOtherList.begin(), myOtherList.end());

	int i = 0;
	for (int& item : myList)
	{
		std::cout << "Item " << i++ << " ---> " << item << " ";
	}
	std::cout << '\n' << std::flush;

	int front = myList.front();
	int back = myList.back();
	int size = myList.size();

	std::cout << "Size = " << size << std::endl;
	std::cout << "Front value = " << front << std::endl;
	std::cout << "Back value = " << back << std::endl;

	return 0;
}
