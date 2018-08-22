#include "Vector.h"
#include <stdlib.h>

Vector* VT_Create(int size)
{
	Vector* v = malloc(sizeof(Vector));
	v->Size = size;
	v->Array = malloc(sizeof(short) * size);

	return v;
}

void VT_Set(Vector* v, int index, short value)
{
	// VT_Set(v, 1, 5);
	v->Array[index] = value;
}

void VT_Resize(Vector* v, int size)
{
	short* ar = malloc(sizeof(short) * size);

	for (int i = 0; i < v->Size; i++)
		ar[i] = v->Array[i];

	free(v->Array);

	v->Array = ar;
	v->Size = size;
}

void Iterate(Vector* v, void(*func)(short)) 
{
	for (int i = 0; i < v->Size; i++)
		func(v->Array[i]);
}

short VT_Get(Vector* v, int index)
{
	return v->Array[index];
}

int VT_Contains(Vector* v, short value)
{
	for (int i = 0; i < v->Size; i++)
		if (v->Array[i] == value)
			return 1;

	return 0;
}

int VT_Count(Vector* v)
{
	return v->Size;
}

int VT_CountIf(Vector* v, int(*func)(short))
{
	int count = 0;

	for (int i = 0; i < v->Size; i++)
		if (func(v->Array[i]) == 1)
			count++;

	return count;
}

void VT_Destroy(Vector* v)
{
	free(v->Array);
	free(v);
}
