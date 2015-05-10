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

static void Rdtsc(u64* result);
static void InitalArray(List_node* array);
static void PrintArray(List_node* array);
static void radix_sort_lsd(List_node* array, const int d);
static void radix_sort_msd(List_node* array, const int d);
static int get_digit(int n, const int i);

typedef struct List_node_t 
{
	ElemType key; //关键字
	int next;  //下一个节点
}List_node;

static void Rdtsc(u64* result)
{
    asm(
        "rdtsc\n\t"
        :"=A"(*result)
    );
}

static void InitalArray(List_node* array)
{
    int i;
    //头指针
    array[0].key = (ElemType)0;
    array[0].next = 0;
    for(i = 1; i < ARRAYNUMBER; i++)
    {
        array[i].key = (ElemType)rand()%1000;
        array[i].next = 0;
    }
}

static void PrintArray(List_node* array)
{
	int i;
	for(i = array[0].next; i != 0; array[i].next)
	{
		printf("%d ",array[i].key);
	}
    	printf("\n");
}

static void radix_sort_lsd(List_node* array, const int d)
{
    int i, j, k;
    int current, last;
    int rear[ARRAYNUMBER], front[ARRAYNUMBER];
    
    for(i = 0; i < ARRAYNUMBER; i++)
    {
    	array[i].next = i + 1;
    }
    array[ARRAYNUMBER].next = 0;
    for(i = 0; i < d; i++)
    {
    	for(j = 0; j < ARRAYNUMBER; j ++)
    	{
    		front[j] = 0;
    	}
    	for(current = array[0].next; current != 0; current = array[current].next)
    	{
    		k = get_dit(array[current].key, i + 1);
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
    	for(j = j + 1; j < ARRAYNUMBER; j++)
    	{
    		if(front[j] != 0)
    		{
    			array[last].next = front[j];
    			last = rear[j]
    		}
    	}
    	array[last].next = 0;
    }
}

static int get_digit(ElemType n, const int i)
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
    List_node* array = (List_node*)malloc(sizeof(List_node)*(ARRAYNUMBER + 1));
    InitalArray(array);
    PrintArray(array);

    Rdtsc(&begin);
    radix_sort_lsd(array, 3);
    Rdtsc(&end);
    printf("基数排序后的数组是:");
    PrintArray(array);
    printf("花费时间为:%llu \n",end - begin);
    
    return 0;
}
