#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
} BTreeNode;


 BTreeNode* MakeBTreeNode(void); // ����� ����
 BTData GetData(BTreeNode* bt); // ��忡 ����� ������ ��ȯ
 void SetData(BTreeNode* bt, BTData data); // ��忡 ������ ����

 BTreeNode* GetLeftSubTree(BTreeNode* bt); // ���� ���� Ʈ�� �ּ� �� ��ȯ
 BTreeNode* GetRightSubTree(BTreeNode* bt); // ������ ���� Ʈ�� �ּ� �� ��ȯ

#endif