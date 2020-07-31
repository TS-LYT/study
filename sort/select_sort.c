/*********************************************************************************
 *      Copyright:  (C) 2020 longyongtu<longyongtu13@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  select_sort.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(31/07/20)
 *         Author:  longyongtu <longyongtu13@qq.com>
 *      ChangeLog:  1, Release initial version on "31/07/20 14:38:08"
 *                 
 ********************************************************************************/

#include <stdio.h>


void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void select_sort(int *arr, int len)
{
    int i,j;

    for (i=0; i<len-1; i++)//遍历所有数据
    {
        int min = i;//取出要比较的数
        for (j=i+1; j<len; j++)
        {
            if(arr[min] > arr[j]) //小到大排序：>  大到小排序：<  一直比较找到最大（小）的数
            {
                min = j;
            }
        }
        swap(&arr[i], &arr[min]);
    }
}
int main(int argc, char *argv[])
{
    int array[6] = {3, 5, 9, 2, 1, 6};
    int i = 0;

    printf("data before select sort\n");
    for(i=0; i<sizeof(array)/sizeof(array[0]); i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    select_sort(array, sizeof(array)/sizeof(array[0]));

    printf("data after select sort:\n");
    for(i=0; i<sizeof(array)/sizeof(array[0]); i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
