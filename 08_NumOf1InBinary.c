/*************************************************************************
    > File Name: 08_NumOf1InBinary.c
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年08月29日 星期一 20时40分15秒
 ************************************************************************/

#include <stdio.h>
 
int NumberOf1_1(int n)
{
	int count = 0;
	int flag = 1;
	while (flag < n)
	{
		if (n & flag)
			count ++;
		flag = flag << 1;
	}
	return count;
}

int NumberOf1_2(int n)
{
	int count = 0;
	while (n)
	{
		++ count;
		n = (n - 1) & n;
	}
	return count;
}

int main()
{
	int ret1 = 0;
	int ret2 = 0;
	
	int n = 5;
	ret1 = NumberOf1_1(n);
	ret2 = NumberOf1_2(n);
	printf("ret1 is %d\n", ret1);
	printf("ret2 is %d\n", ret2);
}