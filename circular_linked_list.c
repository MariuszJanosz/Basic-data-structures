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

CircularLinkedList* CircularLinkedListRemoveHead(CircularLinkedList* head)
{
	if (!head) return NULL;
	if (head->next == head)
	{
		free(head);
		return NULL;
	}
	CircularLinkedList* ptr = CircularLinkedListFindTail(head);
	ptr->next = head->next;
	free(head);
	return ptr->next;
}

CircularLinkedList* CircularLinkedListRemoveElement(CircularLinkedList* head, CircularLinkedList* element)
{
	if (!head || !element) return head;
	if (head == element) return CircularLinkedListRemoveHead(head);

	CircularLinkedList* ptr = head;
	while (ptr->next != element)
	{
		if (ptr->next == head) return head;
		ptr = ptr->next;
	}
	ptr->next = element->next;
	free(element);
	return head;
}

CircularLinkedList* CircularLinkedListRemovePosition(CircularLinkedList* head, size_t position)
{
	size_t size = CircularLinkedListGetSize(head);
	if (size == 0 || size < position + 1) return head;
	CircularLinkedList* element = head;
	while (position > 0)
	{
		element = element->next;
		--position;
	}
	return CircularLinkedListRemoveElement(head, element);
}

CircularLinkedList* CircularLinkedListRemoveTail(CircularLinkedList* head)
{
	CircularLinkedList* element = CircularLinkedListFindTail(head);
	return CircularLinkedListRemoveElement(head, element);
}

CircularLinkedList* CircularLinkedListEmpty(CircularLinkedList* head)
{
	if (!head) return NULL;
	CircularLinkedList* ptr;
	while (head->next != head)
	{
		ptr = head->next;
		head->next = ptr->next;
		free(ptr);
	}
	free(head);
	return NULL;
}

int CircularLinkedListIsEmpty(CircularLinkedList* head)
{
	if (head) return 0;
	return 1;
}

size_t CircularLinkedListGetSize(CircularLinkedList* head)
{
	if (!head) return 0;
	size_t size = 1;
	CircularLinkedList* ptr = head;
	while (ptr->next != head)
	{
		++size;
		ptr = ptr->next;
	}
	return size;
}

CircularLinkedList* CircularLinkedListFindKey(CircularLinkedList* head, int key)
{
	if (!head) return NULL;
	if (head->data == key) return head;
	CircularLinkedList* ptr = head;
	while (ptr->next != head)
	{
		ptr = ptr->next;
		if (ptr->data == key) return ptr;
	}
	return NULL;
}

CircularLinkedList* CircularLinkedListFindTail(CircularLinkedList* head)
{
	if (!head) return NULL;
	CircularLinkedList* ptr = head;
	while (ptr->next != head)
	{
		ptr = ptr->next;
	}
	return ptr;
}

CircularLinkedList* CircularLinkedListRevers(CircularLinkedList* head)
{
	if (!head) return NULL;
	CircularLinkedList* previous = NULL;
	CircularLinkedList* current = head;
	CircularLinkedList* next;
	do
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	} while (current != head);
	current->next = previous;
	return previous;
}
