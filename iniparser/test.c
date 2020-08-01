/*********************************************************************************
 *      Copyright:  (C) 2020 longyongtu<longyongtu13@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  test.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(01/08/20)
 *         Author:  longyongtu <longyongtu13@qq.com>
 *      ChangeLog:  1, Release initial version on "01/08/20 08:57:54"
 *                 
 ********************************************************************************/

#include <stdio.h>
#include "iniparser.h"

#define INI_PATH "conf.ini"

int main(int argc, char *argv[])
{
    dictionary       *ini = NULL;
    FILE             *fp = NULL;
    int              rv = -1;

    ini=iniparser_load(INI_PATH);
    if(ini == NULL)
    {
        printf("iniparser_load error\n");
        return -1;
    }

    /* 查看有几个section */
    rv=iniparser_getnsec(ini);   
    if(rv < 0)
    {
        return -1;
    }
    printf("the number of section is %d\n", rv);

    printf("original data:\n");
    printf("%s\n", iniparser_getstring(ini, "ip_pool:ip0", "null"));
    printf("%s\n", iniparser_getstring(ini, "ip_pool:ip1", "null"));
    printf("%s\n", iniparser_getstring(ini, "port_pool:port0", "null"));
    printf("%s\n", iniparser_getstring(ini, "username:username0", "null"));
    printf("%s\n", iniparser_getstring(ini, "password:password0", "null"));
    printf("%s\n", iniparser_getstring(ini, "clientid:clientid0", "null"));
    printf("%s\n", iniparser_getstring(ini, "topic:topic0", "null"));
    printf("%s\n", iniparser_getstring(ini, "qos:qos0", "null"));
    printf("%s\n", iniparser_getstring(ini, "qos:qos1", "null"));
    printf("%s\n", iniparser_getstring(ini, "qos:qos2", "null"));
    printf("%s\n", iniparser_getstring(ini, "retain:retain0", "null"));
    printf("%s\n", iniparser_getstring(ini, "retain:retain1", "null"));
    printf("%s\n", iniparser_getstring(ini, "keeplive:kepplive0", "null"));

    /* 修改某项数据, 不会改变原本文件的内容 */
    iniparser_set(ini, "keeplive:kepplive0", "30");

   // fp = fopen(INI_PATH, "w");
    fp = fopen(INI_PATH, "w");
    if( fp == NULL )
    {
        printf("stone:fopen error!\n");
        exit(-1);
    }
    /* 可以将我们上面设置的数据保存到对应文件中,可以修改源文件的内容 */
    iniparser_dump_ini(ini, fp);
    printf("modified data:\n");
    printf("%s\n", iniparser_getstring(ini, "keeplive:kepplive0", "null"));
    return 0;
}
