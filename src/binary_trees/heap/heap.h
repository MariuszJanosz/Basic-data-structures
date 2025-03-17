#ifndef HEAP_H
#define HEAP_H

#include <stddef.h>

#define DEFAULT_HEAP_CAPACITY (1<<10)-1 //2^10-1=1023

typedef struct Heap
{
	size_t capacity; //Heap capacity has to be of a form 2^n-1 for natural a number n >=1.
	size_t size;
	int* data;
}Heap;

void HeapInitialize(Heap* heap, size_t capacity);

void HeapHeapify(Heap* heap, size_t index);

void HeapInsert(Heap* heap, int data);
void HeapModify(Heap* heap, size_t index, int new_data);
void HeapBuild(Heap* heap, int* array, size_t array_size);

int HeapDeleteMax(Heap* heap);
int HeapDelete(Heap* heap, size_t index);
void HeapEmpty(Heap* heap);

int HeapGetMax(Heap* heap);
int HeapIsEmpty(Heap* heap);

void HeapDestroy(Heap* heap);

void HeapPrint(Heap* heap);

#endif