/*************************************************************************
    > File Name: 20_IsPopOrder.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016��08��30�� ���ڶ� 19ʱ53��19��
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
		// �����ǰջΪ�� ��ջ��Ԫ�ز�����Ҫ��ջ��Ԫ�أ�ѹջ
		while (stackData.empty() || stackData.top()!=pop[nextPop])
		{
			if (nextPush == length)
				break;
			
			stackData.push(push[nextPush]);
			nextPush ++;
		}
		// ��ջ���н�����û�ҵ���Ԫ�أ� wrong
		if (stackData.top() != pop[nextPop])
			break;
		// ƥ�䵽��Ԫ�أ���������ջָ�����һλ
		stackData.pop();
		nextPop ++;
	}
	// ���ջ���Ѿ�û��Ԫ���ҳ�ջָ���Ѿ����꣬right
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