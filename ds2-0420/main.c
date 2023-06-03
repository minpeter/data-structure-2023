#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
} TreeNode;

//��ȯ���� Ž�� �Լ�
TreeNode* search(TreeNode* node, int key) {
	if (node == NULL) return NULL;
	if (key == node->key) return node;
	else if (key < node->key)
		return search(node->left, key);
	else
		return search(node->right, key);
}
TreeNode* new_node(int item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* node, int key) {
	if (node == NULL) return new_node(key);
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);

	return node;
}

TreeNode* min_value_node(TreeNode* node) {
	TreeNode* current = node;
	//�� ���� �ܸ� ��带 ã���� ������
	while (current->left != NULL)
		current = current->left;
	return current;
}
//���� Ž�� Ʈ���� Ű�� �־����� Ű�� ����� ��带 �����ϰ� //���ο� ��Ʈ ��带 ��ȯ�Ѵ�.
TreeNode* delete_node(TreeNode* root, int key) {
	if (root == NULL) return root;
	//���� Ű�� ��Ʈ���� ������ ���� ���� Ʈ���� �ִ� ����
	if (key < root->key)
		root->left = delete_node(root->left, key);
	//���� Ű�� ��Ʈ���� ũ�� ������ ���� Ʈ���� �ִ� ����
	else if (key > root->key)
		root->right = delete_node(root->right, key);
	//Ű�� ��Ʈ�� ������ �� ��带 �����ϸ� ��
	else {
		//ù ��°�� �� ��° ���
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		//�� ��° ���
		TreeNode* temp = min_value_node(root->right);

		//�߿� ��ȸ�� �İ� ��带 �����Ѵ�.
		root->key = temp->key;
		//�߿� ��ȸ�� �İ� ��带 �����Ѵ�.
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}

//���� ��ȸ
void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left); // ���ʼ���Ʈ�� ��ȸ
		printf("[%d] ", root->key); // ��� �湮
		inorder(root->right); // �����ʼ���Ʈ�� ��ȸ
	}
}

void main() {
	// ���� Ž�� Ʈ�� ����
	TreeNode* root = NULL;
	root = insert_node(root, 30);
	insert_node(root, 10);
	insert_node(root, 20);
	insert_node(root, 40);
	insert_node(root, 50);
	insert_node(root, 60);

	// ���� Ž�� Ʈ�� ��ȸ
	printf("���� ��ȸ : ");
	inorder(root);

	// ���� Ž�� Ʈ�� Ž��

	if (search(root, 30) != NULL)
		printf("\nŽ�� ����\n");
	else
		printf("\nŽ�� ����\n");

	if (search(root, 70) != NULL)
		printf("\nŽ�� ����\n");
	else
		printf("\nŽ�� ����\n");
}