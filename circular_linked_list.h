#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include <stddef.h>

typedef struct CircularLinkedList
{
	int data;
	struct CircularLinkedList* next;
} CircularLinkedList;

void CircularLinkedListPrint(CircularLinkedList* head);

CircularLinkedList* CircularLinkedListInsertAtBeginning(CircularLinkedList* head, int data);
CircularLinkedList* CircularLinkedListInsertAtPosition(CircularLinkedList* head, int data, size_t position);
CircularLinkedList* CircularLinkedListInsertAtEnd(CircularLinkedList* head, int data);

CircularLinkedList* CircularLinkedListRemoveHead(CircularLinkedList* head);
CircularLinkedList* CircularLinkedListRemoveElement(CircularLinkedList* head, CircularLinkedList* element);
CircularLinkedList* CircularLinkedListRemovePosition(CircularLinkedList* head, size_t position);
CircularLinkedList* CircularLinkedListRemoveTail(CircularLinkedList* head);

CircularLinkedList* CircularLinkedListEmpty(CircularLinkedList* head);

int CircularLinkedListIsEmpty(CircularLinkedList* head);
size_t CircularLinkedListGetSize(CircularLinkedList* head);

CircularLinkedList* CircularLinkedListFindKey(CircularLinkedList* head, int key);
CircularLinkedList* CircularLinkedListFindTail(CircularLinkedList* head);

CircularLinkedList* CircularLinkedListRevers(CircularLinkedList* head);

#endif