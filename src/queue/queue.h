#ifndef QUEUE_H
#define QUEUE_H

#include "../linked_lists/linked_list/linked_list.h"

typedef struct Queue
{
	LinkedList* head;
	LinkedList* tail;
}Queue;

void QueueInitialize(Queue* queue);

void QueueEnqueue(Queue* queue, int data);

int QueuePeek(Queue* queue);

int QueueDequeue(Queue* queue);
void QueueEmpty(Queue* queue);

int QueueIsEmpty(Queue* queue);

void QueuePrint(Queue* queue);

#endif
