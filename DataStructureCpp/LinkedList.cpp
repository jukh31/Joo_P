#include "LinkedList.h"
#include <stdlib.h>

LinkedList::LinkedList()
{
	_head = new Node;
	_tail = new Node;

	_head->Next = _tail;
	_tail->Previous = _head;
}

LinkedList::~LinkedList()
{
	delete _head;
	delete _tail;
}

void LinkedList::Add(short value)
{
	AddBack(value);
}

void LinkedList::AddFront(short value)
{
	Node* node = new Node;
	node->Value = value;

	node->Previous = _head;
	node->Next = _head->Next;

	_head->Next->Previous = node;
	_head->Next = node;
}

void LinkedList::AddBack(short value)
{
	Node* node = new Node;
	node->Value = value;

	node->Next = _tail;
	node->Previous = _tail->Previous;

	_tail->Previous->Next = node;
	_tail->Previous = node;
}

short LinkedList::RemoveCore(Node* node)
{
	node->Previous->Next = node->Next;
	node->Next->Previous = node->Previous;

	short value = node->Value;

	delete node;

	return value;
}

void LinkedList::Remove(short value)
{
	Node* node = Find_Node(value);

	if (node == _tail)
		return;

	RemoveCore(node);
}

short LinkedList::RemoveFront()
{
	Node* node = _head->Next;

	if (node == _tail)
		return 0;

	return RemoveCore(node);
}

short LinkedList::RemoveBack()
{
	Node* node = _tail->Previous;

	if (node == _head)
		return 0;

	return RemoveCore(node);
}

void LinkedList::Iterate(void(*pf)(short))
{
	Node* node = _head->Next;

	while (node != _tail)
	{
		pf(node->Value);

		node = node->Next;
	}
}

boolean LinkedList::Contains(short value)
{
	Node* node = Find_Node(value);

	return node == _tail ? FALSE : TRUE;
}

int LinkedList::Count()
{
	int count = 0;

	Node* node = _head->Next;

	while (node != _tail)
	{
		count++;

		node = node->Next;
	}

	return count;
}

int LinkedList::Count(boolean(*fp)(short))
{
	int count = 0;

	Node* node = _head->Next;

	while (node != _tail)
	{
		if (fp(node->Value) == TRUE)
			count++;

		node = node->Next;
	}

	return count;
}

Node* LinkedList::Find_Node(short value)
{
	Node* current = _head->Next;

	while (current != _tail)
	{
		if (current->Value == value)
			return current;

		current = current->Next;
	}

	return _tail;
}