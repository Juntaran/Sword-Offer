/*************************************************************************
    > File Name: 32_UglyNumber.c
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年09月02日 星期五 12时29分59秒
 ************************************************************************/

#include <stdio.h>
#include <malloc.h>

int isUgly(int number)
{
	while (number % 2 == 0)
		number /= 2;
	while (number % 3 == 0)
		number /= 3;
	while (number % 5 == 0)
		number /= 5;
	
	return (number==1) ? 0 : -1;
}

// 低效方法
int getUglyNumber1(int n)
{
	if (n <= 0)
		return -1;
	
	int number = 0;
	while (n != 0)
	{
		++ number;
		if (isUgly(number) == 0)
			n --; 
	}
	printf("%d\n", number);
	return number;
}

int MinOfThree(int a, int b, int c)
{
	int minNum = a>b ? b : a;
	minNum = minNum>c ? c : minNum;
	return minNum;
}

// 高效方法 空间换时间
int getUglyNumber2(int index)
{
	if (index <= 1)
		return index;
	
	int* ugly = (int*)malloc(sizeof(int) * index);
	int i2 = 0;
	int i3 = 0;
	int i5 = 0;
	ugly[0] = 1;
	
	for (int i = 1; i < index; ++i)
	{
		int temp2 = ugly[i2] * 2;
		int temp3 = ugly[i3] * 3;
		int temp5 = ugly[i5] * 5;
		
		int minNum = MinOfThree(temp2, temp3, temp5);
		ugly[i] = minNum;
		
		if (minNum == temp2)
			i2 ++;
		if (minNum == temp3)
			i3 ++;
		if (minNum == temp5)
			i5 ++;
	}
	printf("%d\n", ugly[index - 1]);
	return ugly[index - 1];
}

int main()
{
	getUglyNumber1(1500);
	getUglyNumber2(1500);
}