/*************************************************************************
	> File Name: ShellSort.c
	> Description: 希尔排序
	> Author: Yves
	> E-mail: tangye@hotmail.com
	> Created Time: 2015-4-28. 23:50:51
 ************************************************************************/
#include <stdlib.h>
#include <stdio.h>

typedef int ElemType;

static void ShellSort(ElemType* const array,const int n);
static void InitalArray(ElemType* const array);
static void PrintArray(ElemType* const array);

const int ARRAY_NUMBER  = 10;

/*
*很奇怪，运行会报Segmentation fault，但是用gdb调试就不会，怎么回事？
*/
static void ShellSort(ElemType* const array, const int n)
{
	int gap = n;
	int i,j;
	ElemType temp;
	while(gap > 1)
	{
		gap = gap / 3 + 1;
		for(i = gap; i < n; i++)
		{
			temp = array[i];
			for(j = i - gap; array[j] > temp && j >= 0; j -= gap)
			{
				array[j + gap] = array[j];
			}
			array[j + gap] = temp;
		}
	}
}

static void InitalArray(ElemType* const array)
{
    int i;
    for(i = 0; i < ARRAY_NUMBER; i++)
    {
        array[i] = rand()%100;
    }
}

static void PrintArray(ElemType* const array)
{
    int i;
    for(i = 0; i < ARRAY_NUMBER; i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}

int main(void)
{
    ElemType* const array = (ElemType*)malloc(sizeof(ElemType)*ARRAY_NUMBER);
    InitalArray(array);
    PrintArray(array);
    ShellSort(array,ARRAY_NUMBER);
    printf("排序结果为：");
    PrintArray(array);
    return 0;
}
