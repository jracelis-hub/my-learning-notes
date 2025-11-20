#include <stdio.h>
#include <stdlib.h>

typedef struct SinglyLinkedList SinglyLinkedList;

typedef struct SinglyLinkedList {
	int data;
	SinglyLinkedList *next;
} SinglyLinkedList;

SinglyLinkedList *head = NULL;

void append_node(int data)
{
	SinglyLinkedList *n = (SinglyLinkedList *)malloc(sizeof(*n));
	if (!n) { return; }

	n->data = data;
	n->next = NULL;
	
	if (head == NULL)
	{ 
		head = n;
	}
	head->next = n;
	head = n;
}

void print_nodes(void)
{
	for (SinglyLinkedList *temp = head; temp != NULL; temp = temp->next)
	{
		printf("%d\n", temp->data);
	}
}

int main()
{
	append_node(5);	
	append_node(3);	

	print_nodes();


	return 0;
}
