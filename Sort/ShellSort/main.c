/*************************************************************************
	> File Name: main.c
	> Description: 希尔排序
	> Author: Yves
	> Mail: mail: me@tangye.me
	> Created Time: 2015-4-28. 23:50:51
 ************************************************************************/
#include <stdlib.h>
#include <stdio.h>

#define ARRAYNUMBER 10
typedef int ElemType;

void ShellSort(ElemType *array,int n);
void InitalArray(ElemType* array);
void PrintArray(ElemType* array);

/*
*很奇怪，运行会报Segmentation fault，但是用gdb调试就不会，怎么回事？
*/
void ShellSort(ElemType *array, int n)
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

void InitalArray(ElemType* array)
{
    int i;
    for(i = 0; i < ARRAYNUMBER; i++)
    {
        array[i] = rand()%100;
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

int main(void)
{
    ElemType* array = (ElemType*)malloc(sizeof(ElemType)*ARRAYNUMBER);
    InitalArray(array);
    PrintArray(array);
    ShellSort(array,ARRAYNUMBER);
    printf("排序结果为：");
    PrintArray(array);
    return 0;
}
