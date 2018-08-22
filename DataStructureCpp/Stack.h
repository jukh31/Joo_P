#pragma once

class Stack
{
public:
	virtual ~Stack();

	virtual void Push(short value) = 0;
	virtual short Pop() = 0;
	virtual int Count() = 0;
};
