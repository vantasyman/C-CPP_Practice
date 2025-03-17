#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"
int main()
{
	Stack* pst = StackIni();
	StackPush(&pst, 3);
	StackPush(&pst, 4);
	StackPush(&pst, 5);
	StackPush(&pst, 6);
	StackPush(&pst, 7);
	StackPop(&pst);
	StackPop(&pst);
	printf("%d\n",Stacktop(pst));
	Stackprint(pst);
	

	return 0;
}