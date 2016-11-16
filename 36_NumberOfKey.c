/*************************************************************************
    > File Name: 36_NumberOfKey.c
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年09月03日 星期六 09时32分10秒
 ************************************************************************/

#include <stdio.h>

// 寻找第一个Key的下标
int GetFirstKey(int* nums, int length, int key, int left, int right)
{
	if (nums==NULL || length<=0 || left>right)
		return -1;
	
	int middle = (left + right) / 2;
	if (key == nums[middle])
	{
		if ((middle>0 && nums[middle-1]!=key) || middle==0)
			return middle;
		else
			right = middle - 1;
	}
	else if (key > nums[middle])
		left = middle + 1;
	else
		right = middle - 1;
	
	return GetFirstKey(nums, length, key, left, right);
}

// 寻找最后一个Key的下标
int GetLastKey(int* nums, int length, int key, int left, int right)
{
	if (nums==NULL || length<=0 || left>right)
		return -1;
	
	int middle = (left + right) / 2;
	if (key == nums[middle])
	{
		if ((middle>0 && nums[middle+1]!=key && middle<length) || middle==length-1)
			return middle;
		else
			left = middle + 1;
	}
	else if (key > nums[middle])
		left = middle + 1;
	else
		right = middle - 1;
	
	return GetLastKey(nums, length, key, left, right);
}

int GetNumberOfKey(int* nums, int length, int key)
{
	int count = 0;
	if (nums==NULL || length<=0)
		return 0;
	
	int first = GetFirstKey(nums, length, key, 0, length-1);
	int last  = GetLastKey( nums, length, key, 0, length-1);
	
	if (first>=0 && last>=0)
		count = last - first + 1;
	
	printf("count is %d\n", count);
	return count;
}

int main()
{
	int nums[] = {1, 2, 3, 3, 3, 3, 4, 5};
	int length = 8;
	int key = 3;
	
	GetNumberOfKey(nums, length, key);
}