#include <iostream>
#include <deque>

/* Double sided queue (deque) has front and back operations 

         Front                                      End  
              -------------------------------------
Dequeue <---  | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | <--- Enqueue
pop_front()   -------------------------------------     push_back()

Enqueue add an element to the end of the queue
Dequeue remove an element in the front of the queue

Supports Random Access O(1) index look up
myDeque[n];
myDeque.at(n);
*/

void output_deque(std::deque<int>& myDeque)
{
	std::cout << "Front of Queue  ";
	for (auto value : myDeque)
	{
		std::cout << value << " <--- ";
	}
	std::cout << " Back of Queue" << std::endl;
}

void output_popped_front(std::deque<int>& myDeque)
{
	std::cout << "Popping " << myDeque.front() 
	          << " from the deque front!" << std::endl;
	myDeque.pop_front();	
}

void output_popped_back(std::deque<int>& myDeque)
{
	std::cout << "Popping " << myDeque.back() 
	          << " from the deque back!" << std::endl;
	myDeque.pop_back();	
}

int main()
{
	std::deque<int> myDeque;

	myDeque.push_back(5);
	myDeque.push_front(3);
	myDeque.push_back(10);

	/* Supports Random Access */
	std::cout << "Index at 2 = " << myDeque.at(2) << std::endl;
	std::cout << "Index at 0 = " << myDeque[0] << std::endl;

	output_deque(myDeque);

	output_popped_front(myDeque);

	output_popped_back(myDeque);

	output_deque(myDeque);

	if (myDeque.empty()) 
	{
		std::cout << "I am empty!" << std::endl;
	}

	std::cout << myDeque.size() << std::endl;

	return 0;
}
