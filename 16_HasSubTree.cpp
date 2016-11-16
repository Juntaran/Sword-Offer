/*************************************************************************
    > File Name: 17_MirrorOfBinaryTree.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年08月30日 星期二 17时12分37秒
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

TreeNode* createSubTree()
{
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	root->val = 8;
	root->left = (TreeNode*)malloc(sizeof(TreeNode));
	root->left->val = 9;
	root->right = (TreeNode*)malloc(sizeof(TreeNode));
	root->right->val = 2;
	root->left->left = NULL;
	root->left->right = NULL;
	root->right->left = NULL;
	root->right->right = NULL;
	
	return root;
}

bool DoesTree1HaveTree2(TreeNode* root1, TreeNode* root2)
{
	if (root2 == NULL)
		return true;
	if (root1 == NULL)
		return false;
	if (root1->val != root2->val)
		return false;
	
	return DoesTree1HaveTree2(root1->left, root2->left) && DoesTree1HaveTree2(root1->right, root2->right);
}

bool hasSubTree(TreeNode* root1, TreeNode* root2)
{
	int ret = false;
	if (root1!=NULL && root2!=NULL)
	{
		if (root1->val == root2->val)
			ret = DoesTree1HaveTree2(root1, root2);
		if (ret == false)
			ret = hasSubTree(root1->left, root2);
		if (ret == false)
			ret = hasSubTree(root1->right, root2);
	}
}

// 层序遍历二叉树
void PrintTreeByLevel(TreeNode* root)
{
	if (root == NULL)
		return;
	
	vector<TreeNode*> vec;
	vec.push_back(root);
	int cur = 0;
	int last = 1;
	
	while (cur < vec.size())
	{
		last = vec.size();
		while (cur < last)
		{
			printf("%d ", vec[cur]->val);
			if (vec[cur]->left != NULL)
				vec.push_back(vec[cur]->left);
			if (vec[cur]->right != NULL)
				vec.push_back(vec[cur]->right);
			
			++ cur;
		}
		printf("\n");
	}
}

int main()
{
	TreeNode* tree1 = createTree();
	TreeNode* tree2 = createSubTree();
	
	PrintTreeByLevel(tree1);
	printf("\n");
	PrintTreeByLevel(tree2);
	printf("\n");
	
	bool ret = hasSubTree(tree1, tree2);
	if (ret == true)
		printf("Yes\n");
	else
		printf("No\n");
	
	return 0;
}