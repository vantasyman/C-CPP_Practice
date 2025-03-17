#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include"seqlist.h"
void CheckSl(SL*p)
{
	if (p->capacity <= p->size)
	{
		p->capacity *= 2;
		p->arr = (SLDatetype*)realloc(p->arr, sizeof(SLDatetype) * p->capacity);
		if (!p->arr)
		{
			printf("À©ÈÝÊ§°Ü");
			perror(p);
			return;
		}
		p->capacity += 2;
	}
}
void IniSL(SL* p)
{
	p->arr = (SLDatetype*)malloc(4 * sizeof(SLDatetype));
	if (!p->arr)
	{
		printf("À©ÈÝÊ§°Ü");
		perror(p);
		return;
	}
	p->capacity = 4;
	p->size = 0;
	memset(p->arr, 0, 4*sizeof(SLDatetype));
}
void SeqlistPushBack(SL* p, SLDatetype x)
{
	assert(p);
	//ÅÐ¶ÏÊÇ·ñÐèÒªÔöÈÝ
	CheckSl(p);
	
	p->arr[p->size] = x;
	p->size++;
}
void Seqlistprint(SL* p)
{
	assert(p);
	int a = 0;
	for (a = 0;a < p->size;a++)
	{
		printf("%d ", p->arr[a]);
	}
	printf("\n");
}
void SeqlistPopBack(SL* p)
{
	p->size--;
}
void SeqlistPushFront(SL* p, SLDatetype x)
{
	int tmp = p->size;
	CheckSl(p);
	for (; tmp >= 0; tmp--)
	{
		p->arr[tmp + 1] = p->arr[tmp];
	}
	p->arr[0] = x;
	p->size++;
}
void SeqlistPopFront(SL* p)
{
	int tmp = 0;
	for (tmp = 0; tmp < p->size - 1; tmp++)
	{
		p->arr[tmp] = p->arr[tmp + 1];
	}
	p->size--;
}
void SeqlistPushIn(SL*p,SLDatetype x,int m)
{
	int tmp = p->size;
	CheckSl(p);
	for (; tmp >= m-1; tmp--)
	{
		p->arr[tmp + 1] = p->arr[tmp];
	}
	p->arr[m-1] = x;
	p->size++;
}
void SeqlistPopIn(SL* p, int m)
{
	for (int tmp = m-1; tmp < p->size-1; tmp++)
	{
		p->arr[tmp] = p->arr[tmp + 1];
	}
	p->size--;
}


#ifdef man
int main()
{
	static int a = 0;
	auto int b = 0;
	//register double c = 0;


	return 0;
}
#endif



