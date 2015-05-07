/*************************************************************************
	> File Name: merge_sort.c
	> Description: 归并排序
	> Author: Yves
	> Mail: mail: me@tangye.me
	> Created Time: 2015-5-7. 21:15:51
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define ARRAYNUMBER 12

typedef unsigned long long int u64;
typedef int ElemType;

void Rdtsc(u64* result);
void InitalArray(ElemType* array);
void PrintArray(ElemType* array);
void merge_sort(ElemType* array);

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

void merge(ElemType* array, ElemType* temp, int start, int mid, int end)
{
    int i, j, k;
    i = start;
    j = mid + 1;
    k = 0;
    
    while(i <= mid && j <= end)
    {
        if(array[i] < array[j])
        {
        	temp[k++] = array[i++];
        }else
        {
        	temp[k++] = array[j++];
        }
    }
    while(i < = mid)
    {
    	temp[k++] = array[i];	
    }
    while(j <= end)
    {
    	temp[k++] = array[j];	
    }
    
    while(i = 0; i < k; i++)
    {
    	array[start + i] = temp[i];
    }
}

void merge_sort(ElemType* array, ElemType* temp, int start, int end)
{
   if(start < end)
   {
        const int mid = (start + end)/2;
        merge_sort(array, temp, start, mid);
        merge_sort(array, temp, mid, end);
        merge(array, temp, start, mid, end);
   }
}

int main(void)
{
    int i;
    u64 begin,end;
    ElemType* array = (int*)malloc(sizeof(int)*ARRAYNUMBER);
    ElemType* temp = (int*)malloc(sizeof(int)*ARRAYNUMBER);
    InitalArray(array);
    PrintArray(array);
    
    Rdtsc(&begin);
    merge_sort(array, temp, 0, ARRAYNUMBER-1);
    Rdtsc(&end);
    printf("归并排序后的数组是:");
    PrintArray(array);
    printf("花费时间为:%llu \n",end - begin);
    
    return 0;
}
