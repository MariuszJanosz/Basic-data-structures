#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

void HeapModify(Heap* heap, size_t index, int new_data)
{
	if (index > heap->size - 1) exit(1);
	if (heap->data[index] > new_data)
	{
		heap->data[index] = new_data;
		HeapHeapify(heap, index);
	}
	else
	{
		heap->data[index] = new_data;
		while (index)
		{
			index = (index - 1) / 2;
			HeapHeapify(heap, index);
		}
	}
}

void HeapBuild(Heap* heap, int* array, size_t array_size)
{
	if (array_size == 0) exit(1);
	if (array_size > heap->capacity) exit(1);
	memcpy(heap->data, array, array_size * sizeof(int));
	heap->size = array_size;
	for (size_t i = (heap->size - 1) / 2; i > 0; --i)
	{
		HeapHeapify(heap, i);
	}
	HeapHeapify(heap, 0);
}

int HeapDeleteMax(Heap* heap)
{
	return HeapDelete(heap, 0);
}

int HeapDelete(Heap* heap, size_t index)
{
	if (index > heap->size - 1) exit(1);
	if (index == heap->size - 1)
	{
		--heap->size;
		return heap->data[index];
	}
	int temp = heap->data[index];
	--heap->size;
	heap->data[index] = heap->data[heap->size];
	HeapHeapify(heap, index);
	return temp;
}

void HeapEmpty(Heap* heap)
{
	while (heap->size)
	{
		HeapDelete(heap, heap->size - 1);
	}
}

int HeapGetMax(Heap* heap)
{
	return heap->data[0];
}

int HeapIsEmpty(Heap* heap)
{
	if (heap->size == 0) return 1;
	return 0;
}

void HeapDestroy(Heap* heap)
{
	free(heap->data);
}

void HeapPrint(Heap* heap)
{
	for (int i = 0; i < heap->size; ++i)
	{
		printf("%d ", heap->data[i]);
	}
	printf("\n");
}
