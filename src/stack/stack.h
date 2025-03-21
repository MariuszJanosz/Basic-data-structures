#ifndef STACK_H
#define STACK_H

#include <stddef.h>

#include "../linked_lists/linked_list/linked_list.h"

typedef struct Stack
{
	LinkedList* top;
}Stack;

void StackInitialize(Stack* stack);

void StackPush(Stack* stack, int data);
int StackPeek(Stack* stack);
int StackPop(Stack* stack);

void StackEmpty(Stack* stack);

int StackIsEmpty(Stack* stack);
size_t StackGetSize(Stack* stack);

void StackPrint(Stack* stack);

#endif
