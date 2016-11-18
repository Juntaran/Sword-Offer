/*************************************************************************
    > File Name: 50_DuplicationInArray.c
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016��09��05�� ����һ 17ʱ14��11��
 ************************************************************************/

#include <stdio.h>

// �ڳ�Ϊn�����飬������Ԫ�ض���0-(n-1)��Χ�ڣ�Ѱ��һ���ظ�������
int Find1(int* nums, int n)
{
	if (nums==NULL || n<=0)
		return -1;
	
	for (int i = 0; i < n; ++i)
	{
		if (nums[i] >= n)
			continue;
		
		if (nums[nums[i]] >= n)
			return nums[i];
		
		nums[nums[i]] += n;
	}
	return -1;
}

int Find2(int* nums, int n)
{
	if (nums==NULL || n<=0)
		return -1;
	
	for (int i = 0; i < n; ++i)
	{
		while (nums[i] != i)
		{
			if (nums[i] == nums[nums[i]])
				return nums[i];
			
			int temp = nums[i];
			nums[i] = nums[temp];
			nums[temp] = temp;
		}
	}
	return -1;
}

int main()
{
	int nums[] = {6,6,6,6,6,6,6};
	int n = 7;
	int ret = Find2(nums, n);
	printf("ret is %d\n", ret);
	
	return 0;
}