#pragma once
#include "LinkedList.h"

typedef struct
{
	LinkedList* List;
	int Count;
}ListStack;

ListStack* LS_Create();
void LS_Destroy(ListStack* stack);
void LS_Push(ListStack* stack, short value);
short LS_Pop(ListStack* stack);
int LS_Count(ListStack* stack);
