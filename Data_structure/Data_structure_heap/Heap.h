#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#define HPDataType int
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;
void HeapSort(HPDataType* php, int n);
void Swap(HPDataType* p1, HPDataType* p2);
void HeapInit(Heap* php, HPDataType* a,int n);
void HeapDestory(Heap* php);
void HeapPop(Heap* php);
void HeapPush(Heap* php, HPDataType x);