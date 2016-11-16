/*************************************************************************
    > File Name: 37_TreeDepth.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年09月03日 星期六 09时49分38秒
 ************************************************************************/

#include <stdio.h>
#include <malloc.h>
#include <math.h>

// 二叉树结构体
struct BinaryTree
{
    int val;
    struct BinaryTree* left;
	struct BinaryTree* right;
};

BinaryTree* createTree()
{
	BinaryTree* root = (BinaryTree*)malloc(sizeof(BinaryTree));
	root->val = 1;
	root->left = (BinaryTree*)malloc(sizeof(BinaryTree));
	root->left->val = 2;
	root->right = (BinaryTree*)malloc(sizeof(BinaryTree));
	root->right->val = 3;
	root->left->left = (BinaryTree*)malloc(sizeof(BinaryTree));
	root->left->left->val = 4;
	root->left->left->left = NULL;
	root->left->left->right = NULL;
	root->left->right = (BinaryTree*)malloc(sizeof(BinaryTree));
	root->left->right->val = 5;
	root->left->right->right = NULL;
	root->left->right->left = (BinaryTree*)malloc(sizeof(BinaryTree));
	root->left->right->left->val = 7;
	root->left->right->left->left = NULL;
	root->left->right->left->right = NULL;
	root->right->right = (BinaryTree*)malloc(sizeof(BinaryTree));
	root->right->right->val = 6;
	root->right->left = NULL;
	root->right->right->left = NULL;
	root->right->right->right = NULL;
	// root->right->right->right = (BinaryTree*)malloc(sizeof(BinaryTree));
	// root->right->right->right->val = 8;
	// root->right->right->right->left = root->right->right->right->right = NULL;
	
	return root;
}

// 二叉树中序遍历
void InOrder(BinaryTree* root)
{
	if (root == NULL)
		return;
	
	InOrder(root->left);
	printf("%d ", root->val);
	InOrder(root->right);
}

// 二叉树的深度
int TreeDepth(BinaryTree* root)
{
	if (root == NULL)
		return 0;
	
	int left  = TreeDepth(root->left);
	int right = TreeDepth(root->right);
	
	return (left>right) ? (left+1) : (right+1);
}

// 判断一棵树是不是平衡二叉树
bool isBalanced(BinaryTree* root)
{
	if (root == NULL)
		return true;
	
	int left  = TreeDepth(root->left);
	int right = TreeDepth(root->right);
	
	int diff = abs(left - right);
	if (diff > 1)
		return false;
	
	return isBalanced(root->left) && isBalanced(root->right);
}

// 后序遍历方法
bool isBalanced2(BinaryTree* root, int* depth)
{
	if (root == NULL)
	{
		*depth = 0;
		return true;
	}
	int left, right;
	if (isBalanced2(root->left, &left) && isBalanced2(root->right, &right))
	{
		int diff = abs(left - right);
		if (diff <= 1)
		{
			*depth = 1 + (left>right ? left : right);
			return true;
		}
	}
	return false;
}

bool isBalanced2(BinaryTree* root)
{
	int depth = 0;
	return isBalanced2(root, &depth);
}



int main()
{
	BinaryTree* test = createTree();
	InOrder(test);
	int depth = TreeDepth(test);
	printf("\ndepth is %d\n", depth);
	if (isBalanced2(test) == true)
		printf("Balance\n");
	else
		printf("No Balance\n");
	
}