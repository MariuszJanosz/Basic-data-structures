#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stddef.h>

typedef struct DoublyLinkedList
{
	int data;
	struct DoublyLinkedList* next, *previous;
} DoublyLinkedList;

void DoublyLinkedListPrint(DoublyLinkedList* head);

DoublyLinkedList* DoublyLinkedListInsertAtBeginning(DoublyLinkedList* head, int data);
DoublyLinkedList* DoublyLinkedListInsertAtPosition(DoublyLinkedList* head, int data, size_t position);
DoublyLinkedList* DoublyLinkedListInsertAtEnd(DoublyLinkedList* head, int data);

DoublyLinkedList* DoublyLinkedListRemoveHead(DoublyLinkedList* head);
DoublyLinkedList* DoublyLinkedListRemoveElement(DoublyLinkedList* head, DoublyLinkedList* element);
DoublyLinkedList* DoublyLinkedListRemovePosition(DoublyLinkedList* head, size_t position);
DoublyLinkedList* DoublyLinkedListRemoveTail(DoublyLinkedList* head);

DoublyLinkedList* DoublyLinkedListEmpty(DoublyLinkedList* head);

int DoublyLinkedListIsEmpty(DoublyLinkedList* head);
size_t DoublyLinkedListGetSize(DoublyLinkedList* head);

DoublyLinkedList* DoublyLinkedListFindKey(DoublyLinkedList* head, int key);
DoublyLinkedList* DoublyLinkedListFindTail(DoublyLinkedList* head);

DoublyLinkedList* DoublyLinkedListRevers(DoublyLinkedList* head);

#endif