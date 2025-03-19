#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stddef.h>

typedef struct DynamicArray
{
	size_t capacity;
	size_t size;
	int* data;
}DynamicArray;

void DynamicArrayInitialize(DynamicArray* array, size_t initial_capacity);

void DynamicArrayResize(DynamicArray* array, size_t new_capacity);

void DynamicArrayPush(DynamicArray* array, int data);

int DynamicArrayRemoveElement(DynamicArray* array, size_t index);
void DynamicArrayEmpty(DynamicArray* array);

size_t DynamicArrayGetCapacity(DynamicArray* array);
size_t DynamicArrayGetSize(DynamicArray* array);

void DynamicArrayDestroy(DynamicArray* array);

void DynamicarrayPrint(DynamicArray* array);

#endif