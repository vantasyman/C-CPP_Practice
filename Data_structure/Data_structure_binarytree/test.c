#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include "BinaryTree.h"
int main()
{
	BinaryTree p1;
	BinaryTree p2;
	BinaryTree p3;
	BinaryTree p4;
	BinaryTree p5;
	BinaryTree p6;
	p1.left = &p2;
	p1.right = &p3;
	p2.left = NULL;
	p2.right = &p4;
	p3.left = &p5;
	p3.right = NULL;
	p4.right = NULL;
	p4.left = &p6;
	p6.left = NULL;
	p6.right = NULL;
	p5.left = NULL;
	p5.right = NULL;
	p1.val = 'A';
	p2.val = 'B';
	p3.val = 'C';
	p4.val = 'D';
	p5.val = 'E';
	p6.val = 'F';


	//treefront(&p1);
	//printf("\n");
	//treemid(&p1);
	//printf("\n");
	//treebehind(&p1);

	treeseq(&p1);

}