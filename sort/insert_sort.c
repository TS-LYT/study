/*********************************************************************************
 *      Copyright:  (C) 2020 longyongtu<longyongtu13@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  insert_sort.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(31/07/20)
 *         Author:  longyongtu <longyongtu13@qq.com>
 *      ChangeLog:  1, Release initial version on "31/07/20 14:39:07"
 *                 
 ********************************************************************************/


#include <stdio.h>

void insert_sort(int arr[], int len)
{
    int i=0;
    int j=0;
    int tmp=0;

    for (i=1; i<len; ++i) //遍历全数据个数减一个
    {
        tmp = arr[i]; //取出要插入的数
        j = i-1; //已排好序的最后一个元素的位置
        while((j>=0) && (arr[j]>tmp)) // 第二个大于为从小到大排序，反之，排好序的数据的最后一位往前一一与要插入的数比较，
        {
            arr[j+1] = arr[j]; //上述为真， 则与前面数据一一比较
            j--; //
        }
        arr[j+1] = tmp;//上述为假，则表示插入的数据不许进行在比较，已经是个有序的数组
    }

}

int main(int argc, char *argv[])
{
    int i = 0;
    int array[6] = {2, 3, 1, 5, 4, 8};

    printf("data before insert sort:\n");
    for(i=0; i<sizeof(array)/sizeof(array[0]); i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    insert_sort(array, sizeof(array)/sizeof(array[0]));

    printf("data after insert sort:\n");
    for(i=0; i<sizeof(array)/sizeof(array[0]); i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
