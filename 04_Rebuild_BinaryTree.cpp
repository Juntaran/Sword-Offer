/*************************************************************************
    > File Name: 04_Rebuild_BinaryTree.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年08月29日 星期一 16时32分35秒
 ************************************************************************/

#include <stdio.h>
#include <malloc.h>

// 二叉树结构体
struct BinaryTree
{
    int val;
    struct BinaryTree* left;
	struct BinaryTree* right;
};

void preorderPrintBinaryTree(struct BinaryTree* root)
{
	if (root == NULL)
		return;
	printf("%d ", root->val);
	preorderPrintBinaryTree(root->left);
	preorderPrintBinaryTree(root->right);
}

void inorderPrintBinaryTree(struct BinaryTree* root)
{
	if (root == NULL)
		return;
	preorderPrintBinaryTree(root->left);
	printf("%d ", root->val);
	preorderPrintBinaryTree(root->right);
}

void postorderPrintBinaryTree(struct BinaryTree* root)
{
	if (root == NULL)
		return;
	preorderPrintBinaryTree(root->left);
	preorderPrintBinaryTree(root->right);
	printf("%d ", root->val);
}



struct BinaryTree* rebuild_BinaryTree(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
	// 前序遍历第一个数字是根节点的值
	int rootValue = startPreorder[0];
	struct BinaryTree* root = (BinaryTree*)malloc(sizeof(BinaryTree));
	root->val = rootValue;
	root->left = NULL;
	root->right = NULL;
	
	if (startPreorder == endPreorder)
	{
		if (startInorder==endInorder && *startPreorder==*startInorder)
			return root;
	}
	
	// 在前序遍历中找根节点的值
	int* rootInorder = startInorder;
	while (rootInorder<=endInorder && *rootInorder!=rootValue)
		++ rootInorder;
	
	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;
	if (leftLength > 0)
	{
		// 构建左子树
		root->left = rebuild_BinaryTree(startPreorder+1, leftPreorderEnd, startInorder, rootInorder-1);
	}
	if (leftLength < endPreorder - startPreorder)
	{
		// 构建右子树
		root->right = rebuild_BinaryTree(leftPreorderEnd+1, endPreorder, rootInorder+1, endInorder);
	}
	return root;
}

struct BinaryTree* rebuild(int* preorder, int* inorder, int length)
{
	if (preorder==NULL || inorder==NULL || length<=0)
		return NULL;
	
	return rebuild_BinaryTree(preorder, preorder+length-1, inorder, inorder+length-1);
}

// ====================测试代码====================
void Test(int* preorder, int* inorder, int length)
{
    printf("The preorder sequence is: ");
    for(int i = 0; i < length; ++ i)
        printf("%d ", preorder[i]);
    printf("\n");

    printf("The inorder  sequence is: ");
    for(int i = 0; i < length; ++ i)
        printf("%d ", inorder[i]);
    printf("\n");

    struct BinaryTree* root = rebuild(preorder, inorder, length);
	
	printf("After rebuild:\n");
	printf("\nThe preorder  sequence is: ");
	preorderPrintBinaryTree(root);
	printf("\nThe inorder   sequence is: ");
	inorderPrintBinaryTree(root);
	printf("\nThe postorder sequence is: ");
	postorderPrintBinaryTree(root);
}

int main()
{
	int length = 8;
	int preorder[8] = {1, 2, 4, 7, 3, 5, 6, 8};
	int inorder[8]  = {4, 7, 2, 1, 5, 3, 8, 6};
	
	Test(preorder, inorder, length);
}