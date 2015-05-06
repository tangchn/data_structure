/*************************************************************************
	> File Name: simple_selection_sort.c
	> Description: 简单选择排序
	> Author: Yves
	> Mail: mail: me@tangye.me
	> Created Time: 2015-5-6. 23:35:51
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define ARRAYNUMBER 12

typedef unsigned long long int u64;
typedef int ElemType;

void Rdtsc(u64* result);
void InitalArray(ElemType* array);
void PrintArray(ElemType* array);
void simple_selection_sort(ElemType* array);

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


void simple_selection_sort(ElemType* array)
{
    int i,j,k;
    ElemType temp;
    for(i = 0; i < ARRAYNUMBER; i ++)
    {
    	k = i;
    	for(j = i + 1; j < ARRAYNUMBER; j++)
    	{
    		//找出最小的
    		if(array[j] < array[k])
    		{
    		        k = j;	
    		}
    	}
    	if(k != i)
    	{
    	        temp = array[i];
    	        array[i] = array[k];
    	        array[k] = temp;
    	}
    }
}


int main(void)
{
    int i;
    u64 begin,end;
    ElemType* array = (int*)malloc(sizeof(int)*ARRAYNUMBER);
    InitalArray(array);
    PrintArray(array);

    Rdtsc(&begin);
    simple_selection_sort(array);
    Rdtsc(&end);
    printf("简单选择排序后的数组是:");
    PrintArray(array);
    printf("花费时间为:%llu \n",end - begin);
    
    return 0;
}
