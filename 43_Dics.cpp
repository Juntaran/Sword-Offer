/*************************************************************************
    > File Name: 43_Dics.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年09月04日 星期日 16时46分00秒
 ************************************************************************/

#define maxNum 6 	// 骰子最多为6
 
#include <stdio.h>
#include <math.h>

void PrintDics(int number)
{
	if (number < 1)
		return;
	
	int* Probabilities[2];
	Probabilities[0] = new int[maxNum * number + 1];
	Probabilities[1] = new int[maxNum * number + 1];
	
	
	for (int i = 0; i < maxNum*number+1; ++i)
	{
		Probabilities[0][i] = 0;
		Probabilities[1][i] = 0;
	}
	int flag = 0;
	for (int i = 1; i <= maxNum; ++i)
		Probabilities[flag][i] = 1;
	
	
	for (int k = 2; k <= number; ++k)
	{
		for (int i = 0; i < k; ++i)
			Probabilities[1-flag][i] = 0;
		for (int i = k; i <= maxNum*k; ++i)
		{
			Probabilities[1-flag][i] = 0;
			for (int j = 1; j<=i&&j<=maxNum; ++j)
				Probabilities[1-flag][i] += Probabilities[flag][i-j];
		}
		flag = 1 - flag;
	}
	
	double total = pow((double)maxNum, number);
	for (int i = number; i <= maxNum*number; ++i)
	{
		double ratio = (double)Probabilities[flag][i] / total;
		printf("%d: %f\n", i, ratio);
	}
	delete[] Probabilities[0];
	delete[] Probabilities[1];
}

int main()
{
	int number = 5;
	PrintDics(number);
}