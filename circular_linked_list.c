#include <stdlib.h>
#include <stdio.h>

#include "circular_linked_list.h"

void CircularLinkedListPrint(CircularLinkedList* head)
{
	if (!head)
	{
		printf("\n");
		return;
	}
	CircularLinkedList* ptr=head;
	do
	{
		printf("%d ", head->data);
		head = head->next;
	} while (ptr != head);
	printf("\n");
}

CircularLinkedList* CircularLinkedListInsertAtBeginning(CircularLinkedList* head, int data)
{
	CircularLinkedList* new = malloc(sizeof(CircularLinkedList));
	if (!new) exit(1);
	new->data = data;
	if (!head)
	{
		new->next = new;
	}
	else
	{
		new->next = head;
		while (head->next != new->next)
		{
			head = head->next;
		}
		head->next = new;
	}
	return new;
}

CircularLinkedList* CircularLinkedListInsertAtPosition(CircularLinkedList* head, int data, size_t position)
{
	if (position == 0) return CircularLinkedListInsertAtBeginning(head, data);
	if (!head) return NULL;

	size_t counter = 1;
	CircularLinkedList* ptr = head;
	do
	{
		if (counter == position)
		{
			CircularLinkedList* new = malloc(sizeof(CircularLinkedList));
			if (!new) exit(1);
			new->data = data;
			new->next = ptr->next;
			ptr->next = new;
			return head;
		}
		++counter;
		ptr = ptr->next;
	} while (ptr != head);
	return head;
}

CircularLinkedList* CircularLinkedListInsertAtEnd(CircularLinkedList* head, int data)
{
	if (!head) return CircularLinkedListInsertAtBeginning(head, data);

	CircularLinkedList* ptr = head;
	while (ptr->next != head)
	{
		ptr = ptr->next;
	}
	CircularLinkedList* new = malloc(sizeof(CircularLinkedList));
	if (!new) exit(1);
	new->data = data;
	new->next = head;
	ptr->next = new;
	return head;
}







