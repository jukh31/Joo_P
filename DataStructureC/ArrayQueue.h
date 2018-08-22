#pragma once

#include "Vector.h"

typedef struct
{
	Vector* Array;
	int E;
	int D;
}ArrayQueue;

ArrayQueue* AQ_Create();
void AQ_Destroy(ArrayQueue* queue);
int AQ_Count(ArrayQueue* queue);
void AQ_Enqueue(ArrayQueue* queue, short value);
short AQ_Dequeue(ArrayQueue* queue);