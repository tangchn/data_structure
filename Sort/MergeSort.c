/*************************************************************************
	> File Name: MergeSort.c
	> Description: 归并排序
	> Author: Yves
	> E-mail: tangye@hotmail.com
	> Created Time: 2015-5-7. 21:15:51
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long int u64;
typedef int ElemType;

static void Rdtsc(u64* result);
static void InitalArray(ElemType* array);
static void PrintArray(ElemType* array);
static void MergeSort(ElemType* array, ElemType* temp, int start, int end);
static void MergeArray(ElemType* array, ElemType* temp, int start, int mid, int end);

const int ARRAY_NUMBER = 320;

static void Rdtsc(u64* result)
{
    asm(
        "rdtsc\n\t"
        :"=A"(*result)
    );
}

static void InitalArray(ElemType* array)
{
    int i;
    for(i = 0; i < ARRAY_NUMBER; i++)
    {
        array[i] = (ElemType)rand()%100;
    }
}

static void PrintArray(ElemType* array)
{
    int i;
    for(i = 0; i < ARRAY_NUMBER; i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}

static void MergeArray(ElemType* array, ElemType* temp, int start, int mid, int end)
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
    while(i <= mid)
    {
    	temp[k++] = array[i++];	
    }
    while(j <= end)
    {
    	temp[k++] = array[j++];	
    }
    
    for(i = 0; i < k; i++)
    {
    	array[start + i] = temp[i];
    }
}

static void MergeSort(ElemType* array, ElemType* temp, int start, int end)
{
   if(start < end)
   {
        const int mid = (start + end)/2;
        MergeSort(array, temp, start, mid);
        MergeSort(array, temp, mid+1, end);
        MergeArray(array, temp, start, mid, end);
   }
}

int main(void)
{
    u64 begin,end;
    ElemType* array = (int*)malloc(sizeof(int)*ARRAY_NUMBER);
    ElemType* temp = (int*)malloc(sizeof(int)*ARRAY_NUMBER);
    InitalArray(array);
    PrintArray(array);
    
    Rdtsc(&begin);
    MergeSort(array, temp, 0, ARRAY_NUMBER-1);
    Rdtsc(&end);
    printf("归并排序后的数组是:");
    PrintArray(array);
    printf("花费时间为:%llu \n",end - begin);
    
    return 0;
}
