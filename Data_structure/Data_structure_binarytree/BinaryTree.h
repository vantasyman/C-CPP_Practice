#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <string.h>
typedef char BinaryDataType;
typedef struct BinaryTree
{
	BinaryDataType val;
	struct BinaryTree* left;
	struct BinaryTree* right;
}BinaryTree;
void treeseq(BinaryTree* p);
void treefront(BinaryTree* p);
void treemid(BinaryTree* p);
void treebehind(BinaryTree* p);





