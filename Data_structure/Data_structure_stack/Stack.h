#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#define STDataType int
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct Stack
{
	STDataType* _data;
	struct stack* _next;
}Stack;


Stack* StackIni();
void Stackdestory(Stack* pst);
void StackPush(Stack** ppst, STDataType x);//��ջ
void StackPop(Stack** ppst);//��ջ
int Stackempty(Stack* pst);
void Stackprint(Stack* pst);
STDataType Stacktop(Stack* pst);