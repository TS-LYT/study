/*********************************************************************************
 *      Copyright:  (C) 2020 longyongtu<longyongtu13@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  hhhhh.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(15/07/20)
 *         Author:  longyongtu <longyongtu13@qq.com>
 *      ChangeLog:  1, Release initial version on "15/07/20 00:07:48"
 *                 
 ********************************************************************************/
#include <stdio.h>
#include "cJSON.h"

int main()
{
    cJSON * root =  cJSON_CreateObject();//生成的根节点
    cJSON * album =  cJSON_CreateObject();//album里嵌套的节点
    cJSON * rep_itm =  cJSON_CreateObject();//数组的里面的起始节点
    cJSON * rep_arr = cJSON_CreateArray();//生成一个空数组

    cJSON_AddItemToObject(rep_itm, "song", cJSON_CreateString("Ready For It"));//数组的第一个元素
    cJSON_AddItemToObject(rep_itm, "song", cJSON_CreateString("End Game"));//数组的第二个元素
    cJSON_AddItemToArray(rep_arr, rep_itm);//将数组的内容全部添加到这个数组的起始节点
    cJSON_AddItemToObject(album, "1989", cJSON_CreateString("Style"));//album节点下的第一个键值对
    //album节点下的第二个键值对，这是一个数组的信息，所以需要添加数组的信息
    cJSON_AddItemToObject(album, "Reputation", rep_arr);
    //albumn节点下的最后一个键值对，
    cJSON_AddItemToObject(album, "Lover", cJSON_CreateString("Miss Americana & The Heartbreak Prince"));

    cJSON_AddItemToObject(root, "name", cJSON_CreateString("Taylor Swift"));//根节点下添加第一个键值对
    cJSON_AddItemToObject(root, "age", cJSON_CreateNumber(31));//根节点下添加第二个键值对
    cJSON_AddItemToObject(root, "album", album);//节点下添加第三个键值对, album内嵌了一层，所以直接写它的指针
    cJSON_AddItemToObject(root, "address", cJSON_CreateString("Tennessee"));//跟节点下添加第四个键值对

    printf("%s\n", cJSON_Print(root));

    return 0;
}
