#include <stdlib.h>
#include "ArrayStack.h"
#include "Vector.h"

ArrayStack* AS_Create()
{
	ArrayStack* stack = malloc(sizeof(ArrayStack));

	stack->Position = -1;
	stack->Array = VT_Create(2);

	return stack;
}

void AS_Destroy(ArrayStack* stack)
{
	VT_Destroy(stack->Array);

	free(stack);
}

void AS_Push(ArrayStack* stack, short value)
{
	if (stack->Position == VT_Count(stack->Array) - 1)
		VT_Resize(stack->Array, VT_Count(stack->Array) * 2);

	stack->Position++;
	VT_Set(stack->Array, stack->Position, value);
}

short AS_Pop(ArrayStack* stack)
{
	short value = VT_Get(stack->Array, stack->Position);

	stack->Position--;

	return value;
}

int AS_Count(ArrayStack* stack)
{
	return stack->Position + 1;
}
