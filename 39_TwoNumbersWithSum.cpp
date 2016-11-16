/*************************************************************************
    > File Name: 39_TwoNumbersWithSum.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年09月03日 星期六 11时14分49秒
 ************************************************************************/

#include <stdio.h>

bool FindNumberWithSum(int* nums, int length, int sum, int* num1, int* num2)
{
	bool ret = false;
	if (length<1 || num1==NULL || num2==NULL)
		return ret;
	
	int left  = 0;
	int right = length - 1;
	
	while (right > left)
	{
		int current = nums[left] + nums[right];
		if (current == sum)
		{
			*num1 = nums[left];
			*num2 = nums[right];
			ret = true;
			return ret;
		}
		else if (current > sum)
			right --;
		else
			left ++;
	}
	return ret;
}

int main()
{
	int nums[] = {1,2,4,7,11,15};
	int length = 6;
	int sum = 15;
	int num1, num2;
	
	if (FindNumberWithSum(nums, length, sum, &num1, &num2))
		printf("%d, %d\n", num1, num2);
	else
		printf("Not Find\n");
	return 0;
}