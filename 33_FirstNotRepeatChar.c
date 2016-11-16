/*************************************************************************
    > File Name: 33_FirstNotRepeatChar.c
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年09月02日 星期五 13时43分20秒
 ************************************************************************/

#include <stdio.h>

char FirstNotRepeatChar(char* str)
{
	if (str == NULL)
		return '\0';
	int HashSize = 256;
	int hash[HashSize] = {0};
	
	char* key = str;
	while (*key != '\0')
	{
		printf("*key = %d\n", *key);
		hash[*key] ++;
		*key ++;
	}
	
	key = str;
	while (*key != '\0')
	{
		printf("%d ", hash[*key]);
		if (hash[*key] == 1)
			return *key;
		key ++;
	}
	return '\0';
}

int main()
{
	char str[] = "adaccbweff";
	char ret = FirstNotRepeatChar(str);
	printf("%c\n", ret);
}