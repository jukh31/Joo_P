#include <stdlib.h>
#include "main.h"
#include "ListStack.h"
#include "LinkedList.h"

ListStack::ListStack()
{
	_list = new LinkedList();
	_count = 0;
}

ListStack::~ListStack()
{
	delete _list;
}

void ListStack::Push(short value)
{
	_count++;
	_list->AddFront(value);
}

short ListStack::Pop()
{
	_count--;
	return _list->RemoveFront();
}

int ListStack::Count()
{
	return _list->Count();
}
