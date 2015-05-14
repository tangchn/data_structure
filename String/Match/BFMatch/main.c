/*************************************************************************
	> File Name: BF.c
	> Description: BF模式匹配算法
	> Author: Yves
	> Mail: mail: me@itang.me
	> Created Time: 2015-2-13. 13:40:51
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void BF(char* source, int sLen, char* target, int tLen, int* result);

int main(void)
{
    char source[] = "abaaabbababbababbaabaababbababaabba";
    char target[] = "ababbaba";
    //char source[] = "abbaababab";
    //char target[] = "aba";

    int sLen = strlen(source);
    int tLen = strlen(target);
    int result[sLen];//出现最多次数为sLen个位置
    int i = 0;

    for(i = 0; i < sLen; i++)
    {
        result[i] = -1;
    }

    BF(source,sLen,target,tLen,result);

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

void BF(char* source, int sLen, char* target, int tLen, int* result)
{
    int i,j,k;
    i = j = k = 0;

    while(i < sLen)
    {
            while(j < tLen)
            {
                if(source[i+j] != target[j])        //不等的时候
                {
                   j = 0;
                   break;
                }else{                              //相等的时候
                    j++;
                    //char source[] = "abbaababb";
                    //char target[] = "aba";
                    if(j == tLen)//找到的时候
                    {
                        result[k++] = i;
                        j = 0;
                        break;
                    }
                }
            }
            i++;

    }
}
