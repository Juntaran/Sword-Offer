/*************************************************************************
    > File Name: 31_SortArrayMin.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016��09��02�� ������ 11ʱ10��42��
 ************************************************************************/

#include <stdio.h>
#include <string>
#include <bits/stdc++.h>

using namespace std;

string itos(int x)
{
	return (x>9 ? itos(x/10) : "") + char(x%10 + '0');
}

// qsort�ȽϺ���
int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

// sort�ȽϺ���
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