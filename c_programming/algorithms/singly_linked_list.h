#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

typedef struct Node Node;

typedef struct Node{
	int data;
	Node* next;
} Node;

void enqueue(int data);
void dequeue(void);

#endif /* SINGLY_LINKED_LIST_H */
