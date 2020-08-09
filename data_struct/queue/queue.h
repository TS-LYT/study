/********************************************************************************
 *      Copyright:  (C) 2020 longyongtu<longyongtu13@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  queue.h
 *    Description:  This head file 
 *
 *        Version:  1.0.0(01/08/20)
 *         Author:  longyongtu <longyongtu13@qq.com>
 *      ChangeLog:  1, Release initial version on "01/08/20 16:20:04"
 *                 
 ********************************************************************************/

#ifndef         _QUEUE_H
#define         _QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct que_data
{
    int         fd;
}que_data_t;

typedef struct que_node
{
    struct que_node     *next;
    que_data            data;
}que_node_t;

typedef struct que_head_tail
{
    que_node_t          *front;
    que_node_t          *rear;
}que_head_tail_t

/*! \brief creat head and tail point of queque
 *
 *  Detailed description of the function
 
 * \return head and tail point struct
 */
que_head_tail_t *que_init();


/*! \brief determine whether the queque is empty
 *
 *  Detailed description of the function
 *
 * \param  head and tail of queue
 * \return empty is 1, not empty is nagetive
 */
int que_empty(que_head_tail_t *tmp);


/*! \brief insert data into front of queue
 *
 *  Detailed description of the function
 *
 * \param head and tail of queue
 * \param data you want to insert to queue
 * \return 0 in case of successful, nagetive in case of erro
 */
int que_insert(que_head_tail_t *tmp, que_data_t *data);


/*! \brief delete data int rear of queue
 *
 *  Detailed description of the function
 *
 * \param  head and tail of queue
 * \return 0 in case of successful, nagetive in case of erro
 */
int que_delete(que_head_tail_t *tmp);
       



#endif
