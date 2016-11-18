/*************************************************************************
    > File Name: 40_ContinuesSequenceWithSum.c
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016��09��04�� ������ 15ʱ52��42��
 ************************************************************************/

#include <stdio.h>

void PrintSmallToBig(int left, int right)
{
	for (int i = left; i <= right; ++i)
		printf("%d ", i);
	printf("\n");
}

// ������к�Ϊsum�������������У�����������
void FindContinuesSequence(int sum)
{
	if (sum < 3)
		return;
	
	int left = 1;
	int right = 2;
	int middle = (1 + sum) / 2;
	int current = left + right;
	
	while (left < middle)
	{
		if (current == sum)
			PrintSmallToBig(left, right);
		
		while (current>sum && left<right)
		{
			current -= left;
			left ++;
			
			if (current == sum)
				PrintSmallToBig(left, right);
		}
		right ++;
		current += right;
	}
}

int main()
{
	int sum = 9;
	FindContinuesSequence(sum);
	
	return 0;
}