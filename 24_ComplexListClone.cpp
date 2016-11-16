/*************************************************************************
    > File Name: 24_ComplexListClone.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016年08月31日 星期三 14时24分35秒
 ************************************************************************/

#include <stdio.h>
#include <malloc.h>

// 链表结构体
struct ComplexListNode
{
    int val;
    ComplexListNode* next;
	ComplexListNode* rand;
};

// 构造链表
ComplexListNode* createList()
{
    ComplexListNode* A = new ComplexListNode();
	ComplexListNode* B = new ComplexListNode();
	ComplexListNode* C = new ComplexListNode();
	ComplexListNode* D = new ComplexListNode();
	ComplexListNode* E = new ComplexListNode();
	A->val  = 1;
	A->next = B;
	A->rand = C;
	B->val  = 2;
	B->next = C;
	B->rand = E;
	C->val  = 3;
	C->next = D;
	C->rand = NULL;
	D->val  = 4;
	D->next = E;
	D->rand = B;
	E->val  = 5;
	E->next = NULL;
	E->rand = NULL;
	
    return A;
}

void* PrintComplexList(ComplexListNode* head)
{
	while (head)
	{
		if (head->rand != NULL)
			printf("%d rand=%d\n", head->val, head->rand->val);
		else
			printf("%d\n", head->val);
		head = head->next;
	}
	printf("\n");
}

// 复制链表，复制的接在原位置后面
void CloneNodes(ComplexListNode* head)
{
	ComplexListNode* node = head;
	while (node != NULL)
	{
		ComplexListNode* newNode = new ComplexListNode();
		newNode->val = node->val;
		newNode->next = node->next;
		newNode->rand = NULL;
		node->next = newNode;
		node = newNode->next;
	}
}

// 补充复制的链表的rand指针
void AddRand(ComplexListNode* head)
{
	ComplexListNode* node = head;
	while (node != NULL)
	{
		ComplexListNode* newNode = node->next;
		if (node->rand != NULL)
			newNode->rand = node->rand->next;
		node = newNode->next;
	}
}

// 拆分链表
ComplexListNode* SplitList(ComplexListNode* head)
{
	ComplexListNode* node = head;
	ComplexListNode* newHead = NULL;
	ComplexListNode* newNode = NULL;
	
	if (node != NULL)
	{
		newHead = newNode = node->next;
		node->next = newNode->next;
		node = node->next;
	}
	while (node != NULL)
	{
		newNode->next = node->next;
		newNode = newNode->next;
		node->next = newNode->next;
		node = node->next;
	}
	return newHead;
}

ComplexListNode* Clone(ComplexListNode* head)
{
	CloneNodes(head);
	AddRand(head);
	return SplitList(head);
}

int main()
{
	ComplexListNode* test = createList();
	PrintComplexList(test);
	
	ComplexListNode* newTest = Clone(test);
	PrintComplexList(test);
	PrintComplexList(newTest);
	
}