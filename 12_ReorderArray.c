/*************************************************************************
    > File Name: 12_ReorderArray.c
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年08月30日 星期二 15时15分42秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// 所有奇数放在偶数前面
void ReorderOddEven(int* nums, int length)
{
	if (length <= 0)
		return;
	
	int left  = 0;
	int right = length - 1;
	
	while (left < right)
	{
		// 从左向右找第一个偶数
		while (nums[left] % 2 != 0)
			left ++;
		
		// 从右向左找第一个奇数
		while (nums[right] %2 == 0)
			right --;
		
		if (left < right)
		{
			int temp = nums[left];
			nums[left]  = nums[right];
			nums[right] = temp;
		}
	}
}

void PrintNums(int* nums, int length)
{
	for (int i = 0; i < length; ++i)
		printf("%d ", nums[i]);
	
	printf("\n");
}

int main()
{
	int nums[] = {1, 2, 3, 4, 5, 6};
	int length = 6;
	
	PrintNums(nums, length);
	ReorderOddEven(nums, length);
	PrintNums(nums, length);
	
	return 0;
}