/*********************************************************************************
 *      Copyright:  (C) 2020 longyongtu<longyongtu13@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  pack_1.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(15/07/20)
 *         Author:  longyongtu <longyongtu13@qq.com>
 *      ChangeLog:  1, Release initial version on "15/07/20 22:24:56"
 *                 
 ********************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "cJSON.h"

#define FILENAME     "debug.txt"
#define SIZE         1024

int main(int argc, char *argv[])
{
    int      fd = -1;
    int      rv = -1;
    char     buf[SIZE];
    cJSON*   cjson = NULL;
    char*    string1 = NULL;
    char*    string2 = NULL;
    char*    string3 = NULL;
    int      age = 0;
       
    fd=open(FILENAME, O_RDWR);
    if(fd < 0) 
    {
        printf("open %s failure\n", FILENAME);
        return -1;
    }

    rv=lseek(fd, 0, SEEK_CUR);
    if(rv < 0) 
    {
        printf("lseek %s failure\n", FILENAME);
        return -1;
    }

    rv=read(fd, buf, sizeof(buf));
    if(rv < 0) 
    {
        printf("read %s failure\n", FILENAME);   
        return -1;
    }
    close(fd);

    cjson=cJSON_Parse(buf);//将数据转换成cjson格式,记得使用cJSON_Delete(cJSON *c), 防止内存泄漏
    if(cjson == NULL)//判断是否成功
    {
        printf("data pack to cjson failure\n");
        return -1;
    }
    printf("%s\r\n",cJSON_Print(cjson));//打印输出cjsong格式

    //cJSON_GetObjectItem(cjson,"cmd")返回的是一个结构体指针，所以我们可以通过指针知道对应的值
    string1=cJSON_GetObjectItem(cjson,"name")->valuestring;
    age=cJSON_GetObjectItem(cjson,"age")->valueint;
    string2=cJSON_GetObjectItem(cjson,"album")->valuestring;
    string3=cJSON_GetObjectItem(cjson,"song")->valuestring;

    printf("name:%s\r\n", string1);
    printf("age:%d\r\n", age);
    printf("album:%s\r\n", string2);
    printf("song:%s\r\n", string3);

    cJSON_Delete(cjson);//释放内存, 一般都是在最后释放，一定要等上面的打印完，因为这些指针指向这些内存

    
    return 0;
}
