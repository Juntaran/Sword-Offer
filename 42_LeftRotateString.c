/*************************************************************************
    > File Name: 42_LeftRotateString.c
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年09月04日 星期日 16时31分43秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

// 反转单词
void ReverseWord(char* left, char* right)
{
	if (left== NULL || right==NULL)
		return;
	while (left < right)
	{
		char temp = *left;
		*left = *right;
		*right = temp;
		
		left ++;
		right --;
	}
}

void LeftRotateString(char* str, int n)
{
	if (str == NULL || n<=0)
		return str;
	
	int length = strlen(str);
	// n可能超过字符串长度
	n = n % length;
	
	// 第一部分
	char* FirstStart = str;
	char* FirstEnd   = str + n - 1;
	
	// 第二部分
	char* SecondStart = str + n;
	char* SecondEnd   = str + length - 1;
	
	// 先反转第一部分
	ReverseWord(FirstStart, FirstEnd);
	// 再反转第二部分
	ReverseWord(SecondStart, SecondEnd);
	// 整体反转
	ReverseWord(FirstStart, SecondEnd);
}

int main()
{
	char str[] = "abcdefg";
	int n = 9;
	
	LeftRotateString(str, n);
	printf("%s\n", str);
}