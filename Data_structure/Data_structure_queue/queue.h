#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int QueueDataType;
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
	p->capacity = x;
	p->q = (QueueDataType*)(malloc(sizeof(QueueDataType) * x));
	p->front = 0;
	p->rear = 0;
}
bool isCirQueueEmpty(CirQueue* p)
{
	if (p->front == p->rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool isCirQueueFull(CirQueue* p)
{
	if ((p->front + 1) % p->capacity == p->rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void CirQueuePop(CirQueue* p)
{
	if (!isCirQueueEmpty)
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