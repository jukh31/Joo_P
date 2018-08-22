#include <stdlib.h>
#include "ListStack.h"

ListStack* LS_Create()
{
	ListStack* stack = malloc(sizeof(ListStack));

	stack->Count = 0;
	stack->List = LL_Create();

	return stack;
}

void LS_Destroy(ListStack* stack)
{
	LL_Destroy(stack->List);

	free(stack);
}

void LS_Push(ListStack* stack, short value)
{
	stack->Count++;
	LL_AddFront(stack->List, value);
}

short LS_Pop(ListStack* stack)
{
	stack->Count--;
	return LL_RemoveFront(stack->List);
}

int LS_Count(ListStack* stack)
{
	return stack->Count;
}
