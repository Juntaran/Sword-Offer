/*************************************************************************
    > File Name: 26_StringPermutation.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016��08��31�� ������ 16ʱ11��13��
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
			// left��begin����ֵ
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

// �ַ�����ȫ����
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