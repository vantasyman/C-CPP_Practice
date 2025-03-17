#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
void SList_test(SListNode* pList)
{
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPrint(pList);
	SListPopBack(&pList);
	SListPrint(pList);
	//SListPopBack(&pList);
	SListinsert(&pList, 2, 100);
	SListinsert(&pList,1,101);
	SListinsert(&pList, 44, 102);

	//SListinsert(&pList, 10, 100);

	SListPrint(pList);
	SListPopAfter(&pList, 2);
	SListPrint(pList);
	SListPopAfter(&pList, 1);
	SListPrint(pList);




}
int main()
{
	SListNode *pList = NULL;
	SList_test(pList);

	return 0;
}