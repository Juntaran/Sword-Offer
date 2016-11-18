/*************************************************************************
    > File Name: 35_FirstCommonNode.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016��09��02�� ������ 20ʱ52��28��
 ************************************************************************/

#include <stdio.h>
#include <malloc.h>

// ����ṹ��
struct ListNode
{
    int val;
    struct ListNode* next;
};

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

// ��ȡ������
int getListLength(ListNode* head)
{
	int length = 0;
	ListNode* p = head;
	while (p)
	{
		length ++;
		p = p->next;
	}
	return length;
}

// Ѱ�ҵ�һ���������
ListNode* FindFirstCommonNode(ListNode* head1, ListNode* head2)
{
	int length1 = getListLength(head1);
	int length2 = getListLength(head2);
	
	ListNode* longList;
	ListNode* shortList;
	int diff;
	
	if (length1 >= length2)
	{
		longList = head1;
		shortList = head2;
		diff = length1 - length2;
	}
	else
	{
		longList = head2;
		shortList = head1;
		diff = length2 - length1;
	}
	
	for (int i = 0; i < diff; ++i)
		longList = longList->next;
	
	while (longList && shortList && shortList!=longList)
	{
		longList = longList->next;
		shortList = shortList->next;
	}
	
	if (longList == NULL)
		printf("Not Find\n");
	else
		printf("Find %d\n", longList->val);
	
	return longList;
}

int main()
{
	// ��������ṹ
	ListNode* head1 = (ListNode*)malloc(sizeof(ListNode));
	head1->val = 1;
	ListNode* p1 = head1;
	for (int i = 0; i < 4; ++i)
	{
		ListNode* q1 = (ListNode*)malloc(sizeof(ListNode));
		q1->val = i + 2;
		p1->next = q1;
		p1 = q1;
	}
	p1->next = NULL;
	
	
	ListNode* head2 = (ListNode*)malloc(sizeof(ListNode));
	head2->val = 6;
	ListNode* p2 = head2;
	for (int i = 0; i < 4; ++i)
	{
		ListNode* q2 = (ListNode*)malloc(sizeof(ListNode));
		q2->val = i + 7;
		p2->next = q2;
		p2 = q2;
	}
	p2->next = NULL;
	
	p1->next = head2->next->next;
	
	PrintList(head1);
	PrintList(head2);
	
	FindFirstCommonNode(head1, head2);
}