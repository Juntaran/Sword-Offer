/*************************************************************************
    > File Name: 58_SymmetricalBinaryTree.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年09月07日 星期三 20时22分42秒
 ************************************************************************/
 
#include <stdio.h>
#include <malloc.h>

// 二叉树结构体
struct BinaryTree
{
    int val;
    BinaryTree* left;
	BinaryTree* right;
};

BinaryTree* CreateBinaryTree(int value)
{
    BinaryTree* pNode = new BinaryTree();
    pNode->val = value;
    pNode->left = NULL;
    pNode->right = NULL;

    return pNode;
}

void ConnectTreeNodes(BinaryTree* pParent, BinaryTree* pLeft, BinaryTree* pRight)
{
    if(pParent != NULL)
    {
        pParent->left = pLeft;
        pParent->right = pRight;
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

// 判断是否对称
bool isSymmetricalBinaryTree(BinaryTree* Left, BinaryTree* Right)
{
	if (Left==NULL && Right==NULL)
		return true;
	
	if (Left==NULL || Right==NULL)
		return false;
	
	if (Left->val != Right->val)
		return false;
	
	return isSymmetricalBinaryTree(Left->left, Right->right)
		&& isSymmetricalBinaryTree(Left->right, Right->left);
}

bool isSymmetricalBinaryTree(BinaryTree* root)
{
	return isSymmetricalBinaryTree(root, root);
}

// ==================== Test Code ====================
void Test(char* testName, BinaryTree* pRoot, bool expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(isSymmetricalBinaryTree(pRoot) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

//            8
//        6      6
//       5 7    7 5
void Test1()
{
    BinaryTree* pNode8 = CreateBinaryTree(8);
    BinaryTree* pNode61 = CreateBinaryTree(6);
    BinaryTree* pNode62 = CreateBinaryTree(6);
    BinaryTree* pNode51 = CreateBinaryTree(5);
    BinaryTree* pNode71 = CreateBinaryTree(7);
    BinaryTree* pNode72 = CreateBinaryTree(7);
    BinaryTree* pNode52 = CreateBinaryTree(5);

    ConnectTreeNodes(pNode8, pNode61, pNode62);
    ConnectTreeNodes(pNode61, pNode51, pNode71);
    ConnectTreeNodes(pNode62, pNode72, pNode52);

    Test("Test1", pNode8, true);

    DestroyTree(pNode8);
}

//            8
//        6      9
//       5 7    7 5
void Test2()
{
    BinaryTree* pNode8 = CreateBinaryTree(8);
    BinaryTree* pNode61 = CreateBinaryTree(6);
    BinaryTree* pNode9 = CreateBinaryTree(9);
    BinaryTree* pNode51 = CreateBinaryTree(5);
    BinaryTree* pNode71 = CreateBinaryTree(7);
    BinaryTree* pNode72 = CreateBinaryTree(7);
    BinaryTree* pNode52 = CreateBinaryTree(5);

    ConnectTreeNodes(pNode8, pNode61, pNode9);
    ConnectTreeNodes(pNode61, pNode51, pNode71);
    ConnectTreeNodes(pNode9, pNode72, pNode52);

    Test("Test2", pNode8, false);

    DestroyTree(pNode8);
}

//            8
//        6      6
//       5 7    7
void Test3()
{
    BinaryTree* pNode8 = CreateBinaryTree(8);
    BinaryTree* pNode61 = CreateBinaryTree(6);
    BinaryTree* pNode62 = CreateBinaryTree(6);
    BinaryTree* pNode51 = CreateBinaryTree(5);
    BinaryTree* pNode71 = CreateBinaryTree(7);
    BinaryTree* pNode72 = CreateBinaryTree(7);

    ConnectTreeNodes(pNode8, pNode61, pNode62);
    ConnectTreeNodes(pNode61, pNode51, pNode71);
    ConnectTreeNodes(pNode62, pNode72, NULL);

    Test("Test3", pNode8, false);

    DestroyTree(pNode8);
}

//               5
//              / \
//             3   3
//            /     \
//           4       4
//          /         \
//         2           2
//        /             \
//       1               1
void Test4()
{
    BinaryTree* pNode5 = CreateBinaryTree(5);
    BinaryTree* pNode31 = CreateBinaryTree(3);
    BinaryTree* pNode32 = CreateBinaryTree(3);
    BinaryTree* pNode41 = CreateBinaryTree(4);
    BinaryTree* pNode42 = CreateBinaryTree(4);
    BinaryTree* pNode21 = CreateBinaryTree(2);
    BinaryTree* pNode22 = CreateBinaryTree(2);
    BinaryTree* pNode11 = CreateBinaryTree(1);
    BinaryTree* pNode12 = CreateBinaryTree(1);

    ConnectTreeNodes(pNode5, pNode31, pNode32);
    ConnectTreeNodes(pNode31, pNode41, NULL);
    ConnectTreeNodes(pNode32, NULL, pNode42);
    ConnectTreeNodes(pNode41, pNode21, NULL);
    ConnectTreeNodes(pNode42, NULL, pNode22);
    ConnectTreeNodes(pNode21, pNode11, NULL);
    ConnectTreeNodes(pNode22, NULL, pNode12);

    Test("Test4", pNode5, true);

    DestroyTree(pNode5);
}


//               5
//              / \
//             3   3
//            /     \
//           4       4
//          /         \
//         6           2
//        /             \
//       1               1
void Test5()
{
    BinaryTree* pNode5 = CreateBinaryTree(5);
    BinaryTree* pNode31 = CreateBinaryTree(3);
    BinaryTree* pNode32 = CreateBinaryTree(3);
    BinaryTree* pNode41 = CreateBinaryTree(4);
    BinaryTree* pNode42 = CreateBinaryTree(4);
    BinaryTree* pNode6 = CreateBinaryTree(6);
    BinaryTree* pNode22 = CreateBinaryTree(2);
    BinaryTree* pNode11 = CreateBinaryTree(1);
    BinaryTree* pNode12 = CreateBinaryTree(1);

    ConnectTreeNodes(pNode5, pNode31, pNode32);
    ConnectTreeNodes(pNode31, pNode41, NULL);
    ConnectTreeNodes(pNode32, NULL, pNode42);
    ConnectTreeNodes(pNode41, pNode6, NULL);
    ConnectTreeNodes(pNode42, NULL, pNode22);
    ConnectTreeNodes(pNode6, pNode11, NULL);
    ConnectTreeNodes(pNode22, NULL, pNode12);

    Test("Test5", pNode5, false);

    DestroyTree(pNode5);
}

//               5
//              / \
//             3   3
//            /     \
//           4       4
//          /         \
//         2           2
//                      \
//                       1
void Test6()
{
    BinaryTree* pNode5  = CreateBinaryTree(5);
    BinaryTree* pNode31 = CreateBinaryTree(3);
    BinaryTree* pNode32 = CreateBinaryTree(3);
    BinaryTree* pNode41 = CreateBinaryTree(4);
    BinaryTree* pNode42 = CreateBinaryTree(4);
    BinaryTree* pNode21 = CreateBinaryTree(2);
    BinaryTree* pNode22 = CreateBinaryTree(2);
    BinaryTree* pNode12 = CreateBinaryTree(1);

    ConnectTreeNodes(pNode5, pNode31, pNode32);
    ConnectTreeNodes(pNode31, pNode41, NULL);
    ConnectTreeNodes(pNode32, NULL, pNode42);
    ConnectTreeNodes(pNode41, pNode21, NULL);
    ConnectTreeNodes(pNode42, NULL, pNode22);
    ConnectTreeNodes(pNode21, NULL, NULL);
    ConnectTreeNodes(pNode22, NULL, pNode12);

    Test("Test6", pNode5, false);

    DestroyTree(pNode5);
}

// Only one node
void Test7()
{
    BinaryTree* pNode1 = CreateBinaryTree(1);
    Test("Test7", pNode1, true);

    DestroyTree(pNode1);
}

// No nodes
void Test8()
{
    Test("Test8", NULL, true);
}

// All nodes have the same value
//               5
//              / \
//             5   5
//            /     \
//           5       5
//          /         \
//         5           5
void Test9()
{
    BinaryTree* pNode1 = CreateBinaryTree(5);
    BinaryTree* pNode21 = CreateBinaryTree(5);
    BinaryTree* pNode22 = CreateBinaryTree(5);
    BinaryTree* pNode31 = CreateBinaryTree(5);
    BinaryTree* pNode32 = CreateBinaryTree(5);
    BinaryTree* pNode41 = CreateBinaryTree(5);
    BinaryTree* pNode42 = CreateBinaryTree(5);

    ConnectTreeNodes(pNode1, pNode21, pNode22);
    ConnectTreeNodes(pNode21, pNode31, NULL);
    ConnectTreeNodes(pNode22, NULL, pNode32);
    ConnectTreeNodes(pNode31, pNode41, NULL);
    ConnectTreeNodes(pNode32, NULL, pNode42);
    ConnectTreeNodes(pNode41, NULL, NULL);
    ConnectTreeNodes(pNode42, NULL, NULL);

    Test("Test9", pNode1, true);

    DestroyTree(pNode1);
}

// All nodes have the same value
//               5
//              / \
//             5   5
//            /     \
//           5       5
//          /       /
//         5       5
void Test10()
{
    BinaryTree* pNode1 = CreateBinaryTree(5);
    BinaryTree* pNode21 = CreateBinaryTree(5);
    BinaryTree* pNode22 = CreateBinaryTree(5);
    BinaryTree* pNode31 = CreateBinaryTree(5);
    BinaryTree* pNode32 = CreateBinaryTree(5);
    BinaryTree* pNode41 = CreateBinaryTree(5);
    BinaryTree* pNode42 = CreateBinaryTree(5);

    ConnectTreeNodes(pNode1, pNode21, pNode22);
    ConnectTreeNodes(pNode21, pNode31, NULL);
    ConnectTreeNodes(pNode22, NULL, pNode32);
    ConnectTreeNodes(pNode31, pNode41, NULL);
    ConnectTreeNodes(pNode32, pNode42, NULL);
    ConnectTreeNodes(pNode41, NULL, NULL);
    ConnectTreeNodes(pNode42, NULL, NULL);

    Test("Test10", pNode1, false);

    DestroyTree(pNode1);
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
    Test8();
    Test9();
    Test10();
	
	return 0;
}