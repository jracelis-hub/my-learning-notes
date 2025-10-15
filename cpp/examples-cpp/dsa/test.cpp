#include <iostream>
#include <memory>

using SinglyLinkedList = struct SinglyLinkedList;

struct SinglyLinkedList {
	int value;
	SinglyLinkedList *node_next;

	/* Functor */
	void operator()(int a_value) {
		this->value = a_value;
	}
};

int main()
{
	/* Uninitialized */
	// SinglyLinkedList* head = new SinglyLinkedList;
	/* Initialized to 0 */
	//SinglyLinkedList* node = new SinglyLinkedList();
	SinglyLinkedList node;

	std::shared_ptr<SinglyLinkedList> head = std::make_shared<SinglyLinkedList>();

	node(5);

	std::cout << node.value <<std::endl;

	return 0;
}
