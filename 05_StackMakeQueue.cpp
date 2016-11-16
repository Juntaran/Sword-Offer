/*************************************************************************
    > File Name: 05_StackMakeQueue.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年08月29日 星期一 19时32分12秒
 ************************************************************************/

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

template<class T>
class qStack
{
private:
	stack<T> stack1;
	stack<T> stack2;
	int size;
	
public:
	qStack()
	{
		size = 0;
	}
	void push(T &node)
	{
		stack1.push(node);
		size = stack1.size();
	}
	T pop()
	{
		assert(this->size > 0);
		T ret = 0;
		if (this->size == 1)
		{
			ret = stack1.top();
			stack1.pop();
			this->size = 0;
			return ret;
		}
		if (this->size > 1)
		{
			while (stack1.size())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
			ret = stack2.top();
			stack2.pop();
			
			while (stack2.size())
			{
				stack1.push(stack2.top());
				stack2.pop();
			}
			this->size --;
			return ret;
		}
	}
};


int main()
{
	qStack<int> quque;
	for (int i = 0; i < 5; i++)
    {
        cout << i << " push" << endl;
        quque.push(i);
    }
    for (int i = 1; i < 3; i++)
    {
        cout << quque.pop() << " pop" << endl;
    }
	for (int i = 5; i < 7; i++)
    {
        cout << i << " push" << endl;
        quque.push(i);
    }
	for (int i = 1; i < 3; i++)
    {
        cout << quque.pop() << " pop" << endl;
    }
    cout << endl;
}