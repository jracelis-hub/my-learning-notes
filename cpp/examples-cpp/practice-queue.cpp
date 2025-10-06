#include <iostream>
#include <queue>
#include <string>
#include <stack>

int main()
{
	/* First in First Out (FIFO) */
	std::queue<std::string> eventQueue;
	/* Last in First Out (LIFO) */
	std::stack<std::string> undoStack;

	/* Pushes element in to the queue */
	eventQueue.push("Move left");
	eventQueue.push("Move up");

	while (!eventQueue.empty()) {
		/* Grabest the end of the value in the queue */
		std::string currEvent = eventQueue.front();
		std::cout << "Performing event: " << currEvent << std::endl;
		/* Removes the front element from the queue */
		eventQueue.pop();
		/* Pushes event onto the stack */
		undoStack.push(currEvent);
	}

	/* .top() Removes the last event that was pushed on top of the stack */
	while (!undoStack.empty()) {
		std::cout << "Undo action: " << undoStack.top() << std::endl;
		undoStack.pop();
	}

	return 0;
}
