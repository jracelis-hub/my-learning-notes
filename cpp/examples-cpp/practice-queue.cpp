#include <iostream>
#include <queue>
#include <string>

/* FIFO FIrst In First Out
 * Operations:
 * .push(Type T) add an element on the end of queue
 * .pop(Type T) remove first element in queue
 * .front() to see first element in queue
 * .end() to see last element in queue
 * .empty() to see if the queue is empty
 * .size() to get size of queue
 * */

int main()
{
	std::queue<std::string> myQueue;

	myQueue.push("Jarron"); /* First element front() */
	myQueue.push("Hayeon");
	myQueue.push("Darwin"); /* Last element back() */
	auto size = myQueue.size();

	std::cout << "Queue size = " << size << std::endl;

	int i = 0;
	while (!myQueue.empty())
	{
		std::cout << "Item " << i++ << " = " << myQueue.front() << std::endl;
		myQueue.pop();
	}

	return 0;
}
