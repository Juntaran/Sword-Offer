/*************************************************************************
    > File Name: 12_ReorderArray.c
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016��08��30�� ���ڶ� 15ʱ15��42��
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// ������������ż��ǰ��
void ReorderOddEven(int* nums, int length)
{
	if (length <= 0)
		return;
	
	int left  = 0;
	int right = length - 1;
	
	while (left < right)
	{
		// ���������ҵ�һ��ż��
		while (nums[left] % 2 != 0)
			left ++;
		
		// ���������ҵ�һ������
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