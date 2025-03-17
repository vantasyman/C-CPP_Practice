#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// 定义栈节点
typedef int STDataType;
typedef struct Stack {
    STDataType _data;
    struct Stack* _next;
} Stack;

// 初始化栈
Stack* StackIni() {
    return NULL; // 空栈直接用 NULL 表示
}

// 销毁栈
void Stackdestory(Stack* pst) {
    while (pst) {
        Stack* tmp = pst;
        pst = pst->_next;
        free(tmp);
    }
}

// 入栈
void StackPush(Stack** ppst, STDataType x) {
    Stack* newNode = (Stack*)malloc(sizeof(Stack));
    newNode->_data = x;
    newNode->_next = *ppst; // 新节点指向当前栈顶
    *ppst = newNode;        // 更新栈顶为新节点
}

// 出栈
void StackPop(Stack** ppst) {
    assert(*ppst); // 确保栈非空
    Stack* tmp = *ppst;
    *ppst = (*ppst)->_next;
    free(tmp);
}

// 判断栈是否为空
int Stackempty(Stack* pst) {
    return pst == NULL; // 空栈返回 1，非空返回 0
}

// 获取栈顶元素
STDataType Stacktop(Stack* pst) {
    assert(!Stackempty(pst)); // 确保栈非空
    return pst->_data;
}

// 打印栈
void Stackprint(Stack* pst) {
    Stack* cur = pst;
    while (cur) {
        printf("%d--", cur->_data);
        cur = cur->_next;
    }
    printf("NULL\n");
}

