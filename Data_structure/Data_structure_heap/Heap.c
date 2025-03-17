#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"
//void Swap(HPDataType* p1, HPDataType* p2)
//{
//	HPDataType tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//void AdjustDown(HPDataType* a, int n,int root)
//{
//	//大堆
//	int parent = root;
//	int child = parent * 2 + 1;
//	while (child < n)
//	{
//		if (child+1<n&&a[child] > a[child + 1])//child+1>n,说明child+1越界了
//		{
//			child++;
//		}
//		if (a[parent] > a[child])
//		{
//			Swap(&a[parent], &a[child]);
//			parent = child;
//			child= parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//void HeapInit(Heap* php, HPDataType* a, int n)
//{
//	php->_a = (HPDataType*)malloc(sizeof(HPDataType));
//	memcpy(php->_a, a, sizeof(HPDataType) * n);
//	php->_size = n;
//	php->_capacity = n;
//	//构建堆 x
//	for (int i = (n - 1 - 1) / 2; i >= 0; i--)//找到最后一个叶子节点的爹
//	{
//		AdjustDown(php->_a,n,i);
//	}
//}
void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = 0;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void AdjustDown(HPDataType* a, int n, int root)//向下调整
{
	int parent = root;
	int child =  root * 2 + 1;
	while (child<n)
	{
		if ((child+1)<n&&*(a + child) < *(a + child + 1))//child+1<n防止溢出
		{
			child++;
		}
		if (*(a + child) > *(a + parent))
		{
			Swap(a + child, a + parent);
			parent = child;
			child = parent * 2 + 1;
			
		}
		else
		{
			break;
		}
	}
}
void AdjustUp(HPDataType* a,int begin)
{
	HPDataType child = begin-1;
	HPDataType parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[parent] < a[child])
		{
			Swap(a + parent, a + child);
			child=parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}

}
void HeapInit(Heap* php, HPDataType* a, int n)
{
	php->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	memcpy(php->_a, a, n*sizeof(HPDataType));
	php->_size = n;
	php->_capacity = n;
	int child_ini = (n - 1-1) / 2;
	while (child_ini>=0)
	{
		AdjustDown(php->_a, n, child_ini);
		child_ini--;
	}

}
void HeapSort(HPDataType* php, int n)
{
	int child_ini = (n - 1 - 1) / 2;
	while (child_ini >= 0)
	{
		AdjustDown(php, n, child_ini);
		child_ini--;
	}
	Swap(php, php + n-1);
	n--;
	for (;n>0;n--)
	{
		AdjustDown(php, n, 0);
		Swap(php, php + n - 1);
	}
}
void HeapDestory(Heap* php)
{
	free(php->_a);
	php->_capacity = 0;
	php->_size = 0;
}
void HeapPop(Heap* php)//删掉堆顶//把堆顶换到最下面，用堆排序思想,再来一次向下调整
{
	Swap(php->_a, php->_a + php->_size - 1);
	php->_size--;
	AdjustDown(php->_a, php->_size, 0);
}
void HeapPush(Heap* php, HPDataType x)
{
	if (php->_capacity <= php->_size)
	{
		php->_capacity *= 2;
		HPDataType* tmp = (HPDataType*)realloc(php->_a,sizeof(HPDataType) * php->_capacity);
		if (tmp == NULL)
		{
			perror("malloc");
			exit(-1);
		}
		php->_a = tmp;
	}
	php->_size++;
	*(php->_a + php->_size - 1) = x;
	AdjustUp(php->_a,  php->_size);
	
}