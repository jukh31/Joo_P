#pragma once

typedef int boolean;
#define TRUE 1
#define FALSE 0

typedef struct _Node
{
	short Value;
	struct _Node* Previous;
	struct _Node* Next;
}Node;

typedef struct 
{
	Node* Head;
	Node* Tail;
} LinkedList;

LinkedList* LL_Create();
void LL_Add(LinkedList* list, short value);
void LL_AddFront(LinkedList* list, short value);
void LL_AddBack(LinkedList* list, short value);
void LL_Iterate(LinkedList* list, void (*pf)(short));
short LL_RemoveCore(LinkedList* list, Node* node);
void LL_Remove(LinkedList* list, short value);
short LL_RemoveFront(LinkedList* list);
short LL_RemoveBack(LinkedList* list);
boolean LL_Contains(LinkedList* list, short value);
int LL_Count(LinkedList* list);
int LL_CountIf(LinkedList* list, boolean (*fp)(short));
void LL_Destroy(LinkedList* list);

Node* LL_Find_Node(LinkedList* list, short value);

short LL_GetFront(LinkedList* list, int index);
short LL_GetBack(LinkedList* list, int index);