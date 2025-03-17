#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include"seqlist.h"
void testSeqlist()
{
	SL m;
	IniSL(&m);
	SeqlistPushBack(&m, 1);
	SeqlistPushBack(&m, 2);
	SeqlistPushBack(&m, 3);
	SeqlistPushBack(&m, 4);
	SeqlistPushBack(&m, 5);
	SeqlistPushBack(&m, 6);
	Seqlistprint(&m);
	SeqlistPopBack(&m);
	Seqlistprint(&m);
	SeqlistPushFront(&m,99);
	SeqlistPushFront(&m,9);
	Seqlistprint(&m);
	SeqlistPopFront(&m);
	Seqlistprint(&m);
	SeqlistPushIn(&m, 7, 2);
	SeqlistPushIn(&m, 8, 3);
	Seqlistprint(&m);
	SeqlistPopIn(&m, 3);
	SeqlistPopIn(&m, 4);
	Seqlistprint(&m);




}
int main()
{
	testSeqlist();
}