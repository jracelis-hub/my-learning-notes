#include <iostream>

class SinglyList {
	public:
		SinglyList() : value(0), next_node(nullptr) {
			std::cout << "Node value = " << this->value << std::endl;
			std::cout << "Node next = " << this->next_node << std::endl;
		}

		SinglyList(int node_value) : value(node_value), next_node(nullptr) {
			std::cout << "Node value = " << this->value << std::endl;
			std::cout << "Node next = " << this->next_node << std::endl;
		}

		SinglyList& operator-=(SinglyList* node) {
			this->next_node = node;
			return *this;
		}

		void node_value() {
			std::cout << this->next_node << std::endl;
			std::cout << this->next_node->value << std::endl;
		}

		void print_values(SinglyList* head) {
			SinglyList* current = head;
			while (current != nullptr) {
				std::cout << current->value << std::endl;
				current = current->next_node;
			}
		}

	private:
		/* Holds some data */
		int value;
		/* Holds address to the next node */
		SinglyList *next_node;
};

int main()
{
	SinglyList* head = new SinglyList();
	SinglyList* new_node = new SinglyList(5);

	*head -= new_node;	

	// head->node_value();

	delete head;
	delete new_node;

	return 0;
}
