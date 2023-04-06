#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
} BTreeNode;


 BTreeNode* MakeBTreeNode(void); // 노드의 생성
 BTData GetData(BTreeNode* bt); // 노드에 저장된 데이터 반환
 void SetData(BTreeNode* bt, BTData data); // 노드에 데이터 저장

 void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub); // 왼쪽 서브 트리 연결
 void MakeRightSubTree(BTreeNode* main, BTreeNode* sub); // 오른쪽 서브 트리 연결

 typedef void VisitFuncPtr(BTData data); // 함수 포인터 타입 정의

 void InorderTraverse(BTreeNode* bt, VisitFuncPtr action); // 중위 순회
 void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action); // 전위 순회
 void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action); // 후위 순회

 // 노드의 삭제
 void DeleteTree(BTreeNode* bt);

#endif