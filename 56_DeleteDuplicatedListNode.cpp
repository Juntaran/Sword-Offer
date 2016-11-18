/*************************************************************************
    > File Name: 55_EntryNodeInlist.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016��09��05�� ���ڶ� 14ʱ54��39��
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// ����ṹ��
struct ListNode
{
	int val;
	ListNode* next;
};

ListNode* CreateListNode(int value)
{
    ListNode* pNode = new ListNode();
    pNode->val = value;
    pNode->next = NULL;

    return pNode;
}

void ConnectListNodes(ListNode* Current, ListNode* Next)
{
    if (Current == NULL)
    {
        printf("Error to connect two nodes.\n");
        exit(1);
    }

    Current->next = Next;
}

void DestroyList(ListNode* pHead)
{
    ListNode* pNode = pHead;
    while(pNode != NULL)
    {
        pHead = pHead->next;
        delete pNode;
        pNode = pHead;
    }
}

void PrintList(ListNode* pHead)
{
    printf("PrintList starts.\n");
    
    ListNode* pNode = pHead;
    while(pNode != NULL)
    {
        printf("%d\t", pNode->val);
        pNode = pNode->next;
    }

    printf("\nPrintList ends.\n");
}

void DeleteDuplication(ListNode* head)
{
	if (head==NULL || head->next==NULL)
		return head;
	/*
    //	ȥ���ظ�Ԫ�أ�ʣ��1->2->3->4->5
    while( fast->next ) {
        fast = fast->next;
		while( slow->val == fast->val ) 
		{
            fast = fast->next;
            slow->next = fast;
        }
        slow = slow->next;
    }
    */
	
	// ���� �½�һ��ͷ����ֹͷ��ɾ��
	ListNode* newHead = new ListNode();
	newHead->val = -1;
	newHead->next = head;
	
	ListNode* slow = newHead;
	ListNode* fast = newHead;
	ListNode* current = newHead;
	
	while (current!=NULL)
	{
		fast = current->next;
		
	}
	
	
	
}