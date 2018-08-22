#pragma once
#include "ArrayQueue.h"
#include "Vector.h"
#include <stdlib.h>

ArrayQueue* AQ_Create() 
{
	ArrayQueue* queue = malloc(sizeof(ArrayQueue));
	
	queue->Array = VT_Create(2);
	queue->E = 0;
	queue->D = 0;

	return queue;
}

void AQ_Destroy(ArrayQueue* queue)
{
	VT_Destroy(queue->Array);
	free(queue);
}

int AQ_Count(ArrayQueue* queue)
{
	return queue->E - queue->D;
}

void AQ_Enqueue(ArrayQueue* queue, short value)
{
	if (queue->E == VT_Count(queue->Array))
		VT_Resize(queue->Array, VT_Count(queue->Array) * 2);

	VT_Set(queue->Array, queue->E, value);
	queue->E++;
}

short AQ_Dequeue(ArrayQueue* queue)
{
	short value = VT_Get(queue->Array, queue->D);
	queue->D++;

	return value;
}