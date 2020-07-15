/*********************************************************************************
 *      Copyright:  (C) 2020 longyongtu<longyongtu13@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  cjson_study_1.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(15/07/20)
 *         Author:  longyongtu <longyongtu13@qq.com>
 *      ChangeLog:  1, Release initial version on "15/07/20 22:11:05"
 *                 
 ********************************************************************************/

#include <stdio.h>
#include "cJSON.h"

int main()
{
    cJSON * root =  cJSON_CreateObject();

    cJSON_AddItemToObject(root, "name", cJSON_CreateString("Taylor Swift"));//根节点下添加
    cJSON_AddItemToObject(root, "age", cJSON_CreateNumber(31));
    cJSON_AddItemToObject(root, "album", cJSON_CreateString("Lover"));
    cJSON_AddItemToObject(root, "song", cJSON_CreateString("Miss Americana & The Heartbreak Prince"));

    printf("%s\n", cJSON_Print(root));

    return 0;
}

