/*************************************************************************
    > File Name: 41_ReverseWords.c
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016��09��04�� ������ 16ʱ18��34��
 ************************************************************************/

#include <stdio.h>

// ��ת����
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

void Reverse(char* str)
{
	if (str == NULL)
		return;
	
	char* left = str;
	char* right = str;
	while (*(right+1) != '\0')
		right++;
	
	// �ȷ�ת��������
	ReverseWord(left, right);
	
	// ���𲽷�תÿ������
	left = str;
	right = str;
	while (*left != '\0')
	{
		if (*left == ' ')
		{
			left ++;
			right++;
		}
		else if (*right==' ' || *right=='\0')
		{
			ReverseWord(left, --right);
			left = ++right;
		}
		else
		{
			right ++;
		}
	}
}

int main()
{
	char str[] = "I am a student. ";
	Reverse(str);
	
	printf("%s\n", str);
	return 0;
}