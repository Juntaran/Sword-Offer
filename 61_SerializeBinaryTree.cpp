/*************************************************************************
    > File Name: 60_SerializeBinaryTree.cpp
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


