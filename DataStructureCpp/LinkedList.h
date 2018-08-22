#pragma once
#include "main.h"

struct Node
{
	short Value;
	Node* Previous;
	Node* Next;
};

class LinkedList
{
private:
	Node* _head;
	Node* _tail;
	short RemoveCore(Node* node);
	Node* Find_Node(short value);

public:
	LinkedList();
	~LinkedList();
	void Add(short value);
	void AddFront(short value);
	void AddBack(short value);
	void Iterate(void(*pf)(short));
	void Remove(short value);
	short RemoveFront();
	short RemoveBack();
	boolean Contains(short value);
	int Count();
	int Count(boolean(*fp)(short));
} ;

