#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct LinkedList
{
	int data;
	struct LinkedList* next;
} LinkedList;

void LinkedListPrint(LinkedList* head);

LinkedList* LinkedListInsertAtBeginning(LinkedList *head, int data);
LinkedList* LinkedListInsertAtPosition(LinkedList* head, int data, size_t position);
LinkedList* LinkedListInsertAtEnd(LinkedList* head, int data);

LinkedList* LinkedListRemoveHead(LinkedList* head);
LinkedList* LinkedListRemoveElement(LinkedList* head, LinkedList* element);
LinkedList* LinkedListRemovePosition(LinkedList* head, size_t position);
LinkedList* LinkedListRemoveTail(LinkedList* head);

LinkedList* LinkedListEmpty(LinkedList* head);

int LinkedListIsEmpty(LinkedList* head);
size_t LinkedListGetSize(LinkedList* head);

LinkedList* LinkedListFindKey(LinkedList* head, int key);
LinkedList* LinkedListFindTail(LinkedList* head);

LinkedList* LinkedListRevers(LinkedList* head);

#endif