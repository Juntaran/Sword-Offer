/*************************************************************************
    > File Name: 18_PrintMatrixClock.c
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年08月30日 星期二 17时32分28秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define COL 4
#define ROW 1

void PrintMatrixCircle(int nums[][COL], int col, int row, int start)
{
	// 从左到右打一行
	for (int i = start; i < col-start; ++i)
	{
		int number = nums[start][i];
		printf("%d ", number);
	}
	
	// 从上到下打一列
	if (start < row-start-1)
	{
		for (int i = start + 1; i < row-start; ++i)
		{
			int number = nums[i][start];
			printf("%d ", number);
		}
	}
	
	// 从右到左打一行
	if (start < col-start-1 && start < row-start-1)
	{
		for (int i = col-start-2; i >= start; --i)
		{
			int number = nums[row-start-1][i];
			printf("%d ", number);
		}
	}
	
	// 从下到上打一列
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