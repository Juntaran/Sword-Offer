/*************************************************************************
    > File Name: 53_NumericString.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年09月05日 星期一 18时11分07秒
 ************************************************************************/

#include <stdio.h>

bool scanDigits(char** str)
{
	char* before = *str;
	
	while (**str!='\0' && **str>='0' && **str<='9')
		++(*str);
	
	return *str > before;
}

bool isExpnential(char** str)
{
	if (**str!='e' && **str!='E')
		return false;
	++(*str);
	
	if (**str=='+' || **str=='-')
		++(*str);
	
	if (**str == '\0')
		return false;
	
	scanDigits(str);
	return (**str=='\0') ? true : false;
}


bool isNumeric(char* str)
{
	if (str == NULL)
		return false;
	
	if (*str=='+' || *str=='-')
		++str;
	
	if (*str == '\0')
		return false;
	
	bool numeric = true;
	
	bool hasDigits = scanDigits(&str);
	if (*str != '\0')
	{
		// floats
		if (*str == '.')
		{
			++ str;
			if (*str=='e' || *str=='E')
				return false;
			if (!hasDigits && *str=='\0')
				return false;
			
			scanDigits(&str);
			
			if (*str=='e' || *str=='E')
				numeric = isExpnential(&str);
		}
		// int
		else if (*str=='e' || *str=='E')
			numeric = isExpnential(&str);
		else
			numeric = false;
	}
	return numeric && *str=='\0';
}

void Test(char* testName, char* str, bool expected)
{
    if (testName != NULL)
        printf("%s begins: ", testName);

    if (isNumeric(str) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main()
{
    Test("Test1", "100", true);
    Test("Test2", "123.45e+6", true);
    Test("Test3", "+500", true);
    Test("Test4", "5e2", true);
    Test("Test5", "3.1416", true);
    Test("Test6", "600.", true);
    Test("Test7", "-.123", true);
    Test("Test8", "-1E-16", true);
    Test("Test9", "1.79769313486232E+308", true);

    printf("\n\n");

    Test("Test10", "12e", false);
    Test("Test11", "1a3.14", false);
    Test("Test12", "1+23", false);
    Test("Test13", "1.2.3", false);
    Test("Test14", "+-5", false);
    Test("Test15", "12e+5.4", false);
    Test("Test16", ".", false);
    Test("Test17", ".e1", false);
    Test("Test18", "+.", false);

    return 0;
}