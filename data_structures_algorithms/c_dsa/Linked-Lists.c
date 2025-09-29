#include <stdio.h>
#include <stdlib.h>

typedef struct SinglyLinkedList SinglyLinkedList;

typedef struct SinglyLinkedList {
	int data;
	SinglyLinkedList *next;
} SinglyLinkedList;

SinglyLinkedList *create_singly_linked_list()
{
	SinglyLinkedList *singly_linked_list = NULL;
	singly_linked_list = (SinglyLinkedList *)malloc(sizeof(*singly_linked_list));
	if (!singly_linked_list) {
		return NULL;
	}
	singly_linked_list->data = 0;
	singly_linked_list->next = NULL;

	return singly_linked_list;
}

void update_singly_linked_list(SinglyLinkedList *singly_linked_list, int data)
{
	singly_linked_list->data = data;	
}

void prepend_singly_linked_list(SinglyLinkedList *new_head_singly_linked_list,SinglyLinkedList *old_head_singly_linked_list)
{
	new_head_singly_linked_list->next = old_head_singly_linked_list;
	old_head_singly_linked_list->next = NULL; 
}

int count_singly_linked_list(SinglyLinkedList *head_singly_linked_list)
{
	int count = 0;
	SinglyLinkedList *index;
	for (index = head_singly_linked_list; index != NULL; index = index->next) {
		count++;	
	}

	return count;
}

void destory_singly_linked_list(SinglyLinkedList *singly_linked_list)
{
	if (singly_linked_list) {
		free(singly_linked_list);
	}
}


int main()
{
	SinglyLinkedList *head = create_singly_linked_list();
	if (!head) {
		return -1;
		fprintf(stderr, "Wrong\n");
	}

	SinglyLinkedList *new_head = create_singly_linked_list();
	if (!new_head) {
		return -1;
		fprintf(stderr, "Wrong\n");
	}

	update_singly_linked_list(head, 55);


	prepend_singly_linked_list(new_head, head);

	int count = count_singly_linked_list(new_head);

	update_singly_linked_list(new_head, 100);

	printf("%d\n", head->data);
	printf("%d\n", new_head->data);
	printf("%d\n", count);

	destory_singly_linked_list(head);
	destory_singly_linked_list(new_head);

	return 0;
}
