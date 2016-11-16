/*************************************************************************
    > File Name: 40_ContinuesSequenceWithSum.c
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年09月04日 星期日 15时52分42秒
 ************************************************************************/

#include <stdio.h>

void PrintSmallToBig(int left, int right)
{
	for (int i = left; i <= right; ++i)
		printf("%d ", i);
	printf("\n");
}

// 输出所有和为sum的连续正数序列，至少两个数
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