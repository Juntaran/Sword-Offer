/*************************************************************************
    > File Name: 57_NextNodeInBinaryTree.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年09月07日 星期三 20时05分07秒
 ************************************************************************/
 
#include <stdio.h>
#include <malloc.h>

// 二叉树结构体
struct BinaryTree
{
    int val;
    BinaryTree* left;
	BinaryTree* right;
	BinaryTree* parent;
};

// 中序遍历的下一个结点
BinaryTree* getNext(BinaryTree* node)
{
	if (node == NULL)
		return NULL;
	
	BinaryTree* Next = NULL;
	// 1. 存在右子树，那么下个结点就是右子树最左的结点
	if (node->right)
	{
		Next = node->right;
		while (Next->left)
			Next = Next->left;
	}
	/*
		2. 没有右子树，有两种情况
			a. 是父结点的左孩子： 父节点就是下一个结点
			b. 是父结点的右孩子： 不断找他父结点的父结点，
								  直到当前结点是其父结点的左孩子
								  如果没有，那么他是尾结点，下一个为NULL
	*/
	else if (node->parent)
	{
		BinaryTree* current = node;
		BinaryTree* Parent = node->parent;
		
		while (Parent && current==Parent->right)
		{
			current = Parent;
			Parent = Parent->parent;
		}
		Next = Parent;
	}
	
	return Next;
}

// ==================== Code for Binary Trees ====================
BinaryTree* CreateBinaryTree(int value)
{
    BinaryTree* pNode = new BinaryTree();
    pNode->val = value;
    pNode->left = NULL;
    pNode->right = NULL;
    pNode->parent = NULL;

    return pNode;
}

void ConnectTreeNodes(BinaryTree* pParent, BinaryTree* pLeft, BinaryTree* pRight)
{
    if(pParent != NULL)
    {
        pParent->left = pLeft;
        pParent->right = pRight;
        
        if(pLeft != NULL)
            pLeft->parent = pParent;
        if(pRight != NULL)
            pRight->parent = pParent;
    }
}

void PrintTreeNode(BinaryTree* pNode)
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

void PrintTree(BinaryTree* pRoot)
{
    PrintTreeNode(pRoot);

    if(pRoot != NULL)
    {
        if(pRoot->left != NULL)
            PrintTree(pRoot->left);

        if(pRoot->right != NULL)
            PrintTree(pRoot->right);
    }
}

void DestroyTree(BinaryTree* pRoot)
{
    if(pRoot != NULL)
    {
        BinaryTree* pLeft = pRoot->left;
        BinaryTree* pRight = pRoot->right;

        delete pRoot;
        pRoot = NULL;

        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}

// ==================== Test Code ====================
void Test(char* testName, BinaryTree* pNode, BinaryTree* expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);
        
    BinaryTree* pNext = getNext(pNode);
    if(pNext == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

//            8
//        6      10
//       5 7    9  11
void Test1_7()
{
    BinaryTree* pNode8 = CreateBinaryTree(8);
    BinaryTree* pNode6 = CreateBinaryTree(6);
    BinaryTree* pNode10 = CreateBinaryTree(10);
    BinaryTree* pNode5 = CreateBinaryTree(5);
    BinaryTree* pNode7 = CreateBinaryTree(7);
    BinaryTree* pNode9 = CreateBinaryTree(9);
    BinaryTree* pNode11 = CreateBinaryTree(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    Test("Test1", pNode8, pNode9);
    Test("Test2", pNode6, pNode7);
    Test("Test3", pNode10, pNode11);
    Test("Test4", pNode5, pNode6);
    Test("Test5", pNode7, pNode8);
    Test("Test6", pNode9, pNode10);
    Test("Test7", pNode11, NULL);

    DestroyTree(pNode8);
}

//            5
//          4
//        3
//      2
void Test8_11()
{
    BinaryTree* pNode5 = CreateBinaryTree(5);
    BinaryTree* pNode4 = CreateBinaryTree(4);
    BinaryTree* pNode3 = CreateBinaryTree(3);
    BinaryTree* pNode2 = CreateBinaryTree(2);

    ConnectTreeNodes(pNode5, pNode4, NULL);
    ConnectTreeNodes(pNode4, pNode3, NULL);
    ConnectTreeNodes(pNode3, pNode2, NULL);

    Test("Test8", pNode5, NULL);
    Test("Test9", pNode4, pNode5);
    Test("Test10", pNode3, pNode4);
    Test("Test11", pNode2, pNode3);

    DestroyTree(pNode5);
}

//        2
//         3
//          4
//           5
void Test12_15()
{
    BinaryTree* pNode2 = CreateBinaryTree(2);
    BinaryTree* pNode3 = CreateBinaryTree(3);
    BinaryTree* pNode4 = CreateBinaryTree(4);
    BinaryTree* pNode5 = CreateBinaryTree(5);

    ConnectTreeNodes(pNode2, NULL, pNode3);
    ConnectTreeNodes(pNode3, NULL, pNode4);
    ConnectTreeNodes(pNode4, NULL, pNode5);

    Test("Test12", pNode5, NULL);
    Test("Test13", pNode4, pNode5);
    Test("Test14", pNode3, pNode4);
    Test("Test15", pNode2, pNode3);

    DestroyTree(pNode2);
}

void Test16()
{
    BinaryTree* pNode5 = CreateBinaryTree(5);

    Test("Test16", pNode5, NULL);

    DestroyTree(pNode5);
}

int main(int argc, char* argv[])
{
    Test1_7();
    Test8_11();
    Test12_15();
    Test16();
}