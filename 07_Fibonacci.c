/*************************************************************************
    > File Name: 07_Fibonacci.c
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年08月29日 星期一 20时23分54秒
 ************************************************************************/

#include <stdio.h>

long long Fibonacci1(int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	return Fibonacci1(n-2) + Fibonacci1(n-1);
}

long long Fibonacci2(int n)
{
	int result[2] = {0, 1};
	if (n < 2)
		return result[n];
	
	long long fibNum1 = 0;
	long long fibNum2 = 1;
	long long temp = 0;
	
	for (int i = 2; i <= n; ++i)
	{
		temp = fibNum1 + fibNum2;
		fibNum1 = fibNum2;
		fibNum2 = temp;
	}
	return temp;
}

int main()
{
	int n = 100;
	long long ret1, ret2;
	ret1 = Fibonacci1(n);
	ret2 = Fibonacci2(n);
	printf("ret1 is %lld, ret2 is %lld\n", ret1, ret2);
}