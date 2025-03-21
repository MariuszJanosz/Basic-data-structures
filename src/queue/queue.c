#include <stdlib.h>
#include <stdio.h>

#include "queue.h"
#include "../linked_lists/linked_list/linked_list.h"

void QueueInitialize(Queue* queue)
{
	queue->head = NULL;
	queue->tail = NULL;
}

void QueueEnqueue(Queue* queue, int data)
{
	if (queue->head == NULL)
	{
		queue->head = LinkedListInsertAtBeginning(queue->head, data);
		queue->tail = queue->head;
	}
	else
	{
		queue->head = LinkedListInsertAfterElement(queue->head, data, queue->tail);
		queue->tail = queue->tail->next;
	}
}

int QueuePeek(Queue* queue)
{
	return queue->head->data;
}

int QueueDequeue(Queue* queue)
{
	int result = queue->head->data;
	queue->head = LinkedListRemoveHead(queue->head);
	if (queue->head == NULL) queue->tail = NULL;
	return result;
}

void QueueEmpty(Queue* queue)
{
	queue->head = LinkedListEmpty(queue->head);
	queue->tail = NULL;
}

int QueueIsEmpty(Queue* queue)
{
	if (queue->head) return 0;
	return 1;
}

void QueuePrint(Queue* queue)
{
	LinkedListPrint(queue->head);
}
