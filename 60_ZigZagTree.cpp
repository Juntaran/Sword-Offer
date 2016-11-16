/*************************************************************************
    > File Name: 60_ZigZagTree.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年09月07日 星期三 20时52分02秒
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

void PrintInZigZagTreeInLineTreeNode(TreeNode* pNode)
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

void PrintInZigZagTreeInLineTree(TreeNode* pRoot)
{
    PrintInZigZagTreeInLineTreeNode(pRoot);

    if(pRoot != NULL)
    {
        if(pRoot->left != NULL)
            PrintInZigZagTreeInLineTree(pRoot->left);

        if(pRoot->right != NULL)
            PrintInZigZagTreeInLineTree(pRoot->right);
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

void PrintInZigZag(TreeNode* root)
{
	if (root == NULL)
		return;
	
	stack<TreeNode*> levels[2];
	int currentNode = 0;
	int nextNode = 1;
	
	levels[currentNode].push(root);
	while (!levels[0].empty() || !levels[1].empty())
	{
		TreeNode* Node = levels[currentNode].top();
		levels[currentNode].pop();
		printf("%d ", Node->val);
		
		if (currentNode == NULL)
		{
			if (Node->left != NULL)
				levels[nextNode].push(Node->left);
			if (Node->right != NULL)
				levels[nextNode].push(Node->right);
		}
		else
		{
			if (Node->right != NULL)
				levels[nextNode].push(Node->right);
			if (Node->left != NULL)
				levels[nextNode].push(Node->left);
		}
		
		if (levels[currentNode].empty())
		{
			printf("\n");
			currentNode = 1 - currentNode;
			nextNode = 1- nextNode;
		}
	}
}


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
    printf("10 6 \n");
    printf("5 7 9 11 \n\n");

    printf("Actual Result is: \n");
    PrintInZigZag(pNode8);
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
    PrintInZigZag(pNode5);
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
    PrintInZigZag(pNode5);
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
    PrintInZigZag(pNode5);
    printf("\n");

    DestroyTree(pNode5);
}

void Test5()
{
    printf("====Test5 Begins: ====\n");
    printf("Expected Result is:\n");

    printf("Actual Result is: \n");
    PrintInZigZag(NULL);
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
    PrintInZigZag(pNode100);
    printf("\n");
}

//                8
//        4              12
//     2     6       10      14
//   1  3  5  7     9 11   13  15
void Test7()
{
    TreeNode* pNode8 = CreateTreeNode(8);
    TreeNode* pNode4 = CreateTreeNode(4);
    TreeNode* pNode12 = CreateTreeNode(12);
    TreeNode* pNode2 = CreateTreeNode(2);
    TreeNode* pNode6 = CreateTreeNode(6);
    TreeNode* pNode10 = CreateTreeNode(10);
    TreeNode* pNode14 = CreateTreeNode(14);
    TreeNode* pNode1 = CreateTreeNode(1);
    TreeNode* pNode3 = CreateTreeNode(3);
    TreeNode* pNode5 = CreateTreeNode(5);
    TreeNode* pNode7 = CreateTreeNode(7);
    TreeNode* pNode9 = CreateTreeNode(9);
    TreeNode* pNode11 = CreateTreeNode(11);
    TreeNode* pNode13 = CreateTreeNode(13);
    TreeNode* pNode15 = CreateTreeNode(15);

    ConnectTreeNodes(pNode8, pNode4, pNode12);
    ConnectTreeNodes(pNode4, pNode2, pNode6);
    ConnectTreeNodes(pNode12, pNode10, pNode14);
    ConnectTreeNodes(pNode2, pNode1, pNode3);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);
    ConnectTreeNodes(pNode14, pNode13, pNode15);

    printf("====Test7 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("8 \n");
    printf("12 4 \n");
    printf("2 6 10 14 \n");
    printf("15 13 11 9 7 5 3 1 \n\n");

    printf("Actual Result is: \n");
    PrintInZigZag(pNode8);
    printf("\n");

    DestroyTree(pNode8);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

	return 0;
}