/*************************************************************************
	> File Name: 001.c
	> Author: Juntaran
	> Mail: JuntaranMail@gmail.com
	> Created Time: 2016年08月24日 星期三 01时15分09秒
 ************************************************************************/

#include <stdio.h>

#define ROW 4
#define COL 4

void Young(int array[][COL], int key)
{
    int i = ROW - 1;
    int j = 0;
    int val;

    while (i>=0 && j<COL)
    {
        val = array[i][j];
        if (val == key)
        {
            printf("Find! [%d,%d]\n", i, j);
            return;
        }
        if (val < key)
        {
            j ++;
        }
        if (val > key)
        {
            i --;
        }
    }
    printf("Not Find!\n");
}

int main()
{
    int array[ROW][COL] = {{1,2,8,9}, {2,4,9,12}, {4,7,10,13}, {6,8,11,15}};
    int key = 10;
    Young(array, key);
    return 0;
}
