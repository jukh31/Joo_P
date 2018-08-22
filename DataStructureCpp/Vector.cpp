#include "Vector.h"
#include <stdlib.h>

Vector::Vector(int size) // 기본 매개변수
{
	_size = size;
	_array = new short[size];
}

Vector::~Vector()
{
	delete[] _array;
}

void Vector::Set(int index, short value)
{
	// VT_Set(v, 1, 5);
	_array[index] = value;
}

void Vector::Resize(int size)
{
	short* ar = new short[size];

	for (int i = 0; i < _size; i++)
		ar[i] = _array[i];

	delete[] _array;

	_array = ar;
	_size = size;
}

void Vector::Iterate(void(*func)(short))
{
	for (int i = 0; i < _size; i++)
		func(_array[i]);
}

short Vector::Get(int index)
{
	return _array[index];
}

int Vector::Contains(short value)
{
	for (int i = 0; i < _size; i++)
		if (_array[i] == value)
			return 1;

	return 0;
}

int Vector::Count()
{
	return _size;
}

int Vector::Count(int(*func)(short))
{
	int count = 0;

	for (int i = 0; i < _size; i++)
		if (func(_array[i]) == 1)
			count++;

	return count;
}
