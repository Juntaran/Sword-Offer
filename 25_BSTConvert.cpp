/*************************************************************************
    > File Name: 25_BSTConvert.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016��08��31�� ������ 15ʱ06��28��
 ************************************************************************/

#include <stdio.h>
#include <malloc.h>

// �������ṹ��
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};

// �������������
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
// ��ָOfferд��
void ConvertNode(TreeNode* node, TreeNode** last)
{
	if (node == NULL)
		return;
	
	TreeNode* current = node;
	
	// ��tree������������ת����last��ת�����������һ������ָ��
	if (current->left != NULL)
		ConvertNode(current->left, last);
	// ����tree��leftָ�룬ָ����һ�����
	current->left = *last;
	// ����ָ�����һ����㣬rightָ����һ�����
	if (*last != NULL)
		(*last)->right = current;
	
	// ����ָ���������һ������ָ��
	*last = current;
	
	// ��tree������������ת����last��ת�����������һ������ָ��
	if (current->right != NULL)
		ConvertNode(current->right, last);
}

// ����������ת��Ϊ����˫������
TreeNode* Convert(TreeNode* root)
{
	if (root == NULL)
		return NULL;
	
	TreeNode* last = NULL;
	ConvertNode(root, &last);
	
	TreeNode* head = root;
	// �ҵ�����ߵĽ�㣬��ת���������ͷ���
	while (head && head->left)
		head = head->left;
	return head;
}
/************************************************************************/

/************************************************************************/
// һ���ݹ�д��

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
	
	// ����������Ϊ˫����
	TreeNode* left = Convert2(root->left);
	// ����������Ϊ�գ�root׷�ӵ�����������
	if (left != NULL)
	{
		leftLast->right = root;
		root->left = leftLast;		// ����˫������
	}
	leftLast = root;
	// ����������Ϊ˫����
	TreeNode* right = Convert2(root->right);
	// ����������Ϊ�գ�����׷�ӵ�root��
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
