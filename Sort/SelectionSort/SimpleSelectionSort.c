/*************************************************************************
	> File Name: SimpleSelectionSort.c
	> Description: 简单选择排序
	> Author: Yves
	> E-mail: tangye@hotmail.com
	> Created Time: 2015-5-6. 23:35:51
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long int u64;
typedef int ElemType;

void Rdtsc(u64* result);
void InitalArray(ElemType* array);
void PrintArray(ElemType* array);
void SimpleSelectionSort(ElemType* array);

const int ARRAY_NUMBER = 12;

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
    for(i = 0; i < ARRAY_NUMBER; i++)
    {
        array[i] = (ElemType)rand()%100;
    }
}

void PrintArray(ElemType* array)
{
    int i;
    for(i = 0; i < ARRAY_NUMBER; i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}


void SimpleSelectionSort(ElemType* array)
{
    int i,j,k;
    ElemType temp;
    for(i = 0; i < ARRAY_NUMBER; i ++)
    {
    	k = i;
    	for(j = i + 1; j < ARRAY_NUMBER; j++)
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
    ElemType* array = (int*)malloc(sizeof(int)*ARRAY_NUMBER);
    InitalArray(array);
    PrintArray(array);

    Rdtsc(&begin);
    SimpleSelectionSort(array);
    Rdtsc(&end);
    printf("简单选择排序后的数组是:");
    PrintArray(array);
    printf("花费时间为:%llu \n",end - begin);
    
    return 0;
}
