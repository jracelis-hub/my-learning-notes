#include <iostream>
#include <stdlib.h>

class Node {
private:
	int data = 0;
	Node *next = nullptr;
	
public:
	/* Constructor */
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}

	int getNodeData() {
		return data;
	}

	void setNodeData(int data) {
		this->data = data;
	}

	void connectNode(Node *next) {
		this->next = next;
	}

	void setTailNode() {
		this->next = nullptr;
	}

	int countNodes() {
		int nodeCount = 0;
		Node *current = this;

		while (current != nullptr) {
			nodeCount++;
			current = current->next;
		}

		return nodeCount;
	}

	void insertAtHead(Node *head) {
		this->next = head;	
	}

	void displayNodeSize() {
		std::cout << "Node size = " << countNodes() << std::endl;
	}

	void displayNodesData() {
		Node *current = NULL;
		for (current = this; current != NULL; current = current->next) {
			std::cout << "Node data = "<< current->data << std::endl;
		}
	}
};

int main() 
{
	int linkSize = 0;
	/* Constructor */
	Node *head = new Node(5);
	Node *nodeA = new Node(10);
	Node *nodeB = new Node(55);
	Node *newHead = new Node(33);

	head->connectNode(nodeA);
	nodeA->connectNode(nodeB);
	head->displayNodesData();
	newHead->insertAtHead(head);

	// newHead->displayNodeSize();
	newHead->displayNodesData();

	return 0;
}
