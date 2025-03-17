#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "sort.h"
//int main()
//{
//	int arr[] = {1,3,5,7,9,2,4,6,8,0};
//	//insertsort(arr, 10);
//	//selectsort(arr, 9);
//	int sz = sizeof(arr) / sizeof(arr[0])-1;
//	//my_qsort3(arr, 0, sz);
//	//bubblesort(arr, sz);
//	MergeSort(arr, sz);
//	for (int i = 0; i < sz+1; i++)
//	{
//		printf(" %d", arr[i]);
//	}
//	return 0;
//}


int main()
{
	FILE* p1 = fopen("test.sav1", "w");
	FILE* p2 = fopen("test.sav2", "w");
	if (p1 == NULL)
	{
		printf("can not open!!");
	}
	int arr[10] = { 0 };
	FILE* tmp = NULL;
	int a = 0;
	while (fscanf(p1, "%d\n", arr) != EOF);
	fclose(p1);
	return 0;
}