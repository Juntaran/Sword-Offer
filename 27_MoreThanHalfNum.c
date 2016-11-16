/*************************************************************************
    > File Name: 27_MoreThanHalfNum.c
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年08月31日 星期三 16时40分55秒
 ************************************************************************/

#include <stdio.h>

int FindNum(int* nums, int length)
{
	if (nums==NULL || length<=0)
		return -1;
	
	int ret = nums[0];
	int count = 1;
	for (int i = 0; i < length; ++i)
	{
		if (nums[i] == ret)
			count ++;
		else
			count --;
		if (count == 0)
		{
			ret = nums[i];
			count = 1;
		}
	}
	
	// 检验是否正确
	int count2 = 0;
	for (int i = 0; i < length; ++i)
	{
		if (nums[i] == ret)
			count2 ++;
	}
	if (count2*2 > length)
		return ret;
	else
		return -1;
}

int main()
{
	int nums[] = {1,2,3,2,2,2,5,4,2};
	int length = 9;
	int ret = FindNum(nums, length);
	if (ret == -1)
		printf("Not Find\n");
	else
		printf("ret is %d\n", ret);
	
	return 0;
}