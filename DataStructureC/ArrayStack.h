#pragma once
#include "Vector.h"

typedef struct
{
	Vector* Array;
	int Position;
}ArrayStack;

ArrayStack* AS_Create();
void AS_Destroy(ArrayStack* stack);
void AS_Push(ArrayStack* stack, short value);
short AS_Pop(ArrayStack* stack);
int AS_Count(ArrayStack* stack);
