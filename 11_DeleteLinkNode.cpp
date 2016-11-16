/*************************************************************************
	> File Name: 11_DeleteLinkNode.c
	> Author: Juntaran
	> Mail: JuntaranMail@gmail.com
	> Created Time: 2016年08月30日 星期二 02时10分27秒
 ************************************************************************/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

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

// 删除结点
void DeleteListNode(ListNode** head, ListNode* key)
{
	if (head==NULL || key==NULL)
		return;
	
	// 如果要删除头结点
	if (*head == key)
	{
		*head = (*head)->next;
		free(key);
		key = NULL;
		return;
	}
	
	// 如果要删除尾结点
	if (key->next == NULL)
	{
		ListNode* temp = *head;
		while (temp->next != key)
			temp = temp->next;
		
		temp->next = NULL;
		free(key);
		key = NULL;
		return;
	}
	
	// 其他情况
	ListNode* temp = key->next;
	key->val = temp->val;
	key->next = temp->next;
	
	free(temp);
	temp = NULL;
	
}


int main()
{
	ListNode* test = createList();
	PrintList(test);
	
	ListNode* key1 = test;				// 头结点测试
	ListNode* key2 = test->next->next;	// 正常情况测试
	ListNode* key3 = test;
	while (key3->next)
	{
		key3 = key3->next;				// 尾结点测试
	}
	
	printf("key1 is %d\n", key1->val);
	printf("key2 is %d\n", key2->val);
	printf("key3 is %d\n", key3->val);
	
	DeleteListNode(&test, key1);
	PrintList(test);
	DeleteListNode(&test, key2);
	PrintList(test);
	DeleteListNode(&test, key3);
	PrintList(test);
	
	return 0;
}