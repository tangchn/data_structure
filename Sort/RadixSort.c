/*************************************************************************
	> File Name: RadixSort.c
	> Description: 基数排序
	> Author: Yves
	> E-mail: tangye@hotmail.com
	> Created Time: 2015-5-10. 00:12:51
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long int u64;
typedef int ElemType;
typedef struct tagListNode 
{
	ElemType key; //关键字
	int next;  //下一个节点
}ListNode;

static void Rdtsc(u64* const result);
static void InitalArray(ListNode* const array);
static void PrintArray(ListNode* const array);
static void LsdRadixSort(ListNode* const array, const int d);
static void MsdRadixSort(ListNode* const array, const int d);
static int GetDigit(int n, const int i);

const int ARRAY_NUMBER = 12;

static void Rdtsc(u64* const result)
{
    asm(
        "rdtsc\n\t"
        :"=A"(*result)
    );
}

static void InitalArray(ListNode* const array)
{
    int i;
    for(i = 0; i < ARRAY_NUMBER; i++)
    {
    	array[i].key = (ElemType)rand()%1000;
    	array[i].next = i + 1;
    }
    array[0].key = (ElemType)0;
    array[ARRAY_NUMBER].next = 0;
}

static void PrintArray(ListNode* const array)
{
	int i;
	for(i = array[0].next; i != 0; i= array[i].next)
	{
		printf("%d ",array[i].key);
	}
    printf("\n");
}

static void LsdRadixSort(ListNode* const array, const int d)
{
    int i, j, k;
    int current, last;
    int rear[ARRAY_NUMBER], front[ARRAY_NUMBER];
    
    for(i = 0; i < d; i++)
    {
    	for(j = 0; j < ARRAY_NUMBER; j ++)
    	{
    		front[j] = 0;
    	}
    	for(current = array[0].next; current != 0; current = array[current].next)
    	{
    		k = GetDigit(array[current].key, i + 1);
    		if(front[k] == 0)
    		{
    			front[k] = current;
    			rear[k] = current;
    		}else
    		{
    			array[rear[k]].next = current;
    			rear[k] = current;
    		}
    	}
    	j = 0;
    	while(front[j] == 0)
    	{
    		j++;
    	}
    	array[0].next = current = front[j];
    	last = rear[j];
    	for(j = j + 1; j < ARRAY_NUMBER; j++)
    	{
    		if(front[j] != 0)
    		{
    			array[last].next = front[j];
    			last = rear[j];
    		}
    	}
    	array[last].next = 0;
    }
}

static int GetDigit(ElemType n, const int i)
{
	int j;
	for(j = 1; j < i; j++)
	{
		n /= 10;
	}
	return n % 10;
}

int main(void)
{
    int i;
    u64 begin,end;
    ListNode* const array = (ListNode*)malloc(sizeof(ListNode)*(ARRAY_NUMBER + 1));
    InitalArray(array);
    PrintArray(array);

    Rdtsc(&begin);
    LsdRadixSort(array, 3);
    Rdtsc(&end);
    printf("基数排序后的数组是:");
    PrintArray(array);
    printf("花费时间为:%llu \n",end - begin);
    
    return 0;
}
