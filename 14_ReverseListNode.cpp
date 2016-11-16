/*************************************************************************
    > File Name: 14_ReverseListNode.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年08月30日 星期二 15时47分32秒
 ************************************************************************/

#include <stdio.h>
#include <malloc.h>

// 链表结构体
struct ListNode
{
    int val;
    struct ListNode* next;
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

// 逆序链表
ListNode* ReverseList(ListNode* head)
{
    if (head==NULL || head->next==NULL)
        return head;
    ListNode* fast = head->next;
    ListNode* slow = head;
    slow->next = NULL;
    ListNode* temp;
    
    while (fast->next != NULL)
    {
        temp = fast->next;
        fast->next = slow;
        slow = fast;
        fast = temp;
    }
    fast->next = slow;
    return fast;
}

int main()
{
    ListNode* test = createList();
    PrintList(test);
    test = ReverseList(test);
    PrintList(test);
    return  0;
}