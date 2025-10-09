#include <iostream>
#include <deque>

/* Deque (Double Ended Queue)
 * .push_front(value) add item at the front of queue
 * .push_back(value) add item at the back of queue
 * .pop_front() remove item at the front of queue
 * .pop_back() remove item at the back of the queue
 * .front() returns type of element at the front of the queue
 * .back() returns type of element at the back of the queue
 * .size() returns value size of queue
 * */

int main()
{

	std::deque<int> myDeque;
	myDeque.push_front(10);
	myDeque.push_front(20);
	myDeque.push_back(30);

	int front = myDeque.front();
	int back = myDeque.back();
	auto it = myDeque.begin();

	return 0;
}
