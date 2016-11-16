/*************************************************************************
    > File Name: 21_PrintTreeTopToBottom.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年08月30日 星期二 20时24分53秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <bits/stdc++.h>

using namespace std;

// 二叉树结构体
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};

// 层序遍历
void PrintTreeTopToBottom(TreeNode* root)
{
	if (root == NULL)
		return;
	
	vector<TreeNode*> vec;
	vec.push_back(root);
	
	int cur = 0;
	while (cur < vec.size())
	{
		printf("%d ", vec[cur]->val);
		if (vec[cur]->left)
			vec.push_back(vec[cur]->left);
		if (vec[cur]->right)
			vec.push_back(vec[cur]->right);
		++cur;
	}
	printf("\n");
}

TreeNode* createTree()
{
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	root->val = 8;
	root->left = (TreeNode*)malloc(sizeof(TreeNode));
	root->left->val = 8;
	root->right = (TreeNode*)malloc(sizeof(TreeNode));
	root->right->val = 7;
	root->right->left = NULL;
	root->right->right = NULL;
	root->left->left = (TreeNode*)malloc(sizeof(TreeNode));
	root->left->left->val = 9;
	root->left->left->left = NULL;
	root->left->left->right = NULL;
	root->left->right = (TreeNode*)malloc(sizeof(TreeNode));
	root->left->right->val = 2;
	root->left->right->left = (TreeNode*)malloc(sizeof(TreeNode));
	root->left->right->left->val = 4;
	root->left->right->left->left = NULL;
	root->left->right->left->right = NULL;
	root->left->right->right = (TreeNode*)malloc(sizeof(TreeNode));
	root->left->right->right->val = 7;
	root->left->right->right->left = NULL;
	root->left->right->right->right = NULL;
	
	return root;
}

int main()
{
	TreeNode* test = createTree();
	PrintTreeTopToBottom(test);
}