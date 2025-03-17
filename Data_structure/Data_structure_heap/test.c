#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"
//int main()
//{
//	int a[] = { 20,15,16,13,12,19 };
//	Heap HP;
//	HeapInit(&HP, a, sizeof(a)/sizeof(a[0]));
//	for (int i = 0; i < HP._size; i++)
//	{
//		printf("%d ", HP._a[i]);
//	}
//	printf("\n");
//	HeapPush(&HP, 22);
//	HeapPop(&HP);
//	for (int i = 0; i < HP._size; i++)
//	{
//		printf("%d ", HP._a[i]);
//	}
//	printf("\n");
//	HeapSort(a, sizeof(a) / sizeof(a[0]));
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{
//		printf("%d ", a[i]);
//	}
//	return 0;
//}

#include <stdio.h>
void re_def(int* p, int sz)
{
	int begin = 0;
	int move = 0;
	while (begin < sz)
	{
		move = begin + 1;
		while (move < sz)
		{
			if (p[begin] == p[move])
			{
				break;
			}
			move++;
		}
		if (p[begin] != p[move])
		{
			printf("%d ", p[begin]);
		}
		begin++;
	}
}

int main()
{
	int sz;
	scanf("%d", &sz);
	int* p = (int*)malloc(sz * sizeof(int));
	for (int count = 0; count < sz; count++)
	{
		scanf("%d", p + count);
	}
	re_def(p, sz);

	return 0;
}