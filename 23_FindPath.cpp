/*************************************************************************
    > File Name: 23_FindPath.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年08月30日 星期二 20时49分34秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

// 二叉树结构体
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};

void FindPath(TreeNode* root, int sum);
void FindPath(TreeNode* root, int sum, vector<int> &path, int currentSum);

// 找到二叉树一条和为sum的路径
void FindPath(TreeNode* root, int sum)
{
	if (root == NULL)
		return;
	
	vector<int> path;
	int currentSum = 0;
	FindPath(root, sum, path, currentSum);
}

void FindPath(TreeNode* root, int sum, vector<int> &path, int currentSum)
{
	currentSum += root->val;
	path.push_back(root->val);
	
	// 如果走到叶子结点，和等于输入sum，输出
	if (root->left==NULL && root->right==NULL && currentSum==sum)
	{
		printf("Find:\n");
		vector<int>::iterator iter = path.begin();
		for (; iter != path.end(); ++iter)
			printf("%d\t", *iter);
		printf("\n");
	}
	
	// 如果不是叶子结点，继续遍历子结点
	if (root->left)
		FindPath(root->left, sum, path, currentSum);
	if (root->right)
		FindPath(root->right, sum, path, currentSum);
	
	// 查找失败删除该结点
	path.pop_back();
}

TreeNode* createTree()
{
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	root->val = 10;
	root->left = (TreeNode*)malloc(sizeof(TreeNode));
	root->left->val = 5;
	root->right = (TreeNode*)malloc(sizeof(TreeNode));
	root->right->val = 12;
	root->right->left = NULL;
	root->right->right = NULL;
	root->left->left = (TreeNode*)malloc(sizeof(TreeNode));
	root->left->left->val = 4;
	root->left->left->left = NULL;
	root->left->left->right = NULL;
	root->left->right = (TreeNode*)malloc(sizeof(TreeNode));
	root->left->right->val = 7;
	root->left->right->left = NULL;
	root->left->right->right = NULL;
	
	return root;
}

int main()
{
	TreeNode* test = createTree();
	FindPath(test, 22);
}