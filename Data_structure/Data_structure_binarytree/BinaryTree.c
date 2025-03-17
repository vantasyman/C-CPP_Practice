#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include "BinaryTree.h"
#include "queue.h"
void treeseq(BinaryTree* p)//�������
{
	CirQueue* que=NULL;
	que = CirQueueCreate(que, 20);
	CirQueuePush(que, p);
	while (!isCirQueueEmpty(que))
	{
		if (Cirqueuefront(que) != NULL)
		{
			printf("%c ", Cirqueuefront(que)->val);
			CirQueuePush(que, Cirqueuefront(que)->left);
			CirQueuePush(que, Cirqueuefront(que)->right);
		}
		else
		{
			printf("NULL ");
		}
		CirQueuePop(que);
	}
}
void treefront(BinaryTree* p)//ǰ�����
{
	if (p == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", p->val);
	treefront(p->left);
	treefront(p->right);

}
void treemid(BinaryTree* p)//�������
{
	if (p == NULL)
	{
		printf("NULL ");
		return;
	}
	treemid(p->left);
	printf("%c ", p->val);
	treemid(p->right);

}
void treebehind(BinaryTree* p)//�������
{
	if (p == NULL)
	{
		printf("NULL ");
		return;
	}
	treebehind(p->left);
	treebehind(p->right);
	printf("%c ", p->val);
}