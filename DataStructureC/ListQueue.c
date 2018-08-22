#include "ListQueue.h"
#include "LinkedList.h"
#include <stdlib.h>

ListQueue* LQ_Create()
{
	ListQueue* queue = malloc(sizeof(ListQueue));
	queue->List = LL_Create();
	queue->Count = 0;

	return queue;
}

void LQ_Destroy(ListQueue* queue)
{
	LL_Destroy(queue->List);
	free(queue);
}

int LQ_Count(ListQueue* queue)
{
	//return queue->Count;
	return (*queue).Count;
}

void LQ_Enqueue(ListQueue* queue, short value)
{
	LL_AddFront(queue->List, value);
	queue->Count++;
}

short LQ_Dequeue(ListQueue* queue)
{
	queue->Count--;
	return LL_RemoveBack(queue->List);
}
