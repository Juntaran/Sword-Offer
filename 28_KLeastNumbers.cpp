/*************************************************************************
    > File Name: 28_KLeastNumbers.cpp
    > Author: Juntaran
    > Mail: JuntaranMail@gmail.com
    > Created Time: 2016��08��31�� ������ 19ʱ45��41��
 ************************************************************************/

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;


// �󶥶�����СK����
typedef multiset<int, greater<int> > intSet;
typedef multiset<int, greater<int> >::iterator setIterator;

void GetKLeastNumbers2(int* data, intSet& leastNumbers, int length, int k)
{
    leastNumbers.clear();
    
    if (k<1 || length<k)
        return;
    
    for (int i = 0; i < length; ++i)
    {
        if (leastNumbers.size() < k)
            leastNumbers.insert(data[i]);
        
        else
        {
            setIterator Greatest = leastNumbers.begin();
            if (data[i] < *(leastNumbers.begin()))
            {
                leastNumbers.erase(Greatest);
                leastNumbers.insert(data[i]);
            }
        }
    }
    
    for (setIterator iter = leastNumbers.begin(); iter != leastNumbers.end(); ++iter)
    {
        printf("%d ", *iter); 
    }
    printf("\n");
}


void swap(int* p, int* q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

// Partition����Ӧ��
int Partition(int* data, int length, int start, int end)
{
    if (data==NULL || length<=0 || start<0 || end>=length)
        return -1;
    
    // �������һ������Ϊ���
    int index = start;                
    
    // ������������һ��Ԫ�ؽ���
    swap(&data[index], &data[end]);
    
    int small = start - 1;
    for (index = start; index < end; ++index)
    {
        if (data[index] < data[end])
        {
            ++ small;
            if (small != index)
            {
                swap(&data[index], &data[small]);
            }
        }
    }
    ++ small;
    swap(&data[small], &data[end]);
    
    return small;
}

// ����Partitonʵ�ֿ���
void quickSort(int* data, int length, int start, int end)
{
    if (start==end || data==NULL || length<=0)
        return;
    
    int index = Partition(data, length, start, end);
    // printf("index is %d\n", index);
    if (index > start)
        quickSort(data, length, start, index-1);
    if (index < end)
        quickSort(data, length, index+1, end);
}

// ����PartitionѰ�ҳ��ִ�������һ����� (��λ��)
int GetMoreThanHalf(int* input, int length)
{
    if (input==NULL || length<=0)
        return -1;
    int start = 0;
    int end   = length - 1;
    int index = Partition(input, length, start, end);
    int middle = length >> 1;
    while (index != middle)
    {
        if (index > middle)
        {
            end = index - 1;
            index = Partition(input, length, start, end);
        }
        else
        {
            start = index + 1;
            index = Partition(input, length, start, end);
        }
    }
    int ret = input[middle];
    // �����Ƿ���ȷ
    int count2 = 0;
    for (int i = 0; i < length; ++i)
    {
        if (input[i] == ret)
            count2 ++;
    }
    if (count2*2 > length)
    {
        printf("middle number is %d\n", input[middle]);
        return ret;
    }
    else
    {
        printf("Not Find\n");
        return -1;
    }
}


// ����PartitionѰ�ҵ�KС����
int GetKthNumber(int* input, int length, int k)
{
    if (input==NULL || length<=0 || k<=0 || k>length)
        return -1;
    int start = 0;
    int end   = length - 1;
    int index = Partition(input, length, start, end);
    while (index != k - 1)
    {
        if (index > k-1)
        {
            end = index-1;
            index = Partition(input, length, start, end);
        }
        else
        {
            start = index + 1;
            index = Partition(input, length, start, end);
        }
    }
    printf("Kth is %d\n", input[index]);
    return input[index];
}


// ����PartitionѰ����СK����
void GetKLeastNumbers(int* input, int length, int* output, int k)
{
    if (input==NULL || output==NULL || length<=0 || k<=0 || k>length)
    {
        return;
    }
    int start = 0;
    int end   = length - 1;
    int index = Partition(input, length, start, end);
    while (index != k - 1)
    {
        if (index > k-1)
        {
            end = index - 1;
            index = Partition(input, length, start, end);
        }
        else
        {
            start = index + 1;
            index = Partition(input, length, start, end);
        }
        // printf("index is %d\n", index);
    }
    for (int i = 0; i < k; ++i)
        output[i] = input[i];
    
    for (int i = 0; i < k; ++i)
        printf("%d ", output[i]);
    printf("\n");
}


int main()
{
    int k = 5;
    int nums[] = {3,5,5,5,6,5,7,1,2,9};
    int length = 10;
    int output[k] = {0};
    
    // ��������
    quickSort(nums, length, 0, length-1);
    for (int i = 0; i < length; ++i)
        printf("%d ", nums[i]);
    printf("\n");
    
    // ����СK����
    GetKLeastNumbers(nums, length, output, k);
    
    // ���K�����
    GetKthNumber(nums, length, k);
    
    // �������г���һ�����(��λ��)
    GetMoreThanHalf(nums, length);
    
    // �󶥶�����СK����
    intSet leastNumbers;
    GetKLeastNumbers2(nums, leastNumbers, length, k);
}