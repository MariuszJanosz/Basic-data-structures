#include <stdlib.h>
#include <stdio.h>

#include "linked_list.h"
#include "doubly_linked_list.h"
#include "circular_linked_list.h"

int main(int argc, char** argv)
{
	LinkedList *head=NULL;

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

	return 0;
}