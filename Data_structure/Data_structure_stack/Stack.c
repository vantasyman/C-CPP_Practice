#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// ����ջ�ڵ�
typedef int STDataType;
typedef struct Stack {
    STDataType _data;
    struct Stack* _next;
} Stack;

// ��ʼ��ջ
Stack* StackIni() {
    return NULL; // ��ջֱ���� NULL ��ʾ
}

// ����ջ
void Stackdestory(Stack* pst) {
    while (pst) {
        Stack* tmp = pst;
        pst = pst->_next;
        free(tmp);
    }
}

// ��ջ
void StackPush(Stack** ppst, STDataType x) {
    Stack* newNode = (Stack*)malloc(sizeof(Stack));
    newNode->_data = x;
    newNode->_next = *ppst; // �½ڵ�ָ��ǰջ��
    *ppst = newNode;        // ����ջ��Ϊ�½ڵ�
}

// ��ջ
void StackPop(Stack** ppst) {
    assert(*ppst); // ȷ��ջ�ǿ�
    Stack* tmp = *ppst;
    *ppst = (*ppst)->_next;
    free(tmp);
}

// �ж�ջ�Ƿ�Ϊ��
int Stackempty(Stack* pst) {
    return pst == NULL; // ��ջ���� 1���ǿշ��� 0
}

// ��ȡջ��Ԫ��
STDataType Stacktop(Stack* pst) {
    assert(!Stackempty(pst)); // ȷ��ջ�ǿ�
    return pst->_data;
}

// ��ӡջ
void Stackprint(Stack* pst) {
    Stack* cur = pst;
    while (cur) {
        printf("%d--", cur->_data);
        cur = cur->_next;
    }
    printf("NULL\n");
}

