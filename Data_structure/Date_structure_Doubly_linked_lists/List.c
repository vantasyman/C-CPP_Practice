#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"
void ListIni(ListNode** pphead)//初始化的时候，会重置指针的值，所以要传二级指针。
{
	*pphead = (ListNode*)malloc(sizeof(ListNode));
	if (pphead == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	(*pphead)->next = *pphead;
	(*pphead)->prev = *pphead;
}
void ListPushBack(ListNode* phead, LTDatatype a)
{
	assert(phead);
	ListNode* back = (ListNode*)malloc(sizeof(ListNode));
	if (back == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	ListNode* tmp_back = phead->prev;
	tmp_back->next = back;
	phead->prev = back;
	back->next = phead;
	back->prev = tmp_back;//链接
	back->data = a;//赋值
}
void Listprint(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur!=phead)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void ListPopback(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	ListNode* tmp_back = phead->prev;
	ListNode* tmp_back_prev = tmp_back->prev;
	phead->prev = tmp_back_prev;
	tmp_back_prev->next = phead;
	free(tmp_back);
}

void ListPushfront(ListNode* phead,LTDatatype a)
{
	ListNode* new_front = (ListNode*)malloc(sizeof(ListNode));
	if (!new_front)
	{
		perror("malloc");
		exit(-1);
	}
	ListNode* old_first = phead->next;
	phead->next = new_front;
	new_front->next = old_first;
	new_front->prev = phead;
	old_first->prev = new_front;
	new_front->data = a;
}

void ListPopfront(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	ListNode* Dalhead = phead->next;
	phead->next = Dalhead->next;
	Dalhead->next->prev = phead;
	free(Dalhead);
}

ListNode* ListFind(ListNode* phead, LTDatatype a)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == a)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void ListInsert(ListNode* pos, LTDatatype a)//在pos前面插入
{
	assert(pos);
	ListNode* NewNode = (ListNode*)malloc(sizeof(ListNode));
	if (!NewNode)
	{
		perror("malloc");
		exit(-1);
	}
	ListNode* prev = pos->prev;
	prev->next = NewNode;
	NewNode->prev = prev;
	NewNode->next = pos;
	NewNode->data = a;
}

void ListErase(ListNode*pos)//将pos删除
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
}

void ListChange(ListNode* pos,LTDatatype a)
{
	assert(pos);
	pos->data = a;
}