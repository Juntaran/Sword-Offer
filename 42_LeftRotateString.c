/*************************************************************************
    > File Name: 42_LeftRotateString.c
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016��09��04�� ������ 16ʱ31��43��
 ************************************************************************/

#include <stdio.h>
#include <string.h>

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

void LeftRotateString(char* str, int n)
{
	if (str == NULL || n<=0)
		return str;
	
	int length = strlen(str);
	// n���ܳ����ַ�������
	n = n % length;
	
	// ��һ����
	char* FirstStart = str;
	char* FirstEnd   = str + n - 1;
	
	// �ڶ�����
	char* SecondStart = str + n;
	char* SecondEnd   = str + length - 1;
	
	// �ȷ�ת��һ����
	ReverseWord(FirstStart, FirstEnd);
	// �ٷ�ת�ڶ�����
	ReverseWord(SecondStart, SecondEnd);
	// ���巴ת
	ReverseWord(FirstStart, SecondEnd);
}

int main()
{
	char str[] = "abcdefg";
	int n = 9;
	
	LeftRotateString(str, n);
	printf("%s\n", str);
}