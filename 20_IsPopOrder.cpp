/*************************************************************************
    > File Name: 20_IsPopOrder.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年08月30日 星期二 19时53分19秒
 ************************************************************************/

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

bool isPopOrder(int* push, int* pop, int length)
{
	if (push==NULL || pop==NULL || length<=0)
		return false;
	
	int nextPush = 0;
	int nextPop  = 0;
	
	stack<int> stackData;
	while (nextPop < length)
	{
		// 如果当前栈为空 或栈顶元素不等于要出栈的元素，压栈
		while (stackData.empty() || stackData.top()!=pop[nextPop])
		{
			if (nextPush == length)
				break;
			
			stackData.push(push[nextPush]);
			nextPush ++;
		}
		// 入栈队列结束还没找到钙元素， wrong
		if (stackData.top() != pop[nextPop])
			break;
		// 匹配到该元素，弹出，出栈指针后移一位
		stackData.pop();
		nextPop ++;
	}
	// 如果栈内已经没有元素且出栈指针已经走完，right
	if (stackData.empty() && nextPop==length)
		return true;
	
	return false;
}

int main()
{
	int push[] = {1, 2, 3, 4, 5};
//	int pop[]  = {4, 5, 3, 2, 1};
	int pop[]  = {4, 3, 5, 1, 2};
	int length = 5;
	if (isPopOrder(push, pop, length) == true)
		printf("Right\n");
	else
		printf("Wrong\n");
	
	return 0;
}