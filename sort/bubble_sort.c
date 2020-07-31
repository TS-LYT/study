/*********************************************************************************
 *      Copyright:  (C) 2020 longyongtu<longyongtu13@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  bubble_sort.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(31/07/20)
 *         Author:  longyongtu <longyongtu13@qq.com>
 *      ChangeLog:  1, Release initial version on "31/07/20 14:37:12"
 *                 
 ********************************************************************************/

#include <stdio.h>

void bubble_sort(int *arr, int len)
{
    int     i = 0;
    int     j = 0;
    int     t = 0;

    for(i=0; i<len-1; i++) //对数组进行遍历
        for(j=0; j<len-1-i; j++) //对选定的数和其它数进行比较
        {
            if(*(arr+j) > *(arr+j+1))//如果选定的数大于它比较的数就进行换位
            {
                t = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = t;
            }
        }
}
int main(int argc, char *argv[])
{
    int i = 0;
    int array[6] = {2, 3, 1, 5, 4, 8};

    printf("data before bubble sort:\n");
    for(i=0; i<sizeof(array)/sizeof(array[0]); i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    bubble_sort(array, sizeof(array)/sizeof(array[0]));

    printf("data after bubble sort:\n");
    for(i=0; i<sizeof(array)/sizeof(array[0]); i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
