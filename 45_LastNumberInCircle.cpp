/*************************************************************************
    > File Name: 45_LastNumberInCircle.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年09月04日 星期日 20时21分57秒
 ************************************************************************/
 
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;


// 环形链表
int LastRemaining1(int n, int m)
{
	if (n<1 || m<1)
		return -1;
	
	int i = 0;
	
	list<int> numbers;
	for (int i = 0; i < n; ++i)
		numbers.push_back(i);
	
	list<int>::iterator current = numbers.begin();
	while (numbers.size() > 1)
	{
		for (int i = 1; i < m; ++i)
		{
			current ++;
			if (current == numbers.end())
				current = numbers.begin();
		}
		list<int>::iterator next = ++current;
		if (next == numbers.end())
			next = numbers.begin();
		
		--current;
		numbers.erase(current);
		current = next;
	}
	return *current;
}

// 数组模拟环
int LastRemaining2(int n, int m)
{
	if (n<1 || m<1)
		return -1;
	
	int array[n];
	int i = -1;
	int step = 0;
	int count = n;
	
	while (count > 0)
	{
		i ++;
		if (i >= n)			// 模拟环
			i = 0;
		if (array[i] == -1)
			continue;
		step ++;
		if (step == m)
		{
			array[i] = -1;
			step = 0;
			count --;
		}
	}
	int ret = i;
	return ret;
}

// 数学解法
int LastRemaining3(int n, int m)
{
	if (n<1 || m<1)
		return -1;
	
	int ret = 0;
	for (int i = 2; i <= n; ++i)
		ret = (ret + m) % i;
	
	return ret;
}

int main()
{
	int n = 100;
	int m = 5;
	
	int ret1 = LastRemaining1(n, m);
	int ret2 = LastRemaining2(n, m);
	int ret3 = LastRemaining3(n, m);
	
	printf("ret1 is %d\n", ret1);
	printf("ret2 is %d\n", ret2);
	printf("ret3 is %d\n", ret3);
	
	return 0;
}