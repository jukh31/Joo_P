#pragma once
#include "LinkedList.h"
#include "Stack.h"

class ListStack : public Stack
{
private:
	LinkedList * _list;
	int _count;

public:
	ListStack();
	~ListStack();
	void Push(short value);
	short Pop();
	int Count();
};