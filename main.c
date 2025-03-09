#include <stdlib.h>
#include <stdio.h>

#include "linked_list.h"
#include "doubly_linked_list.h"
#include "circular_linked_list.h"

int main(int argc, char** argv)
{
	{
		LinkedList* head = NULL;

		head = LinkedListInsertAtBeginning(head, 1);
		head = LinkedListInsertAtBeginning(head, 2);
		head = LinkedListInsertAtBeginning(head, 3);
		head = LinkedListInsertAtBeginning(head, 4);
		head = LinkedListInsertAtEnd(head, 7);
		head = LinkedListInsertAtPosition(head, 10, 60);

		LinkedList* tmp = LinkedListFindTail(head);
		head = LinkedListRemoveElement(head, tmp);
		head = LinkedListRemoveHead(head);
		head = LinkedListRemovePosition(head, 3);

		head = LinkedListRevers(head);

		LinkedListPrint(head);
	}
	printf("<================================================>\n");
	{
		DoublyLinkedList* head = NULL;

		head = DoublyLinkedListInsertAtBeginning(head, 1);
		head = DoublyLinkedListInsertAtBeginning(head, 2);
		head = DoublyLinkedListInsertAtBeginning(head, 3);
		head = DoublyLinkedListInsertAtBeginning(head, 4);
		head = DoublyLinkedListInsertAtBeginning(head, 5);
		head = DoublyLinkedListInsertAtPosition(head, 10, 3);
		head = DoublyLinkedListInsertAtEnd(head, 7);

		head = DoublyLinkedListRemoveHead(head);
		head = DoublyLinkedListRemoveElement(head, head->next);
		head = DoublyLinkedListRemovePosition(head, 1);
		head = DoublyLinkedListRemoveTail(head);

		head = DoublyLinkedListRevers(head);

		DoublyLinkedListPrint(head);
	}
	return 0;
}