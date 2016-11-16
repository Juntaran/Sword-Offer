/*************************************************************************
    > File Name: 34_InversePairsInArray.c
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年09月02日 星期五 20时05分05秒
 ************************************************************************/

#include <stdio.h>
#include <malloc.h>

int InversePairsCore(int* nums, int* copy, int left, int right)
{
	if (left == right)
	{
		copy[left] = copy[right];
		return 0;
	}
	int newlength = (right - left) / 2;
	
	// 递归
	int leftCount  = InversePairsCore(copy, nums, left, left+newlength);
	int rightCount = InversePairsCore(copy, nums, left+newlength+1, right);
	
	// i初始化为前半段最后一个数字下标
	int i = left + newlength;
	// j初始化为后半段最后一个数字下标
	int j = right;
	
	int indexCopy = right;
	int count = 0;
	
	while (i>=left && j>=left+newlength+1)
	{
		if (nums[i] > nums[j])
		{
			copy[indexCopy--] = nums[i--];
			count += j - left - newlength;
		}
		else
		{
			copy[indexCopy--] = nums[j--];
		}
	}
	
	for (i; i >= left; --i)
		copy[indexCopy--] = nums[i];
	for (j; j>=left+newlength+1; --j)
		copy[indexCopy--] = nums[j];
	
	return leftCount + rightCount + count;
}

int InversePairs(int* nums, int length)
{
	if (nums==NULL || length<=0)
		return -1;
	
	int* copy = (int*)malloc(sizeof(int)*length);
	for (int i = 0; i < length; ++i)
		copy[i] = nums[i];
	
	int count = InversePairsCore(nums, copy, 0, length-1);
	delete[] copy;
	
	return count;
}

int main()
{
	int nums[] = {7,5,6,4};
	int length = 4;
	int ret = InversePairs(nums, length);
	printf("%d\n", ret);
}