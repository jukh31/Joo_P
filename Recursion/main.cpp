#include <iostream>
#include <stdlib.h>
using namespace std;

int Factorial(int n)
{
	if (n == 1)
		return 1;
	else
		return Factorial(n - 1) * n;
}

int main()
{
	// 1! = 1
	// 2! = 1! * 2
	// 3! = 2! * 3
	// 4! = 3! * 4
	// n! = (n-1)! * n

	return 0;
}
