/*************************************************************************
	> File Name: radix_sort.c
	> Description: 基数排序
	> Author: Yves
	> Mail: mail: me@tangye.me
	> Created Time: 2015-5-10. 00:12:51
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define ARRAYNUMBER 12

typedef unsigned long long int u64;
typedef int ElemType;

void Rdtsc(u64* result);
void InitalArray(ElemType* array);
void PrintArray(ElemType* array);
void radix_sort_lsd(ElemType* array);
void radix_sort_msd(ElemType* array);

void Rdtsc(u64* result)
{
    asm(
        "rdtsc\n\t"
        :"=A"(*result)
    );
}

void InitalArray(ElemType* array)
{
    int i;
    for(i = 0; i < ARRAYNUMBER; i++)
    {
        array[i] = (ElemType)rand()%100;
    }
}

void PrintArray(ElemType* array)
{
    int i;
    for(i = 0; i < ARRAYNUMBER; i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}


void radix_sort_lsd(ElemType* array)
{
    int i,j,k;
    ElemType temp;
}


int main(void)
{
    int i;
    u64 begin,end;
    ElemType* array = (int*)malloc(sizeof(int)*ARRAYNUMBER);
    InitalArray(array);
    PrintArray(array);

    Rdtsc(&begin);
    radix_sort_lsd(array);
    Rdtsc(&end);
    printf("简单选择排序后的数组是:");
    PrintArray(array);
    printf("花费时间为:%llu \n",end - begin);
    
    return 0;
}
