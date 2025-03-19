#include <stdlib.h>
#include <stdio.h>

#include "dynamic_array.h"

void DynamicArrayInitialize(DynamicArray* array, size_t initial_capacity)
{
	if (initial_capacity < 2) exit(1);
	array->capacity = initial_capacity;
	array->size = 0;
	array->data = malloc(initial_capacity * sizeof(int));
	if (!array->data) exit(1);
}

void DynamicArrayResize(DynamicArray* array, size_t new_capacity)
{
	if (new_capacity < array->size) exit(1);
	void* temp = realloc(array->data, new_capacity * sizeof(int));
	if (!temp) exit(1);
	array->data = (int*)temp;
	array->capacity = new_capacity;
}

void DynamicArrayPush(DynamicArray* array, int data)
{
	if (array->size == array->capacity) DynamicArrayResize(array, array->capacity * 3 / 2);
	array->data[array->size] = data;
	++array->size;
}

int DynamicArrayRemoveElement(DynamicArray* array, size_t index)
{
	if (index >= array->size) exit(1);
	int tobereturned = array->data[index];

	for (size_t i = index; i < array->size-1; ++i)
	{
		array->data[index] = array->data[index + 1];
	}
	--array->size;

	return tobereturned;
}

void DynamicArrayEmpty(DynamicArray* array)
{
	array->size = 0;
}

size_t DynamicArrayGetCapacity(DynamicArray* array)
{
	return array->capacity;
}

size_t DynamicArrayGetSize(DynamicArray* array)
{
	return array->size;
}

void DynamicArrayDestroy(DynamicArray* array)
{
	free(array->data);
}

void DynamicarrayPrint(DynamicArray* array)
{
	for (size_t i = 0; i < array->size; ++i)
	{
		printf("%d ", array->data[i]);
	}
}
