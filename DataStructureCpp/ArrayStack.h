#pragma once
#include "Vector.h"
#include "Stack.h"

class ArrayStack : public Stack
{
private:
	Vector* _array;
	int _position;

public:
	ArrayStack();
	~ArrayStack();
	void Push(short value);
	short Pop();
	int Count();
};

