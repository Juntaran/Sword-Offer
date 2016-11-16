/*************************************************************************
    > File Name: 06_MinNumberInRotatedArray.c
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年08月29日 星期一 20时14分22秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// O(n)解法
int minNumberInRotatedArray1(int* rotatedArray, int length)
{
	if (length <= 0)
		return 0;
	
	for (int i = 1; i < length; ++i)
	{
		if ( rotatedArray[i] < rotatedArray[i-1])
			return rotatedArray[i];
	}
	return rotatedArray[0];
}

// O(log(n))解法
int minNumberInRotatedArray2(int* rotatedArray, int length)
{
	if (length <= 0)
		return 0;
	if (length == 1)
		return rotatedArray[0];
	int left  = 0;
	int right = length - 1;
	int middle = 0;
	
	if (rotatedArray[left] < rotatedArray[right])
		return rotatedArray[0];
	
	while (rotatedArray[left] >= rotatedArray[right])
	{
		if (right - left == 1)
		{
			middle = right;
			break;
		}
		middle = (left + right) / 2;
		
		// 如果left、right、middle的值相同，只能顺序查找
		if (rotatedArray[left]==rotatedArray[middle] 
		&& rotatedArray[middle]==rotatedArray[right])
		{
			for (int i = left+1; i < right; ++i)
			{
				if (rotatedArray[i] < rotatedArray[i-1])
					return rotatedArray[i];
			}
			return rotatedArray[left];
		}
		
		if (rotatedArray[middle] >= rotatedArray[left])
			left = middle;
		else if (rotatedArray[middle] <= rotatedArray[right])
			right = middle;
	}
	return rotatedArray[middle];
}

int main()
{
	int rotatedArray1[] = {1,1,1,1,1,1,1};
	int rotatedArray2[] = {7,8,9,9,9,1,2};
	int rotatedArray3[] = {8,1,2,3,4,5,6};
	int rotatedArray4[] = {8,9,1,2,8,8,8,8,8,8};
	
	int length1 = 7;
	int length2 = 10;
	
	int ret1, ret2;
	
	ret1 = minNumberInRotatedArray1(rotatedArray1, length1);
	ret2 = minNumberInRotatedArray2(rotatedArray1, length1);
	printf("ret1 is %d, ret2 is %d\n", ret1, ret2);
	ret1 = minNumberInRotatedArray1(rotatedArray2, length1);
	ret2 = minNumberInRotatedArray2(rotatedArray2, length1);
	printf("ret1 is %d, ret2 is %d\n", ret1, ret2);
	ret1 = minNumberInRotatedArray1(rotatedArray3, length1);
	ret2 = minNumberInRotatedArray2(rotatedArray3, length1);
	printf("ret1 is %d, ret2 is %d\n", ret1, ret2);
	ret1 = minNumberInRotatedArray1(rotatedArray4, length2);
	ret2 = minNumberInRotatedArray2(rotatedArray4, length2);
	printf("ret1 is %d, ret2 is %d\n", ret1, ret2);
	
	return 0;
}