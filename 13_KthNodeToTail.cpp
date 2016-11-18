/*************************************************************************
    > File Name: 13_KthNodeToTail.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016��08��30�� ���ڶ� 15ʱ32��25��
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// ����ṹ��
struct ListNode
{
	int val;
	ListNode* next;
};

// ��������
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

// ˳���������
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