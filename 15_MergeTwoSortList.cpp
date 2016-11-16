/*************************************************************************
    > File Name: 15_MergeTwoSortList.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年08月30日 星期二 15时49分47秒
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
ListNode* createList(int* nums, int length)
{
    struct ListNode* head;
    struct ListNode* p;
    struct ListNode* q;
    head = p = (ListNode*)malloc(sizeof(ListNode));
    head->val = nums[0];
    for (int i = 1; i < length; ++i)
    {
        q = (ListNode*)malloc(sizeof(ListNode));
        q->val = nums[i];
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
    // printf("PrintList:\n");
    while (temp != NULL)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

// 合并两个已排序链表
ListNode* MergeTwoSortList(ListNode* p, ListNode* q)
{
	if (!p)
		return q;
	if (!q)
		return p;
	
	ListNode* temp1 = (p->val > q->val ? q : p);
	ListNode* temp2 = (p->val > q->val ? p : q);
	ListNode* head = (temp1);
	head->next = MergeTwoSortList(temp1->next, temp2);
	
	return head;
}

int main()
{
	int nums1[] = {1,3,5,7};
	int nums2[] = {2,4,6,8};
	ListNode* list1 = createList(nums1, 4);
	ListNode* list2 = createList(nums2, 4);
	PrintList(list1);
	PrintList(list2);
	list1 = MergeTwoSortList(list1, list2);
	PrintList(list1);
	
	return 0;
	
}