/*************************************************************************
	> File Name: InsertionSort.c
	> Description: 直接插入排序
	> Author: Yves
	> Mail: mail: ty@msn.cn
	> Created Time: 2015-4-28. 23:08:51
 ************************************************************************/
#include <stdlib.h>
#include <stdio.h>

typedef int ElemType;

void InsertionSort(ElemType *array,int n);
void InitalArray(ElemType* array);
void PrintArray(ElemType* array);

const int ARRAY_NUMBER = 5;

/*
*假定a[0...i-1]为有序，a[i]..为无序，从i=1开始，将a[i]插入到一个合适的位置
*/
void InsertionSort(ElemType array[], int n)
{
	int i,j;
	ElemType temp;
	for(i = 1; i < n; i++)
	{
		temp = array[i];
		for(j = i - 1; j >= 0 && array[j] > temp; j--)//array[j]必须大于temp才是合适的位置
		{
			array[j+1] = array[j];//元素开始后移		
		}
		array[j+1] = temp;
	}
	//还有一种方法,但是这种貌似效率不好
	/*for(j = i - 1; j >=0 && array[j] > array[j+1]; j--)
        {
            int temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
        }*/
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
    InsertionSort(array,ARRAYNUMBER);
    printf("排序结果为：");
    PrintArray(array);
    return 0;
}
