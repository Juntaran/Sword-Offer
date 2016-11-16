/*************************************************************************
    > File Name: 51_ArrayConstruction.c
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年09月05日 星期一 17时44分52秒
 ************************************************************************/

#include <stdio.h>

void Multiply(double* array1, double* array2, int length1, int length2)
{	
	if (length1==length2 && length1>1)
	{
		array2[0] = 1;
		for (int i = 1; i < length1; ++i)
			array2[i] = array2[i-1] * array1[i-1];
		
		double temp = 1;
		for (int i = length1-2; i >= 0; --i)
		{
			temp *= array1[i+1];
			array2[i] *= temp;
		}
	}
}

int main()
{
	double array1[] = {1, 2, 3, 4, 5};
    double array2[] = {0, 0, 0, 0, 0};
	
	int length1 = 5;
	int length2 = 5;
	
	Multiply(array1, array2, length1, length2);
			 
	return 0;
}