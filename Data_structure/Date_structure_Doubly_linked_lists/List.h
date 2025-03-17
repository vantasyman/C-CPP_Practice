#define _CRT_SECURE_NO_WARNINGS 1
#define LTDatatype int
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
//结构复杂，但使用简单
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDatatype data;
}ListNode;
void ListPushBack(ListNode* phead, LTDatatype a);
void ListIni(ListNode** pphead);
void ListPopback(ListNode* phead);
void Listprint(ListNode* phead);
void ListPushfront(ListNode* phead, LTDatatype a);
void ListPopfront(ListNode* phead);
void ListErase(ListNode* pos);//将pos删除
void ListInsert(ListNode* pos, LTDatatype a);//在pos前面插入
ListNode* ListFind(ListNode* phead, LTDatatype a);
