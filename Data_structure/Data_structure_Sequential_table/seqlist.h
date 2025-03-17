#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<assert.h>

typedef int SLDatetype;
typedef struct seqlist
{
	SLDatetype* arr;
	int size;
	int capacity;
}SL;
void Seqlistprint(SL*p);
void IniSL(SL* p);
void SeqlistPushBack(SL*p, SLDatetype x);
void SeqlistPopBack(SL* p);
void SeqlistPushFront(SL* p, SLDatetype x);
void SeqlistPopFront(SL* p);