/*************************************************************************
    > File Name: 54_FirstCharacterInStream.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年09月05日 星期二 14时26分33秒
 ************************************************************************/

#include <stdio.h>
#include <vector>
#include <limits.h>

using namespace std;

class CharStatistics
{
	private:
		int occurrence[256];
		int index;
		
	public:
		
		CharStatistics()
		{
			for (int i = 0; i < 256; ++i)
				occurrence[i] = -1;
		
			index = 0;
		}
		
		void Insert(char ch)
		{
			if (occurrence[ch] == -1)
				occurrence[ch] = index;
			
			else if (occurrence[ch] >= 0)
				occurrence[ch] = -2;
			
			index ++;
		}
		
		char FirstAppearOnce()
		{
			char ch = '\0';
			int minIndex = INT_MAX;
			for (int i = 0; i < 256; ++i)
			{
				if (occurrence[i]>=0 && occurrence[i]<minIndex)
				{
					ch = (char)i;
					minIndex = occurrence[i];
				}
			}
			return ch;
		}
		
};

// ==================== Test Code ====================
void Test(char* testName, CharStatistics chars, char expected)
{
    if (testName != NULL)
        printf("%s begins: ", testName);

    if (chars.FirstAppearOnce() == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
    CharStatistics chars;

    Test("Test1", chars, '\0');

    chars.Insert('g');
    Test("Test2", chars, 'g');

    chars.Insert('o');
    Test("Test3", chars, 'g');

    chars.Insert('o');
    Test("Test4", chars, 'g');

    chars.Insert('g');
    Test("Test5", chars, '\0');

    chars.Insert('l');
    Test("Test6", chars, 'l');

    chars.Insert('e');
    Test("Test7", chars, 'l');

	return 0;
}