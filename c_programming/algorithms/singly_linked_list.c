#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list.h"

Node* front = NULL;
Node* rear = NULL;

void enqueue(int data)
{
	Node *n = malloc(sizeof(*n));
	if (!n)
	{ return; }

	n->data = data;
	n->next = NULL;

	if (!front && !rear) 
	{
		front = rear = n;
		return;
	} 

	rear->next = n;
	rear = n;
}

void dequeue(void)
{
	/* Temp is hold the memory address front */
	Node* temp = front;
	if (front == NULL) { return; }
	if (front == rear) 
	{
		front = rear = NULL;
	}
	else
	{
		/* front is not incremented to the next element */
		front = front->next;
	}
	
	/* To remove the element must free the memory */
	free(temp);
}

int is_empty(void) 
{
	if (front == NULL) { return 1; }
	else { return 0; }
}

int peek(void)
{
	return front->data;
}


int main()
{
	enqueue(5);
	enqueue(10);
	enqueue(15);

	for (Node* current = front; current != NULL; current = current->next) 
	{
		printf("%d\n", current->data);
	}

	int value = peek();
	printf("%d\n", value);

	dequeue();
	dequeue();
	dequeue();

	if(is_empty()) 
	{
		printf("Is empty\n");
	}

	return 0;
}
