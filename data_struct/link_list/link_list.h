/********************************************************************************
 *      Copyright:  (C) 2020 longyongtu<longyongtu13@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  link_list.h
 *    Description:  This head file 
 *
 *        Version:  1.0.0(31/07/20)
 *         Author:  longyongtu <longyongtu13@qq.com>
 *      ChangeLog:  1, Release initial version on "31/07/20 14:50:51"
 *                 
 ********************************************************************************/

#ifndef _LINK_LIST_H
#define _LINK_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* data of link list, you can choice data that you want to set */
typedef struct link_data
{
    int   fd;
}link_data_t;

/* node of link list */
typedef struct node
{
    struct node*    next;
    link_data_t     data;   
}node_t;


/*! \brief Brief function description here
 *
 *  Detailed description: no para
 *
 * \return head point in successful , negative is error
 */
node_t *link_init();


/*! \brief insert data into link list
 *
 *  Detailed description of the function
 *  para1: head point of link list
 *  para2: data you want to insert to link
 *
 * \return 
 */
void link_insert(node_t *head, int data);


/*! \brief print data that you want to print
 *
 *  Detailed description of the function
 *
 * \param  head point of link list
 * \param  data that you want to specified
 *
 * \return 0 is successful error is negative
 */
void link_print_specified(node_t *head, int data);


/*! \brief print all data 
 *
 *  Detailed description of the function
 *
 * \param  head data of link list
 *
 * \return 
 */
void link_print_all(node_t *head);
    

/*! \brief seek a node of link list
 *
 *  Detailed description of the function
 *
 * \param  head point of link list
 * \param  data you want to seek
 * \return point that you want to seek , error is NULL
 */
node_t *link_seek(node_t *head, int data);


/*! \brief free all node of link
 *
 *  Detailed description of the function
 *
 * \param head of point
 * \return 
 */
void link_free_all(node_t *head);


/*! \brief free specified node of link
 *
 *  Detailed description of the function
 *
 * \param head of data
 * \param data of specified node 
 * \return 
 */
void link_free_specified(node_t *head, int data);
    
       

#endif
