#pragma once

typedef struct 
{
	int Size;
	short* Array;
}Vector;

Vector* VT_Create(int size);
void VT_Set(Vector* v, int index, short value);
void VT_Resize(Vector* v, int size);
void Iterate(Vector* v, void (*func)(short));
short VT_Get(Vector* v, int index);
int VT_Contains(Vector* v, short value);
int VT_Count(Vector* v);
int VT_CountIf(Vector* v, int (*func)(short));
void VT_Destroy(Vector* v);
