#include <stdlib.h>
#include <stdio.h>

#include "doubly_linked_list.h"

void DoublyLinkedListPrint(DoublyLinkedList* head)
{
	while (head)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

DoublyLinkedList* DoublyLinkedListInsertAtBeginning(DoublyLinkedList* head, int data)
{
	DoublyLinkedList* temp = malloc(sizeof(DoublyLinkedList));
	if (!temp) exit(1);
	temp->data = data;
	temp->previous = NULL;
	if (head)
	{
		head->previous = temp;
		temp->next = head;
	}
	else
	{
		temp->next = NULL;
	}
	return temp;
}

DoublyLinkedList* DoublyLinkedListInsertAtPosition(DoublyLinkedList* head, int data, size_t position)
{
	if (position == 0) return DoublyLinkedListInsertAtBeginning(head, data);
	size_t counter = 1;
	DoublyLinkedList* ptr = head;
	while (ptr)
	{
		if (counter == position)
		{
			DoublyLinkedList* new = malloc(sizeof(DoublyLinkedList));
			if (!new) exit(1);
			new->data = data;
			new->previous = ptr;
			new->next = ptr->next;
			ptr->next = new;
			if (new->next) new->next->previous = new;
			return head;
		}
		++counter;
		ptr = ptr->next;
	}
	return head;
}

DoublyLinkedList* DoublyLinkedListInsertAtEnd(DoublyLinkedList* head, int data)
{
	DoublyLinkedList* temp = malloc(sizeof(DoublyLinkedList));
	if (!temp) exit(1);
	temp->data = data;
	temp->next = NULL;
	if (!head)
	{
		temp->previous = NULL;
		return temp;
	}
	DoublyLinkedList* ptr = head;
	while (1)
	{
		if (ptr->next == NULL)
		{
			ptr->next = temp;
			temp->previous = ptr;
			break;
		}
		ptr = ptr->next;
	}
	return head;
}





