/*************************************************************************
    > File Name: 18_PrintMatrixClock.c
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016��08��30�� ���ڶ� 17ʱ32��28��
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define COL 4
#define ROW 1

void PrintMatrixCircle(int nums[][COL], int col, int row, int start)
{
	// �����Ҵ�һ��
	for (int i = start; i < col-start; ++i)
	{
		int number = nums[start][i];
		printf("%d ", number);
	}
	
	// ���ϵ��´�һ��
	if (start < row-start-1)
	{
		for (int i = start + 1; i < row-start; ++i)
		{
			int number = nums[i][start];
			printf("%d ", number);
		}
	}
	
	// ���ҵ����һ��
	if (start < col-start-1 && start < row-start-1)
	{
		for (int i = col-start-2; i >= start; --i)
		{
			int number = nums[row-start-1][i];
			printf("%d ", number);
		}
	}
	
	// ���µ��ϴ�һ��
	if (start < col-start-1 && start < row-start-2)
	{
		for (int i = row-start-2; i >= start + 1; --i)
		{
			int number = nums[i][start];
			printf("%d ", number);
		}
	}
}

void PrintMatrixClock(int nums[][COL], int col, int row)
{
	if (nums==NULL || col<=0 || row<=0)
		return;
	int start = 0;
	
	while (col>start*2 && row>start*2)
	{
		PrintMatrixCircle(nums, col, row, start);
		++start;
	}
}

int main()
{
	int nums[ROW][COL] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	
	PrintMatrixClock(nums, COL, ROW);
	
	return 0;
}