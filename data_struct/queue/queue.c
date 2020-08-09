/*********************************************************************************
 *      Copyright:  (C) 2020 longyongtu<longyongtu13@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  queue.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(01/08/20)
 *         Author:  longyongtu <longyongtu13@qq.com>
 *      ChangeLog:  1, Release initial version on "01/08/20 16:19:50"
 *                 
 ********************************************************************************/

#include "queue.h"



que_head_tail_t *que_init()
{
    que_head_tail_t *tmp=(que_head_tail_t *)malloc(sizeof(que_head_tail_t));
    tmp->front=tmp->rear=NULL;
    return tmp;
}

int que_empty(que_head_tail_t *tmp)
{
    return tmp->front=NULL;
}

int que_insert(que_head_tail_t *tmp, que_data data)
{
    if(tmp == NULL) 
    {
        printf("invaild argument\n");   
        return -1;
    }
    
    que_node_t *tmp1=(que_node_t *)malloc(sizeof(que_node_t));

    tmp1->next=NULL;
    tmp1->data=data;

    if(tmp->rear == NULL)
    {
        tmp->rear =tmp1;
        tmp->front =tmp1;
    }
    else
    {
        tmp->rear->next=tmp1;
        tmp->rear=tmp1;
    }
    return -1;
}

int que_delete(que_head_tail_t *tmp)
{
    que_node_t      *tmp1=tmp->front;
    if(tmp->front == NULL || tmp->rear == NULL) 
    {
        printf("queue don't have data\n");   
        return -1
    }
    if(tmp->rear == trmp->front)
    {
        free(tmp->front);
        tmp->rear == NULL;
        tmp->front == NULL;
    }
    else
    {
        tmp->fornt=tmp->front->next;
        free(tmp1);
    }
    return 0;
}


#if 1
int main(int argc, char *argv[])
{
    
    return 0;
}


#endif
