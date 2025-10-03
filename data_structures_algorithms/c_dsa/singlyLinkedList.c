#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

struct Node *createNode(int data)
{
	struct Node *n = (struct Node *)malloc(sizeof(*n));
	if (!n) {
		return NULL;
	}

	n->data = data;
	n->next = NULL;

	return n;
}

void connectNode(struct Node *current, struct Node *next) 
{
	current->next = next;
}

void appendNode(struct Node *newHead, struct Node *oldHead)
{
	newHead->next = oldHead;
}

int countNodes(struct Node *head)
{
	int nodeCount = 0;
	struct Node *current = head;

	while (current != NULL) {
		nodeCount++;
		current = current->next;
	}

	return nodeCount;
}

int changeNodeData(struct Node *head, int currentData, int newData)
{
	struct Node *current = head;	
	while (current != NULL) {
		if (current->data == currentData) {
			printf("Changing %d --> %d\n", current->data, newData);
			current->data = newData;
			return 0;
		}
		current = current->next;
	}

	printf("Current data %d does not exist!\n", currentData);
	return -1;
}

void insertNewNode(struct Node **head, int position, int data)
{
	struct Node *newNode = createNode(data);
	if (position == 0) {
		appendNode(newNode, *head);
		*head = newNode;
		return;
	}

	int i = 0;
	struct Node *current = *head;
	while (current != NULL && i < position - 1) {
		current = current->next;
		i++;
	}

	if (current == NULL) {
		printf("Position %d is not within the range\n", position);
		free(newNode);
		return;
	}

	newNode->next = current->next;
	current->next = newNode;
}

void displayNodeSize(struct Node *head, int (*countNodes)(struct Node *))
{
	printf("Node size = %d\n", countNodes(head));
}

void displayNodeData(struct Node *head)
{
	struct Node *current = head;

	printf("Displaying node data!\n");
	while (current != NULL) {
		printf("%d\n", current->data);
		current = current->next;
	}
}

int main() 
{
	int nodeCount = 0;
	struct Node *head = createNode(5);
	struct Node *nodeA = createNode(10);

	connectNode(head, nodeA);
	insertNewNode(&head, 0, 6);

	insertNewNode(&head, 4, 55);

	displayNodeData(head);

	return 0;
}

/* changing inserting node
 * insertNode(int position) 
 * if position == 0 
 * 
 * else return NULL;
 * -----       -----      -----      -----
 * | H | ----> | N |      | N | ---> | T | ---> NULL
 * -----       -----      -----      -----
 *               |         /|\
 *             |--          |
 *            \|/           |
 *           -----          |
 *           | N | ----------
 *           -----
*/
