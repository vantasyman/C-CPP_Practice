#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"
//����һ��ͷ�ڵ㣬���������κ���Чֵ��ֻ��Ϊ����ʹ��
void testlist1(ListNode** pphead)
{
	ListIni(pphead);
	ListPushBack(*pphead, 8);
	ListPushBack(*pphead, 7);
	ListPushBack(*pphead, 6);
	ListPushBack(*pphead, 5);
	ListPushBack(*pphead, 4);
	ListPushBack(*pphead, 3);
	Listprint(*pphead);
	ListPopback(*pphead);
	ListPushfront(*pphead, 2);
	Listprint(*pphead);
	ListPopfront(*pphead);
	Listprint(*pphead);
	ListInsert(ListFind(*pphead, 6), 888);
	Listprint(*pphead);
	ListErase(ListFind(*pphead,5));
	Listprint(*pphead);

}
int main()
{
	ListNode *phead = NULL;
	testlist1(&phead);
	return 0;
}
