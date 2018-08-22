#include <stdlib.h>
#include "ArrayStack.h"
#include "Vector.h"

ArrayStack::ArrayStack()
{
	_position = -1;
	_array = new Vector(2);
}

ArrayStack::~ArrayStack()
{
	delete _array;
}

void ArrayStack::Push(short value)
{
	if (_position == _array->Count() - 1)
		_array->Resize(_array->Count() * 2);

	_position++;
	_array->Set(_position, value);
}

short ArrayStack::Pop()
{
	short value = _array->Get(_position);

	_position--;

	return value;
}

int ArrayStack::Count()
{
	return _position + 1;
}
