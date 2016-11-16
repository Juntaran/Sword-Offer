/*************************************************************************
    > File Name: 56_DeleteDuplicatedListNode.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年09月05日 星期二 15时49分18秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// 链表结构体
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

ListNode* isHasCircle(ListNode* head)
{
	if (head==NULL || head->next==NULL)
		return NULL;
	
	ListNode* slow = head->next;
	ListNode* fast = head->next->next;
	
	while (fast!=NULL && slow!=NULL)
	{
		if (fast == slow)		// 快慢指针相遇，有环
			return fast;
		
		slow = slow->next;
		fast = fast->next;
		
		if (fast != NULL)
			fast = fast->next;
	}
	return NULL;				// 走出循环，无环
}

ListNode* FindEntry(ListNode* head)
{
	if (head==NULL || head->next==NULL)
		return NULL;
	
	ListNode* meetNode = isHasCircle(head);
	if (meetNode == NULL)
		return NULL;
	
	// 计算环的长度
	int lengthCircle = 1;
	ListNode* temp = meetNode;
	while (temp->next != meetNode)
	{
		temp = temp->next;
		lengthCircle ++;
	}
	
	// 快指针先走环长步数
	ListNode* fast = head;
	ListNode* slow = head;
	int lengthStraight = 0;
	for (int i = 0; i < lengthCircle; ++i)
		fast = fast->next;
	
	// 快慢指针一起走，相遇点就是入口
	while (fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
		lengthStraight ++;
	}
	printf("\n  Straight length is %d\n", lengthStraight);
	printf("  Circle length is %d\n", lengthCircle);
	printf("  Entry is %d\n", fast->val);
	return fast;
}

// ==================== Test Code ====================
void Test(char* testName, ListNode* pHead, ListNode* entryNode)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(FindEntry(pHead) == entryNode)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// A list has a node, without a loop
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);

    Test("Test1", pNode1, NULL);

    DestroyList(pNode1);
}

// A list has a node, with a loop
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);
    ConnectListNodes(pNode1, pNode1);

    Test("Test2", pNode1, pNode1);

    delete pNode1;
    pNode1 = NULL;
}

// A list has multiple nodes, with a loop 
void Test3()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode3);

    Test("Test3", pNode1, pNode3);

    delete pNode1;
    pNode1 = NULL;
    delete pNode2;
    pNode2 = NULL;
    delete pNode3;
    pNode3 = NULL;
    delete pNode4;
    pNode4 = NULL;
    delete pNode5;
    pNode5 = NULL;
}

// A list has multiple nodes, with a loop 
void Test4()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode1);

    Test("Test4", pNode1, pNode1);

    delete pNode1;
    pNode1 = NULL;
    delete pNode2;
    pNode2 = NULL;
    delete pNode3;
    pNode3 = NULL;
    delete pNode4;
    pNode4 = NULL;
    delete pNode5;
    pNode5 = NULL;
}

// A list has multiple nodes, with a loop 
void Test5()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode5);

    Test("Test5", pNode1, pNode5);

    delete pNode1;
    pNode1 = NULL;
    delete pNode2;
    pNode2 = NULL;
    delete pNode3;
    pNode3 = NULL;
    delete pNode4;
    pNode4 = NULL;
    delete pNode5;
    pNode5 = NULL;
}

// A list has multiple nodes, without a loop 
void Test6()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test("Test6", pNode1, NULL);

    DestroyList(pNode1);
}

// Empty list
void Test7()
{
    Test("Test7", NULL, NULL);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

	return 0;
}