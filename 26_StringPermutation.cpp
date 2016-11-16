/*************************************************************************
    > File Name: 26_StringPermutation.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年08月31日 星期三 16时11分13秒
 ************************************************************************/

#include <stdio.h>

void Permutation(char* str, char* begin)
{
	if (*begin == '\0')
		printf("%s\n", str);
	else
	{
		for (char* left = begin; *left != '\0'; left++)
		{
			// left与begin交换值
			char temp = *left;
			*left = *begin;
			*begin = temp;
			
			Permutation(str, begin+1);
			
			temp = *left;
			*left = *begin;
			*begin =temp;
		}
	}
}

// 字符串的全排列
void Permutation(char* str)
{
	if (str == NULL)
		return;
	Permutation(str, str);
}

int main()
{
	char str[] = "abc";
	Permutation(str);
	
	return 0;
}