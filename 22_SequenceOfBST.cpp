/*************************************************************************
    > File Name: 22_SequenceOfBST.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016��08��30�� ���ڶ� 20ʱ34��33��
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// �ж�һ�������ǲ���ĳ�������������ĺ������
bool isSequenceOfBST(int* sequence, int length)
{
	if (sequence==NULL || length<=0)
		return false;
	
	int root = sequence[length-1];
	
	int i, j;
	
	// ��������������������С�ڸ�
	for (i = 0; i < length-1; ++i)
	{
		if (sequence[i] > root)
			break;
	}
	
	// �����������������������ڸ�
	for (j = i; j < length-1; ++j)
	{
		if (sequence[j] < root)
			return false;
	}
	
	// �ݹ��ж��������ǲ��Ƕ���������
	bool left = true;
	if (i > 0)
		left = isSequenceOfBST(sequence, i);
	
	// �ݹ��ж��������ǲ��Ƕ���������
	bool right = true;
	if (i < length-1)
		right = isSequenceOfBST(sequence+i, length-i-1);
	
	return (left && right);
}

int main()
{
	int sequence1[] = {5,7,6,9,11,10,8};
	int sequence2[] = {7,4,5,6};
	bool ret1 = isSequenceOfBST(sequence1, 7);
	bool ret2 = isSequenceOfBST(sequence2, 4);
	if (ret1 == true)
		printf("ret1 is true\n");
	else
		printf("ret1 is false\n");
	
	if (ret2 == true)
		printf("ret2 is true\n");
	else
		printf("ret2 is false\n");
	
	return 0;
}