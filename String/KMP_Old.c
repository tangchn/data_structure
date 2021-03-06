﻿/*************************************************************************
	> File Name: KMP_Old.c
	> Description: KMP模式匹配算法
	> Author: Yves
	> E-mail: tangye@hotmail.com
	> Created Time: 2015-2-13. 11:53:51
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void KMP(const char* source, const int sLen, const char* target, 
	const int tLen, const int* next, int* result);
static void GetNext(const char* target, const int tLen, int* next);

int main(void)
{
    const char source[] = "abaaabbababbababba;abaababbababaabba";
    const char target[] = "ababbaba";
    int sLen = strlen(source);
    int tLen = strlen(target);
    int next[tLen+1];//注意转移数组的元素要比target多1个
    int result[sLen];//出现最多次数为sLen个位置
    int i;
    for(i = 0; i < sLen; i++)
    {
        result[i] = -1;
    }
    GetNext(target,tLen,next);
    printf("转移数组: ");
    for(i = 0; i < tLen+1; i++)
    {
        printf("%d  ",next[i]);
    }
    printf("\n");
    KMP(source,sLen,target,tLen,next,result);
    if(result[0] == -1)
    {
        printf("字符串%s中不含有字符串%s\n",source,target);
    }else
    {
        i = 0;
        do
        {
            printf("匹配成功，字符串%s在字符串中第%d次出现的位置为%d\n",target,i+1,result[i]);
        }while(result[++i] != -1);
    }
    return 0;
}

static void KMP(const char* source, const int sLen, const char* target, 
const int tLen, const int* next, int* result)
{
    int i,j,k;
    i = k = 0;
    j = -1;
    while(i < sLen)
    {
        if((j == -1) || (source[i] == target[j]))
        {
            i++;
            j++;
        }else
        {
            j = next[j];
        }
        if(j == tLen)//找到的时候
        {
            result[k++] = (i-j);
        }
    }
}

static void GetNext(const char* target, const int tLen, int* next)
{
    int i,j;
    i = 0;
    j = -1;
    next[0] = -1;
    while(i < tLen)
    {
        if((j == -1) || (target[j] == target[i]))
        {
            i++;
            j++;
            if(target[i] != target[j])
            {	
            	next[i] = j;
            }else
            {
            	next[i] = next[j];
            }
            
        }else
        {
            j = next[j];
        }
    }
}
