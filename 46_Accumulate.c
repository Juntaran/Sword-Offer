/*************************************************************************
    > File Name: 46_Accumulate.c
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年09月04日 星期日 21时18分28秒
 ************************************************************************/
 
#include <stdio.h>

// 函数指针法求1+2+...+n
typedef unsigned int (*fun)(unsigned int);

unsigned int sum_T(int n)
{
	return 0;
}

int Sum1(int n)
{
	static fun f[2] = {sum_T, Sum1};
	return n + f[!!n](n-1);
}

// 递归
int Sum2(int n)
{
	int sum = n;
	int ans = (n>0) && (sum+=Sum2(n-1));
	return sum;
}

int main()
{
	int n = 7;
	int ret1 = Sum1(n);
	int ret2 = Sum2(n);
	printf("ret1 is %d\n", ret1);
	printf("ret2 is %d\n", ret2);
	
	return 0;
}