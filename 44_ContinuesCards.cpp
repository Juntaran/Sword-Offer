/*************************************************************************
    > File Name: 44_ContinuesCards.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016��09��04�� ������ 19ʱ55��44��
 ************************************************************************/
 
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

bool isContinues(int* nums, int length)
{
	if (nums==NULL || length!=5)
		return false;
	
	qsort(nums, length, sizeof(int), cmp);
	
	int ZeroNum = 0;
	int GapNum  = 0;
	
	for (int i = 0; i < length; ++i)
	{
		if (nums[i] == 0)
			ZeroNum ++;
		
		if (ZeroNum > 2)			// ��С���������
			return false;
		
		if (i >= 1)
		{
			if (nums[i]!=0 && (nums[i]-nums[i-1])==0)
				return false;		// �ظ�����
			
			if (nums[i-1]!=0 && (nums[i]-nums[i-1])>1)
				GapNum += nums[i]-nums[i-1] - 1;
		}
	}
	
	if (GapNum > ZeroNum)
		return false;
	
	return true;
}

int main()
{
	int nums[] = {4, 5, 0, 2, 0};
	int length = 5;
	
	if (isContinues(nums, length))
		printf("True\n");
	else
		printf("False\n");
	return 0;
}