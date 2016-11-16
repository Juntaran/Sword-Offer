/*************************************************************************
    > File Name: 25_BSTConvert.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年08月31日 星期三 15时06分28秒
 ************************************************************************/

#include <stdio.h>
#include <malloc.h>

// 二叉树结构体
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};

// 构造二叉搜索树
TreeNode* InsertNode(TreeNode* tree, int val)
{
	if (tree == NULL)
	{
		tree = new TreeNode();
		tree->left = NULL;
		tree->right = NULL;
		tree->val = val;
	}
	else if (tree->val > val)
		tree->left = InsertNode(tree->left, val);
	else if (tree->val < val)
		tree->right = InsertNode(tree->right, val);
	return tree;
}

void PrintTree(TreeNode* tree)
{
	if (tree == NULL)
		return;
	PrintTree(tree->left);
	printf("%d ", tree->val);
	PrintTree(tree->right);
}

void PrintList(TreeNode* list)
{
	printf("\n");
	if (list == NULL)
		return;
	TreeNode* node = list;
	while (node)
	{
		printf("%d ", node->val);
		node = node->right;
	}
	printf("\n");
}

/************************************************************************/
// 剑指Offer写法
void ConvertNode(TreeNode* node, TreeNode** last)
{
	if (node == NULL)
		return;
	
	TreeNode* current = node;
	
	// 对tree的左子树进行转换，last是转换后链表最后一个结点的指针
	if (current->left != NULL)
		ConvertNode(current->left, last);
	// 调整tree的left指针，指向上一个结点
	current->left = *last;
	// 调整指向最后一个结点，right指向下一个结点
	if (*last != NULL)
		(*last)->right = current;
	
	// 调整指向最后链表一个结点的指针
	*last = current;
	
	// 对tree的右子树进行转换，last是转换后链表最后一个结点的指针
	if (current->right != NULL)
		ConvertNode(current->right, last);
}

// 二叉搜索树转换为排序双向链表
TreeNode* Convert(TreeNode* root)
{
	if (root == NULL)
		return NULL;
	
	TreeNode* last = NULL;
	ConvertNode(root, &last);
	
	TreeNode* head = root;
	// 找到最左边的结点，即转换后链表的头结点
	while (head && head->left)
		head = head->left;
	return head;
}
/************************************************************************/

/************************************************************************/
// 一个递归写法

TreeNode* leftLast = NULL;
TreeNode* Convert2(TreeNode* root)
{
	if (root == NULL)
		return root;
	if (root->left==NULL && root->right==NULL)
	{
		leftLast = root;
		return root;
	}
	
	// 左子树改造为双链表
	TreeNode* left = Convert2(root->left);
	// 左子树链表不为空，root追加到左子树链表
	if (left != NULL)
	{
		leftLast->right = root;
		root->left = leftLast;		// 构造双向链表
	}
	leftLast = root;
	// 右子树改造为双链表
	TreeNode* right = Convert2(root->right);
	// 右子树链表不为空，链表追加到root后
	if (right != NULL)
	{
		right->left = root;
		root->right = right;
	}
	return left != NULL ? left : root;
}
/************************************************************************/

int main()
{
	TreeNode* tree = NULL;
	for (int i = 10; i > 5; --i)
	{
		tree = InsertNode(tree, i);
	}
	for (int i = 0; i <= 5; ++i)
	{
		tree = InsertNode(tree, i);
	}
	PrintTree(tree);
	// tree = Convert(tree);
	tree = Convert2(tree);
	PrintList(tree);
	
	return 0;
}
