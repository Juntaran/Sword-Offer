/*************************************************************************
	> File Name: 10_PrintToMaxNum.c
	> Author: Juntaran
	> Mail: JuntaranMail@gmail.com
	> Created Time: 2016年08月30日 星期二 00时47分36秒
 ************************************************************************/

#include <stdio.h>
#include <malloc.h>
#include <string.h>


void PrintNumber(char* number)
{
	bool isBeginning0 = true;
	int length = strlen(number);
	
	for (int i = 0; i < length; ++i)
	{
		if (isBeginning0 && number[i]!='0')
			isBeginning0 = false;
		
		if (!isBeginning0)
			printf("%c", number[i]);
	}
	printf("\t");
}


bool Increment(char* number)
{
	bool isOverflow = false;
	int length = strlen(number);
	int TakeOver = 0;
	
	for (int i = length-1; i >= 0; i--)
	{
		int sum = number[i] - '0' + TakeOver;	// 进位
		if (i == length - 1)
			sum ++;
		
		if (sum >= 10)
		{
			if (i == 0)
				isOverflow = true;
			else
			{
				sum -= 10;
				TakeOver = 1;
				number[i] = sum + '0';
			}
		}
		else
		{
			number[i] = sum + '0';
			break;
		}
	}
	return isOverflow;
}

// 从1打印到最大的n位数
void PrintToMaxNum1(int n)
{
	if (n <= 0)
		return;
	
	char* number = (char*)malloc(sizeof(char)*(n+1));
	memset(number, '0', n);
	number[n] = '\0';
	
	while (!Increment(number))
	{
		PrintNumber(number);
	}
	free(number);
}


/************************************************************************/
// 递归写法
void PrintToMaxNumRecursively(char* number, int length, int index)
{
	if (index == length-1)
	{
		PrintNumber(number);
		return;
	}
	for (int i = 0; i < 10; ++i)
	{
		number[index+1] = i + '0';
		PrintToMaxNumRecursively(number, length, index+1);
	}
}

void PrintToMaxNum2(int n)
{
	if (n <= 0)
		return;
	
	char* number = (char*)malloc(sizeof(char)*(n+1));
	number[n] = '\0';
	
	for (int i = 0; i < 10; ++i)
	{
		number[0] = i + '0';
		PrintToMaxNumRecursively(number, n, 0);
	}
	free(number);
}


int main()
{
	int n = 5;
	PrintToMaxNum1(n);
	PrintToMaxNum2(n);
}