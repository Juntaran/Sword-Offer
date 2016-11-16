/*************************************************************************
    > File Name: 13_KthNodeToTail.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年08月30日 星期二 15时32分25秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// 链表结构体
struct ListNode
{
	int val;
	ListNode* next;
};

// 构造链表
ListNode* createList()
{
	struct ListNode* head;
	struct ListNode* p;
	struct ListNode* q;
	head = p = (ListNode*)malloc(sizeof(ListNode));
	head->val = 0;
	
	for (int i = 1; i <= 10; ++i)
	{
		q = (ListNode*)malloc(sizeof(ListNode));
		q->val = i;
		p->next = q;
		p = q;
	}
	p->next = NULL;
	return head;
}

// 顺序输出链表
void PrintList(ListNode* head)
{
	if (head == NULL)
		return;
	ListNode* temp = head;
	printf("PrintList:\n");
	while (temp != NULL)
	{
		printf("%d ", temp->val);
		temp = temp->next;
	}
	printf("\n");
}

ListNode* FintKthNodeToTail(ListNode* head, int k)
{
	if (head==NULL || k<=0)
		return NULL;
	
	ListNode* fast = head;
	ListNode* slow = head;
	
	for (int i = 0; i < k - 1; ++i)
	{
		fast = fast->next;
		if (fast == NULL)
		{
			printf("Overflow!\n");
			return NULL;
		}
	}
	
	while (fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next;
	}
	printf("Find: %d\n", slow->val);
	
	return slow;
}

int main()
{
	ListNode* test = createList();
	PrintList(test);
	
	int k = 3;
	ListNode* find = FintKthNodeToTail(test, k);
	
	return 0;
}