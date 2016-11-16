/*************************************************************************
    > File Name: 48_ATOI.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年09月05日 星期一 15时51分13秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

enum Status{Valid=0, Invalid};
int Status= Valid;

long long StrToIntCore(char* digit, bool minus)
{
	long long num = 0;
	while (*digit != '\0')
	{
		if (*digit>='0' && *digit<='9')
		{
			int flag = minus ? -1 : 1;
			num = num*10 + flag*(*digit - '0');
			
			if ((!minus && num>0x7FFFFFFF) || (minus && num<(signed int)0x80000000))
			{
				num = 0;
				break;
			}
			digit ++;
		}
		else
		{
			num = 0;
			break;
		}
	}
	
	if (*digit == '\0')
		Status = Valid;
	
	return num;
}

int StrToInt(char* str)
{
	Status = Invalid;
	long long num = 0;
	
	if (str!=NULL && *str!='\0')
	{
		bool minus = false;
		if (*str == '+')
			str ++;
		else if (*str == '-')
		{
			str ++;
			minus = true;
		}
		if (*str != '\0')
			num = StrToIntCore(str, minus);
	}
	return (int)num;
}

int main()
{
	char digit[] = "+5555555";
	int ret = StrToInt(digit);
	printf("ret is %d\n", ret);
	
	return 0;
}
