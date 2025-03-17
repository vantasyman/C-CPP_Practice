#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
/*void SListPrint(SListNode* phead)
{
	if (phead != NULL)
	{
		printf(phead->data);
		SListPrint(phead->next);
	}
	else
	{
		return;
	}
}*/
void SListPrint(SListNode *phead)
{
	SListNode *cur = phead;
	while (cur)
	{
		printf("%d-->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
void SListPushBack(SListNode** pphead, SListDataType x)
{
	if (*pphead == NULL)
	{
		SListNode *NewNode = (SListNode*)malloc(sizeof(SListNode));
		if (NewNode == NULL)
		{
			perror("malloc");
			exit(-1);
		}
		NewNode->data = x;
		NewNode->next = NULL;
		*pphead = NewNode;
		return;
	}
	else
	{
		SListNode* tmp = *pphead;
		while (tmp->next)
		{
			tmp = tmp->next;
		}//找尾巴位置
		//增加容量
		SListNode* NewNode = (SListNode*)malloc(sizeof(SListNode));
		if (!NewNode)
		{
			perror("malloc");
			return;
		}
		tmp->next = NewNode;
		NewNode->next = NULL;
		NewNode->data = x;
	}
}
void SListPopBack(SListNode **pphead)
{
	if (*pphead == NULL)
	{
		printf("无需删除，已经为空\n");
		return;
	}
	else if ((*pphead)->next == NULL)
	{
		printf("仅有一个元素，已删\n");
		free(*pphead);
		*pphead = NULL;
		return;
	}
	else
	{
		SListNode* cur = *pphead;
		SListNode* pre = NULL;
		while (cur->next)
		{
			pre = cur;
			cur = cur->next;
		}
		free(cur);
		//cur = NULL;
		pre->next = NULL;
	}
}
void SListPushFront(SListNode** pphead,SListDataType x)
{
	if (*pphead == NULL)
	{
		SListNode* NewNode = (SListNode*)malloc(sizeof(SListNode));
		if (NewNode == NULL)
		{
			perror("malloc");
			exit(-1);
		}
		NewNode->data = x;
		NewNode->next = NULL;
		*pphead = NewNode;
		return;
	}
	else
	{
		SListNode* begin = (SListNode*)malloc(sizeof(SListNode));
		if (begin == NULL)
		{
			perror("malloc");
			exit(-1);
		}
		SListNode* tmp = *pphead;
		*pphead = begin;
		begin->next = tmp;
		begin->data = x;
	}
}
void SListPopFront(SListNode** pphead)
{
	if (*pphead == NULL)
	{
		printf("无需删除，已经为空\n");
		return;
	}
	else if ((*pphead)->next == NULL)
	{
		printf("仅有一个元素，已删\n");
		free(*pphead);
		*pphead = NULL;
		return;
	}
	else
	{
		SListDataType* tmp = *pphead;
		*pphead =(*pphead)->next;
		free(tmp);
	}

}
void SListinsert(SListNode** pphead, int afterplace, SListDataType x)
{
	int count = 0;
	SListNode* tmp = *pphead;
	if (*pphead == NULL)
	{
		*pphead = (SListNode*)malloc(sizeof(SListDataType));
	}
	else
	{
		while (tmp->next != NULL)
		{
			count++;

			if (count == afterplace)
			{
				SListNode* expand= (SListNode*)malloc(sizeof(SListDataType));
				expand->next = tmp->next;
				tmp->next = expand;
				expand->data = x;
				break; 
			}
			tmp = tmp->next;
		}
		if (count != afterplace)
		{
			SListNode* expand = (SListNode*)malloc(sizeof(SListDataType));
			expand->next = tmp->next;
			expand->data = x;
			tmp->next = expand;
		}
	}
}
void SListPopAfter(SListNode** pphead, int afterplace)
{
	int count = 0;
	SListNode* tmp = *pphead;
	if (*pphead == NULL)
	{
		return;
	}
	else
	{
		while (tmp->next != NULL)
		{
			count++;

			if (count == afterplace)
			{
				SListNode* next = tmp->next;
				tmp->next = next->next;
				free(next);
				break;
			}
			tmp = tmp->next;
		}
		if (count != afterplace)
		{
			return;
		}
	}
}

