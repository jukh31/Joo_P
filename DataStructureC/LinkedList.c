#include "LinkedList.h"
#include <stdlib.h>

LinkedList* LL_Create()
{
	LinkedList* list = malloc(sizeof(LinkedList));

	list->Head = malloc(sizeof(Node));
	list->Tail = malloc(sizeof(Node));

	list->Head->Next = list->Tail;
	list->Tail->Previous = list->Head;

	return list;
}

void LL_Add(LinkedList* list, short value)
{
	LL_AddBack(list, value);
}

void LL_AddFront(LinkedList* list, short value)
{
	Node* node = malloc(sizeof(Node));
	node->Value = value;

	node->Previous = list->Head;
	node->Next = list->Head->Next;

	list->Head->Next->Previous = node;
	list->Head->Next = node;
}

void LL_AddBack(LinkedList* list, short value)
{
	Node* node = malloc(sizeof(Node));
	node->Value = value;

	node->Next = list->Tail;
	node->Previous = list->Tail->Previous;

	list->Tail->Previous->Next = node;
	list->Tail->Previous = node;
}

short LL_RemoveCore(LinkedList* list, Node* node)
{
	node->Previous->Next = node->Next;
	node->Next->Previous = node->Previous;

	short value = node->Value;

	free(node);

	return value;
}

void LL_Remove(LinkedList* list, short value)
{
	Node* node = LL_Find_Node(list, value);

	if (node == list->Tail)
		return;

	LL_RemoveCore(list, node);
}

short LL_RemoveFront(LinkedList* list)
{
	Node* node = list->Head->Next;

	if (node == list->Tail)
		return 0;

	return LL_RemoveCore(list, node);
}

short LL_RemoveBack(LinkedList* list)
{
	Node* node = list->Tail->Previous;

	if (node == list->Head)
		return 0;

	return LL_RemoveCore(list, node);
}

void LL_Iterate(LinkedList* list, void(*pf)(short))
{
	Node* node = list->Head->Next;

	while (node != list->Tail)
	{
		pf(node->Value);

		node = node->Next;
	}
}

boolean LL_Contains(LinkedList* list, short value)
{
	Node* node = LL_Find_Node(list, value);

	return node == list->Tail ? FALSE : TRUE;
}

int LL_Count(LinkedList* list)
{
	int count = 0;

	Node* node = list->Head->Next;

	while (node != list->Tail)
	{
		count++;

		node = node->Next;
	}

	return count;
}

int LL_CountIf(LinkedList* list, boolean(*fp)(short))
{
	int count = 0;

	Node* node = list->Head->Next;

	while (node != list->Tail)
	{
		if (fp(node->Value) == TRUE)
			count++;

		node = node->Next;
	}

	return count;
}

void LL_Destroy(LinkedList* list)
{
	free(list->Head);
	free(list->Tail);
	free(list);
}

Node* LL_Find_Node(LinkedList* list, short value)
{
	Node* current = list->Head->Next;

	while (current != list->Tail)
	{
		if (current->Value == value)
			return current;

		current = current->Next;
	}

	return list->Tail;
}

short LL_GetFront(LinkedList* list, int index)
{
	Node* node = list->Head->Next;

	while (node != list->Tail)
	{
		index--;

		if (index == -1)
			return node->Value;

		node = node->Next;
	}

	return 0;
}

short LL_GetBack(LinkedList* list, int index)
{
	return 0;
}