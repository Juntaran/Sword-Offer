/*************************************************************************
    > File Name: 47_AddTwoNumbers.c
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年09月04日 星期日 21时33分07秒
 ************************************************************************/
 
#include <stdio.h>

// 移位求两数相加
int ADD(int num1, int num2)
{
	int sum, carry;
	if (num1 == 0)
		return num2;
	if (num2 == 0)
		return num1;
	
	while (num2 != 0)
	{
		sum = num1 ^ num2;
		carry = (num1 & num2) << 1;
		
		num1 = sum;
		num2 = carry;
	}
	return sum;
}

int main()
{
	int num1 = 5;
	int num2 = 37;
	
	int sum = ADD(num1, num2);
	printf("sum is %d\n", sum);
	return 0;
}