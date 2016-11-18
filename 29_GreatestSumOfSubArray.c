/*************************************************************************
    > File Name: 29_GreatestSumOfSubArray.c
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016��09��01�� ������ 20ʱ37��22��
 ************************************************************************/

#include <stdio.h>

int FindGreatestSumOfSubArray(int* nums, int length)
{
	if (nums==NULL || length<=0)
	{
		printf("error\n");
		return -1;
	}
	
	int CurSum = 0;
	int MaxSum = 0;
	
	for (int i = 0; i < length; ++i)
	{
		if (CurSum <= 0)
			CurSum = nums[i];
		else
			CurSum += nums[i];
		
		if (CurSum > MaxSum)
			MaxSum = CurSum;
	}
	printf("MaxSum is %d\n", MaxSum);
	return MaxSum;
}

int main()
{
	int nums[] = {1,-2,3,10,-4,7,2,-5};
	int length = 8;
	FindGreatestSumOfSubArray(nums, length);
}