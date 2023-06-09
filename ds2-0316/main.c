#include <stdio.h>
#include "BinaryTree.h"

void ShowIntData(int data) {
	printf("%d ", data);
}


void main() {
	BTreeNode* bt1 = MakeBTreeNode();
	BTreeNode* bt2 = MakeBTreeNode();
	BTreeNode* bt3 = MakeBTreeNode();
	BTreeNode* bt4 = MakeBTreeNode();
	BTreeNode* bt5 = MakeBTreeNode();
	BTreeNode* bt6 = MakeBTreeNode();

	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);
	SetData(bt5, 5);
	SetData(bt6, 6);


	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);
	MakeRightSubTree(bt2, bt5);
	MakeLeftSubTree(bt3, bt6);

	printf("중위순회\n");
	InorderTraverse(bt1, ShowIntData);
	printf("\n");

	printf("전위순회\n");
	PreorderTraverse(bt1, ShowIntData);
	printf("\n");

	printf("후위순회\n");
	PostorderTraverse(bt1, ShowIntData);
	printf("\n");

	printf("%p\n", bt1);

	DeleteTree(&bt1);

	printf("후위순회\n");
	PostorderTraverse(bt1, ShowIntData);

	// 당연하지만 bt1를 비롯한 트리가 해제되었기에 아무것도 출력되지 않는다.
	printf("\n");
}