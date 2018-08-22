#pragma once
#include "LinkedList.h"

typedef struct
{
	LinkedList* List;
	int Count;
}ListQueue;

ListQueue* LQ_Create();
void LQ_Destroy(ListQueue* queue);
int LQ_Count(ListQueue* queue);
void LQ_Enqueue(ListQueue* queue, short value);
short LQ_Dequeue(ListQueue* queue);
