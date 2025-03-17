#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef BinaryTree* QueueDataType;
typedef struct CirQueue
{
	QueueDataType* q;
	int front;
	int rear;
	int capacity;
}CirQueue;


QueueDataType Cirqueuefront(CirQueue* p1)
{
	return *((p1->q)+(p1->front));
}

CirQueue* CirQueueCreate(CirQueue* p,size_t x)
{
	p = (CirQueue*)malloc(sizeof(CirQueue));
	p->q = (QueueDataType*)(malloc(sizeof(QueueDataType) * x));
	p->capacity = x;
	p->front = 0;
	p->rear = 0;
}
int isCirQueueEmpty(CirQueue* p)
{
	if (p->front == p->rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isCirQueueFull(CirQueue* p)
{
	if ((p->rear+1) % p->capacity == p->front)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void CirQueuePop(CirQueue* p)
{
	if (!isCirQueueEmpty(p))
	{
		p->front=(p->front+1)%p->capacity;
	}
	else
	{
		return;
	}
}
void CirQueuePush(CirQueue* p,QueueDataType x)
{
	if (isCirQueueFull(p))
	{
		return;
	}
	else
	{
		*(p->q + p->rear) = x;
		p->rear = (p->rear + 1) % p->capacity;
	}
}