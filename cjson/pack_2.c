/*********************************************************************************
 *      Copyright:  (C) 2020 longyongtu<longyongtu13@qq.com>
 *                  All rights reserved.
 *
 *       Filename:  pack_2.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(16/07/20)
 *         Author:  longyongtu <longyongtu13@qq.com>
 *      ChangeLog:  1, Release initial version on "16/07/20 01:18:32"
 *                 
 ********************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "cJSON.h"

#define FILENAME     "debug_2.txt"
#define SIZE         1024

void printJson(cJSON * root)//以递归的方式打印json的最内层键值对
{
    for(int i=0; i<cJSON_GetArraySize(root); i++)   //遍历最外层json键值对
    {
        cJSON * item = cJSON_GetArrayItem(root, i);        
        if(cJSON_Object == item->type)      //如果对应键的值仍为cJSON_Object就递归调用printJson
            printJson(item);
        else                                //值不为json对象就直接打印出键和值
        {
            printf("%s:", item->string);
            printf("%s\r\n", cJSON_Print(item));
        }
    }

}



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

    printJson(cjson);
    cJSON_Delete(cjson);//释放内存, 一般都是在最后释放，一定要等上面的打印完，因为这些指针指向这些内存


    return 0;
}
