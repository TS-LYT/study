/*********************************************************************************
 *      Copyright:  (C) 2020 longyongtu<longyongtu13@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  link_list.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(31/07/20)
 *         Author:  longyongtu <longyongtu13@qq.com>
 *      ChangeLog:  1, Release initial version on "31/07/20 16:42:53"
 *                 
 ********************************************************************************/

#include "link_list.h"



node_t *link_init()
{
    node_t      *head = NULL;
    
    head=(node_t *)malloc(sizeof(node_t));
    memset(head, 0, sizeof(node_t));
    return head;
}


void link_insert(node_t *head, int data)
{
    /* insert in head */
    node_t      *tmp = NULL;

    tmp=(node_t *)malloc(sizeof(node_t));
    memset(tmp, 0, sizeof(node_t));

    tmp->next=head->next;
    tmp->data.fd=data;
    head->next=tmp;

    return ;

#if 0
    /* insert in tail */
    node_t      *tmp = NULL;

    tmp=(node_t *)malloc(sizeof(node_t));
    memset(tmp, 0, sizeof(node_t));

    while(head != NULL)
    {
        head=head->next;
    }

    head->next=tmp;
    tmp->data=data;
    tmp->next=NULL;
    
    return;
#endif
}

void link_print_specified(node_t *head, int data)
{
    while(head->data.fd != data)
    {
        head=head->next;
    }
    printf("%d\n", data);

    return;
}

void link_print_all(node_t *head)
{
    head=head->next;
    while(head->next != NULL)
   {
        printf("%d\n", head->data.fd);
        head=head->next;
    }
    
    return ;
}

node_t *link_seek(node_t *head, int data)
{
    while(head->data.fd != data)
    {
        head=head->next;
    }
    
    return head;
}

void link_free_all(node_t *head)
{
    node_t      *tmp = NULL;   

    while(head->next != NULL)
    {
        tmp=head->next;
        free(head);
        head=tmp;
    }
    free(head);
    
    return;
}

void link_free_specified(node_t *head, int data)
{
    node_t      *tmp = NULL;

    while(head->next->data.fd != data)
    {
        head=head->next;
    }
    tmp=head->next;
    free(head->next);
    head->next=tmp->next;

    return;
}

#if 1
int main(int argc, char *argv[])
{
    node_t      *head;
    int         i = 0;
    
    head=link_init();
    
    for(i=0; i<=8; i++)
    {
        link_insert(head, i);
    }
    link_print_specified(head, 2);
    link_print_all(head);
    link_free_all(head);

    return 0;
}
#endif
