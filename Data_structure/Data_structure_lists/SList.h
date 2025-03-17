#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
typedef int SListDataType;
typedef struct SListNode
{
	SListDataType data;
	struct SListNode* next;
}SListNode;
void SListPushBack(SListNode** pphead, SListDataType x);
void SListPopBack(SListNode** phead);
void SListPushFront(SListNode** phead, SListDataType x);
void SListPopFront(SListNode** phead);
void SListPrint(SListNode* phead);
void SListinsert(SListNode** pphead, int afterplace, SListDataType x);
void SListPopAfter(SListNode** pphead, int afterplace);