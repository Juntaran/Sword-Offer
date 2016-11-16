/*************************************************************************
    > File Name: 09_Power.c
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年08月29日 星期一 21时07分21秒
 ************************************************************************/

#include <stdio.h>
 
double Power(double base, int exponent)
{
	if (base == 0)
		return 0;
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;
	
	int x = abs(exponent);
	double r = 1.0;
	
	while (x)
	{
		if (x & 1)
			r *= base;
		base *= base;
		x >>= 1;
		printf("r is %f\n base is %f\n x is %d\n", r, base, x);
	}
	return exponent<0 ? 1/r : r;
}

int main()
{
	double base = 2;
	int exponent = 10;
	double ret = Power(base, exponent);
	printf("ret is %f\n", ret);
	
	return 0;
}