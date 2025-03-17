#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
int main()
{

	int* a = new int[10];
	delete[] a;
	return 0;
}