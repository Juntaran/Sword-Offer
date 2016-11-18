/*************************************************************************
    > File Name: 38_NumbersAppearOnce.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016��09��03�� ������ 10ʱ50��32��
 ************************************************************************/

#include <stdio.h>

// �ж����ֶ����ƴ��������indexλ�ǲ���1
bool isBit(int num, int index)
{
	num = num >> index;
	return (num & 1);
}

// �������ֳ������Σ�ֻ������������һ�Σ��ҳ�����������
void FindNumsAppearOnce(int* nums, int length, int* num1, int* num2)
{
	if (nums==NULL || length<=2)
		return;
	
	int temp = nums[0];
	// ��һ�����
	for (int i = 1; i < length; ++i)
		temp ^= nums[i];
	
	// ��������Ѱ��temp�����Ƶڼ�λ��1
	int index = 0;
	while ((temp & 1) == 0)
	{
		temp = temp >> 1;
		++ index;
	}
	
	
	*num1 = 0;
	*num2 = 0;
	
	// �������
	for (int i = 0; i < length; ++i)
	{
		if (isBit(nums[i], index))
			*num1 ^= nums[i];
		else
			*num2 ^= nums[i];
	}
}

int main()
{
	int nums[] = {2,4,3,6,3,2,5,5};
	int length = 8;
	int num1 = 0;
	int num2 = 0;
	FindNumsAppearOnce(nums, length, &num1, &num2);
	printf("num1 is %d\nnum2 is %d\n", num1, num2);
	return 0;
}