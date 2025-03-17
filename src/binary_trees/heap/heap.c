#include <stdlib.h>
#include <stdio.h>

#include "heap.h"

void HeapInitialize(Heap* heap, size_t capacity)
{
	if (capacity == 0) capacity = DEFAULT_HEAP_CAPACITY;
	heap->size = 0;
	heap->capacity = 1;
	while (heap->capacity < capacity) heap->capacity = (heap->capacity << 1) + 1;
	heap->data = (int*)malloc(heap->capacity * sizeof(int));
}

void HeapHeapify(Heap* heap, size_t index)
{
	size_t biggest = index;
	if (2 * index + 1 < heap->size)
	{
		if (heap->data[2 * index + 1] > heap->data[index])
		{
			biggest = 2 * index + 1;
		}
	}
	if (2 * index + 2 < heap->size)
	{
		if (heap->data[2 * index + 2] > heap->data[biggest])
		{
			biggest = 2 * index + 2;
		}
	}
	if (biggest == index) return;
	int temp = heap->data[biggest];
	heap->data[biggest] = heap->data[index];
	heap->data[index] = temp;
	HeapHeapify(heap, biggest);
}

void HeapInsert(Heap* heap, int data)
{
	if (heap->size == heap->capacity) exit(1);
	heap->data[heap->size] = data;
	if (heap->size == 0)
	{
		++heap->size;
		return;
	}
	size_t index = (heap->size - 1) / 2;
	++heap->size;
	while (index)
	{
		HeapHeapify(heap, index);
		index = (index - 1) / 2;
	}
	HeapHeapify(heap, 0);
}

void HeapPrint(Heap* heap)
{
	for (int i = 0; i < heap->size; ++i)
	{
		printf("%d ", heap->data[i]);
	}
	printf("\n");
}
