#include <stdlib.h>
#include <stdio.h>

#include "stack.h"
#include "../linked_lists/linked_list/linked_list.h"

void StackInitialize(Stack* stack)
{
	stack->top = NULL;
}

void StackPush(Stack* stack, int data)
{
	stack->top = LinkedListInsertAtBeginning(stack->top, data);
}

int StackPeek(Stack* stack)
{
	return stack->top->data;
}

int StackPop(Stack* stack)
{
	int result = StackPeek(stack);
	stack->top = LinkedListRemoveHead(stack->top);
	return result;
}

void StackEmpty(Stack* stack)
{
	stack->top = LinkedListEmpty(stack->top);
}

int StackIsEmpty(Stack* stack)
{
	return LinkedListIsEmpty(stack->top);
}

size_t StackGetSize(Stack* stack)
{
	return LinkedListGetSize(stack->top);
}

void StackPrint(Stack* stack)
{
	LinkedList* temp=stack->top;
	while (temp)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}