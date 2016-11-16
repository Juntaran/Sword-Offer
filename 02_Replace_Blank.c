/*************************************************************************
	> File Name: 02_Replace_Blank.c
	> Author: Juntaran
	> Mail: JuntaranMail@gmail.com
	> Created Time: 2016年08月24日 星期三 01时28分33秒
 ************************************************************************/

#include <stdio.h>

void ReplaceBlank(char* str)
{
	if (str==NULL)
	{
		return;
	}
	
	int blankCount = 0;
	int alphaCount = 0;
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			blankCount ++;
		alphaCount ++;
		
		i ++;
	}
	printf("alphaCount is %d\n", alphaCount);
	printf("blankCount is %d\n", blankCount);
	
	int newLength = alphaCount + 2*blankCount;
	printf("newLength is %d\n", newLength);
	int p1 = alphaCount + 1;
	int p2 = newLength + 1;
	while (p1>=0 && p2>p1)
	{
		if (str[p1] == ' ')
		{
			str[p2--] = '0';
			str[p2--] = '2';
			str[p2--] = '%';
		}
		else
		{
			str[p2--] = str[p1];
		}
		p1 --;
	}
}

int main()
{
	char str[] = "We are Happy!";
	printf("Before: %s\n", str);
	ReplaceBlank(str);
	printf("After: %s\n", str);
}