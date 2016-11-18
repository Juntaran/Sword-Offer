/*************************************************************************
    > File Name: 19_MinInStack.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016��08��30�� ���ڶ� 19ʱ29��48��
 ************************************************************************/

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

template<class T>
class minStack
{
private:
	stack<T> stack_data;
	stack<T> stack_min;
	
public:

	void push(T &value)
	{
		// ��Ԫ����ջ
		stack_data.push(value);
		
		// ��Ԫ�ر�֮ǰ��СԪ��С��ʱ����Ԫ�ؽ��븨��ջ
		// �����֮ǰ��СԪ���ظ����븨��ջ
		if (stack_min.size()==0 || value<stack_min.top())
			stack_min.push(value);
		else
			stack_min.push(stack_min.top());
	}
	T pop()
	{
		assert(stack_data.size()>0 && stack_min.size()>0);
		stack_data.pop();
		stack_min.pop();
		return stack_data.top();
	}
	T min()
	{
		assert(stack_data.size()>0 && stack_min.size()>0);
		return stack_min.top();
	}
};

int main()
{
	minStack<int> mStack;
	for (int i = 0; i < 5; i++)
    {
        cout << i << " push" << endl;
        mStack.push(i);
    }
	cout << "min is " << mStack.min() << endl;
    for (int i = 1; i < 3; i++)
    {
        cout << mStack.pop() << " pop" << endl;
    }
	cout << "min is " << mStack.min() << endl;
	for (int i = 5; i < 7; i++)
    {
        cout << i << " push" << endl;
        mStack.push(i);
    }
	cout << "min is " << mStack.min() << endl;
	for (int i = 1; i < 3; i++)
    {
        cout << mStack.pop() << " pop" << endl;
    }
	int k = -1;
	mStack.push(k);
	cout << "min is " << mStack.min() << endl;
    cout << endl;
}