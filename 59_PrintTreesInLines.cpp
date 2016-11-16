/*************************************************************************
    > File Name: 59_PrintTreeInLineTreeInLine.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年09月07日 星期三 20时31分19秒
 ************************************************************************/
 
#include <stdio.h>
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

TreeNode* CreateTreeNode(int value)
{
    TreeNode* pNode = new TreeNode();
    pNode->val = value;
    pNode->left = NULL;
    pNode->right = NULL;

    return pNode;
}

void ConnectTreeNodes(TreeNode* pParent, TreeNode* pLeft, TreeNode* pRight)
{
    if(pParent != NULL)
    {
        pParent->left = pLeft;
        pParent->right = pRight;
    }
}

void PrintTreeInLineTreeNode(TreeNode* pNode)
{
    if(pNode != NULL)
    {
        printf("value of this node is: %d\n", pNode->val);

        if(pNode->left != NULL)
            printf("value of its left child is: %d.\n", pNode->left->val);
        else
            printf("left child is null.\n");

        if(pNode->right != NULL)
            printf("value of its right child is: %d.\n", pNode->right->val);
        else
            printf("right child is null.\n");
    }
    else
    {
        printf("this node is null.\n");
    }

    printf("\n");
}

void PrintTreeInLineTree(TreeNode* pRoot)
{
    PrintTreeInLineTreeNode(pRoot);

    if(pRoot != NULL)
    {
        if(pRoot->left != NULL)
            PrintTreeInLineTree(pRoot->left);

        if(pRoot->right != NULL)
            PrintTreeInLineTree(pRoot->right);
    }
}

void DestroyTree(TreeNode* pRoot)
{
    if(pRoot != NULL)
    {
        TreeNode* pLeft = pRoot->left;
        TreeNode* pRight = pRoot->right;

        delete pRoot;
        pRoot = NULL;

        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}

// 层序遍历，分层输出
void PrintTreeInLine(TreeNode* root)
{
	if (root == NULL)
		return;
	
	queue<TreeNode*> nodes;
	nodes.push(root);
	
	int nextLevel = 0;
	int toBePrinted = 1;
	
	while (!nodes.empty())
	{
		TreeNode* node = nodes.front();
		printf("%d ", node->val);
		
		if (node->left != NULL)
		{
			nodes.push(node->left);
			++ nextLevel;
		}
		if (node->right != NULL)
		{
			nodes.push(node->right);
			++ nextLevel;
		}
		nodes.pop();
		-- toBePrinted;
		
		if (toBePrinted == 0)
		{
			printf("\n");
			toBePrinted = nextLevel;
			nextLevel = 0;
		}
	}
}

// ==================== Test Code ====================
//            8
//        6      10
//       5 7    9  11
void Test1()
{
    TreeNode* pNode8 = CreateTreeNode(8);
    TreeNode* pNode6 = CreateTreeNode(6);
    TreeNode* pNode10 = CreateTreeNode(10);
    TreeNode* pNode5 = CreateTreeNode(5);
    TreeNode* pNode7 = CreateTreeNode(7);
    TreeNode* pNode9 = CreateTreeNode(9);
    TreeNode* pNode11 = CreateTreeNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    printf("====Test1 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("8 \n");
    printf("6 10 \n");
    printf("5 7 9 11 \n\n");

    printf("Actual Result is: \n");
    PrintTreeInLine(pNode8);
    printf("\n");

    DestroyTree(pNode8);
}

//            5
//          4
//        3
//      2
void Test2()
{
    TreeNode* pNode5 = CreateTreeNode(5);
    TreeNode* pNode4 = CreateTreeNode(4);
    TreeNode* pNode3 = CreateTreeNode(3);
    TreeNode* pNode2 = CreateTreeNode(2);

    ConnectTreeNodes(pNode5, pNode4, NULL);
    ConnectTreeNodes(pNode4, pNode3, NULL);
    ConnectTreeNodes(pNode3, pNode2, NULL);

    printf("====Test2 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("5 \n");
    printf("4 \n");
    printf("3 \n");
    printf("2 \n\n");

    printf("Actual Result is: \n");
    PrintTreeInLine(pNode5);
    printf("\n");

    DestroyTree(pNode5);
}

//        5
//         4
//          3
//           2
void Test3()
{
    TreeNode* pNode5 = CreateTreeNode(5);
    TreeNode* pNode4 = CreateTreeNode(4);
    TreeNode* pNode3 = CreateTreeNode(3);
    TreeNode* pNode2 = CreateTreeNode(2);

    ConnectTreeNodes(pNode5, NULL, pNode4);
    ConnectTreeNodes(pNode4, NULL, pNode3);
    ConnectTreeNodes(pNode3, NULL, pNode2);

    printf("====Test3 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("5 \n");
    printf("4 \n");
    printf("3 \n");
    printf("2 \n\n");

    printf("Actual Result is: \n");
    PrintTreeInLine(pNode5);
    printf("\n");

    DestroyTree(pNode5);
}

void Test4()
{
    TreeNode* pNode5 = CreateTreeNode(5);

    printf("====Test4 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("5 \n\n");

    printf("Actual Result is: \n");
    PrintTreeInLine(pNode5);
    printf("\n");

    DestroyTree(pNode5);
}

void Test5()
{
    printf("====Test5 Begins: ====\n");
    printf("Expected Result is:\n");

    printf("Actual Result is: \n");
    PrintTreeInLine(NULL);
    printf("\n");
}

//        100
//        /
//       50   
//         \
//         150
void Test6()
{
    TreeNode* pNode100 = CreateTreeNode(100);
    TreeNode* pNode50 = CreateTreeNode(50);
    TreeNode* pNode150 = CreateTreeNode(150);

    ConnectTreeNodes(pNode100, pNode50, NULL);
    ConnectTreeNodes(pNode50, NULL, pNode150);

    printf("====Test6 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("100 \n");
    printf("50 \n");
    printf("150 \n\n");

    printf("Actual Result is: \n");
    PrintTreeInLine(pNode100);
    printf("\n");
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

	return 0;
}