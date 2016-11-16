/*************************************************************************
    > File Name: 31_SortArrayMin.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年09月02日 星期五 11时10分42秒
 ************************************************************************/

#include <stdio.h>
#include <string>
#include <bits/stdc++.h>

using namespace std;

string itos(int x)
{
	return (x>9 ? itos(x/10) : "") + char(x%10 + '0');
}

// qsort比较函数
int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

// sort比较函数
bool compare(int a, int b)
{
	return (itos(a) + itos(b)) < (itos(b) + itos(a));
}

string PrintMinNumber(int* nums, int length)
{
	string s = "";
	if (nums==NULL || length<=0)
		return s;
	// sort(nums, nums+length, compare);
	qsort(nums, length, sizeof(int), cmp);
	
	for (int i = 0; i < length; ++i)
		s += itos(nums[i]);
	cout << s << endl;
	return s;
}

int main()
{
	int nums[] = {3, 32, 321};
	int length = 3;
	PrintMinNumber(nums, length);
	
	return 0;
}