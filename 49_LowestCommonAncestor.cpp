/*************************************************************************
    > File Name: 49_LowestCommonAncestor.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016��09��05�� ����һ 16ʱ51��30��
 ************************************************************************/

#include <stdio.h>
#include <malloc.h>

// �������ṹ
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};

// ����һ�����
TreeNode* newNode(int num)
{
	TreeNode* temp = new TreeNode;
	temp->val = num;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

// LCA
TreeNode* findLCA(TreeNode* root, int n1, int n2)
{
	if (root == NULL)
		return NULL;
	
	if (root->val==n1 || root->val==n2)
		return root;
	
	TreeNode* leftNode  = findLCA(root->left,  n1, n2);
	TreeNode* rightNode = findLCA(root->right, n1, n2);
	
	if (leftNode && rightNode)
		return root;
	
	return leftNode==NULL ? rightNode : leftNode;
}

int main()
{
	TreeNode* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	
	printf("LCA(4,7) = %d\n", findLCA(root, 4, 7)->val);
	
	return 0;
}