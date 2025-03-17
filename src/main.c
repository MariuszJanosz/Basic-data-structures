#include <stdlib.h>
#include <stdio.h>

#include "linked_lists/linked_list/linked_list.h"
#include "linked_lists/doubly_linked_list/doubly_linked_list.h"
#include "linked_lists/circular_linked_list/circular_linked_list.h"
#include "stack/stack.h"
#include "queue/queue.h"
#include "hash_table/hash_table.h"
#include "binary_trees/binary_tree/binary_tree.h"
#include "binary_trees/heap/heap.h"

int main(int argc, char** argv)
{
	printf("<Linked list>\n");
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
		LinkedListEmpty(head);
	}
	printf("<Doubly linked list>\n");
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
		DoublyLinkedListEmpty(head);
	}
	printf("<Circular linked list>\n");
	{
		CircularLinkedList* head = NULL;
	
		head = CircularLinkedListInsertAtBeginning(head, 1);
		head = CircularLinkedListInsertAtBeginning(head, 2);
		head = CircularLinkedListInsertAtBeginning(head, 3);
		head = CircularLinkedListInsertAtPosition(head, 5, 1);
		head = CircularLinkedListInsertAtEnd(head, 10);
	
		CircularLinkedListPrint(head);
		CircularLinkedListEmpty(head);
	}
	printf("<Stack>\n");
	{
		Stack stack;
		StackInitialize(&stack);
	
		StackPush(&stack, 1);
		StackPush(&stack, 2);
		StackPush(&stack, 3);
		StackPush(&stack, 4);
	
		StackPrint(&stack);
		printf("Size of a stack: %llu\n", StackGetSize(&stack));
		StackEmpty(&stack);
	}
	printf("<Queue>\n");
	{
		Queue queue;
		QueueInitialize(&queue);
	
		QueueEnqueue(&queue, 1);
		QueueEnqueue(&queue, 2);
		QueueEnqueue(&queue, 3);
		QueueEnqueue(&queue, 4);
		QueueEnqueue(&queue, 5);
		QueueEnqueue(&queue, 6);
	
		QueuePrint(&queue);
		QueueEmpty(&queue);
	}
	printf("<Hash table>\n");
	{
		HashTable hashtable;
		HashTableInitialize(&hashtable, 8);

		HashTableInsert(&hashtable, 16);
		HashTableInsert(&hashtable, 2142);
		HashTableInsert(&hashtable, 3854);
		HashTableInsert(&hashtable, 54763);
		HashTableInsert(&hashtable, 54763);
		HashTableInsert(&hashtable, 9353);
		HashTableInsert(&hashtable, 223);
		HashTableDelet(&hashtable, 16);
		HashTableDelet(&hashtable, 9);

		HashTablePrint(&hashtable);

		int i = HashTableIsPresent(&hashtable, 54763);
		if (i)
		{
			printf("54763 is present in the hash table.\n");
		}
		else
		{
			printf("54763 is not present in the hash table.\n");
		}
		i = HashTableIsPresent(&hashtable, -8);
		if (i)
		{
			printf("-8 is present in the hash table.\n");
		}
		else
		{
			printf("-8 is not present in the hash table.\n");
		}

		printf("Emptied hash table.\n");
		HashTableEmpty(&hashtable);
		HashTablePrint(&hashtable);

		HashTableFree(&hashtable);
	}
	printf("<Binary tree>\n");
	{
		BinaryTree* root = NULL;

		root = BinaryTreeInsert(root, 1);
		root = BinaryTreeInsert(root, 2);
		root = BinaryTreeInsert(root, 3);
		root = BinaryTreeInsert(root, 4);
		root = BinaryTreeInsert(root, 5);
		root = BinaryTreeInsert(root, 6);

		BinaryTreePrint(root);
		printf("\n");

		root = BinaryTreeDelete(root, BinaryTreeFind(root, 2));
		BinaryTreePrint(root);
		printf("\n");
		
		root = BinaryTreeEmpty(root);
		BinaryTreePrint(root);
		printf("\n");
	}
	printf("<Heap>\n");
	{
		Heap heap;
		HeapInitialize(&heap, 0);

		HeapInsert(&heap, 1);
		HeapPrint(&heap);
		HeapInsert(&heap, 2);
		HeapPrint(&heap);
		HeapInsert(&heap, 3);
		HeapPrint(&heap);
		HeapInsert(&heap, 4);

		HeapPrint(&heap);
	}
	return 0;
}