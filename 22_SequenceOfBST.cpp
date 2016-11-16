/*************************************************************************
    > File Name: 22_SequenceOfBST.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年08月30日 星期二 20时34分33秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// 判断一个数组是不是某个二叉搜索树的后序遍历
bool isSequenceOfBST(int* sequence, int length)
{
	if (sequence==NULL || length<=0)
		return false;
	
	int root = sequence[length-1];
	
	int i, j;
	
	// 二叉搜索树的左子树都小于根
	for (i = 0; i < length-1; ++i)
	{
		if (sequence[i] > root)
			break;
	}
	
	// 二叉搜索树的右子树都大于根
	for (j = i; j < length-1; ++j)
	{
		if (sequence[j] < root)
			return false;
	}
	
	// 递归判断左子树是不是二叉搜索树
	bool left = true;
	if (i > 0)
		left = isSequenceOfBST(sequence, i);
	
	// 递归判断右子树是不是二叉搜索树
	bool right = true;
	if (i < length-1)
		right = isSequenceOfBST(sequence+i, length-i-1);
	
	return (left && right);
}

int main()
{
	int sequence1[] = {5,7,6,9,11,10,8};
	int sequence2[] = {7,4,5,6};
	bool ret1 = isSequenceOfBST(sequence1, 7);
	bool ret2 = isSequenceOfBST(sequence2, 4);
	if (ret1 == true)
		printf("ret1 is true\n");
	else
		printf("ret1 is false\n");
	
	if (ret2 == true)
		printf("ret2 is true\n");
	else
		printf("ret2 is false\n");
	
	return 0;
}