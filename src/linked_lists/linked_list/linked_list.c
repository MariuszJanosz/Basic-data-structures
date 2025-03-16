#include <stdlib.h>
#include <stdio.h>

#include "linked_list.h"

void LinkedListPrint(LinkedList* head)
{
	while (head)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

LinkedList* LinkedListInsertAtBeginning(LinkedList* head, int data)
{
	LinkedList* temp = malloc(sizeof(LinkedList));
	if (!temp) exit(1);
	temp->data = data;
	if (head)
	{
		temp->next = head;
	}
	else
	{
		temp->next = NULL;
	}
	return temp;
}

LinkedList* LinkedListInsertAtPosition(LinkedList* head, int data, size_t position)
{
	if (position == 0) return LinkedListInsertAtBeginning(head, data);
	
	size_t counter = 1;
	LinkedList* ptr = head;
	while (ptr)
	{
		if (counter == position)
		{
			LinkedList* temp = malloc(sizeof(LinkedList));
			if (!temp) exit(1);
			temp->data = data;
			temp->next = ptr->next;
			ptr->next = temp;
			return head;
		}
		++counter;
		ptr = ptr->next;
	}
	return head;
}

LinkedList* LinkedListInsertAfterElement(LinkedList* head, int data, LinkedList* element)
{
	LinkedList* new = malloc(sizeof(LinkedList));
	if (!new) exit(1);
	new->data = data;
	new->next = element->next;
	element->next = new;
	return head;
}

LinkedList* LinkedListInsertAtEnd(LinkedList* head, int data)
{
	LinkedList* temp = malloc(sizeof(LinkedList));
	if (!temp) exit(1);
	temp->data = data;
	temp->next = NULL;
	if (!head)	return temp;
	LinkedList* ptr=head;
	while (1)
	{
		if (ptr->next == NULL)
		{
			ptr->next = temp;
			break;
		}
		ptr = ptr->next;
	}
	return head;
}

LinkedList* LinkedListRemoveHead(LinkedList* head)
{
	return LinkedListRemoveElement(head, head);
}

LinkedList* LinkedListRemoveElement(LinkedList* head, LinkedList* element)
{
	if (!head || !element) return head;

	LinkedList* ptr = head;
	if (element == head)
	{
		ptr = ptr->next;
		free(element);
		return ptr;
	}

	while (1)
	{
		if (ptr->next == element)
		{
			ptr->next = element->next;
			free(element);
			return head;
		}
		ptr = ptr->next;
		if (!ptr) return head;
	}
}

LinkedList* LinkedListRemovePosition(LinkedList* head, size_t position)
{
	if (!head) return NULL;
	if (position == 0) return LinkedListRemoveHead(head);
	
	size_t counter = 1;
	LinkedList* ptr = head;
	while (ptr->next)
	{
		if (counter == position)
		{
			LinkedList* temp = ptr->next;
			ptr->next = temp->next;
			free(temp);
			return head;
		}
		++counter;
		ptr = ptr->next;
	}
	return head;
}

LinkedList* LinkedListRemoveTail(LinkedList* head)
{
	if (!head) return head;
	if (!head->next)
	{
		free(head);
		return NULL;
	}
	LinkedList* ptr = head;
	while (1)
	{
		if (!ptr->next->next)
		{
			free(ptr->next);
			ptr->next = NULL;
			return head;
		}
		ptr = ptr->next;
	}
}

LinkedList* LinkedListEmpty(LinkedList* head)
{
	if (!head) return NULL;
	LinkedList* ptr = head->next;
	while (ptr)
	{
		free(head);
		head = ptr;
		ptr = ptr->next;
	}
	free(head);
	return NULL;
}

int LinkedListIsEmpty(LinkedList* head)
{
	if (head) return 0;
	return 1;
}

size_t LinkedListGetSize(LinkedList* head)
{
	size_t size = 0;
	while (head)
	{
		head = head->next;
		++size;
	}
	return size;
}

LinkedList* LinkedListFindKey(LinkedList* head, int key)
{
	while (head)
	{
		if (head->data == key) return head;
		head = head->next;
	}
	return head;
}

LinkedList* LinkedListFindTail(LinkedList* head)
{
	if (!head) return head;
	while (1)
	{
		if (!head->next) return head;
		head = head->next;
	}
}

LinkedList* LinkedListRevers(LinkedList* head)
{
	if (!head) return head;
	LinkedList* ptr1, * ptr2;
	ptr1 = NULL;
	ptr2 = head;
	while (ptr2)
	{
		head = head->next;
		ptr2->next = ptr1;
		ptr1 = ptr2;
		ptr2 = head;
	}
	return ptr1;
}
