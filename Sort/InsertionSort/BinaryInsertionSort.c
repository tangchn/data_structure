/*************************************************************************
	> File Name: BinaryInsertionSort.c
	> Description: 折半插入排序
	> Author: Yves
	> E-mail: tangye@hotmail.com
	> Created Time: 2015-4-28. 23:17:51
 ************************************************************************/
 
#include <stdlib.h>
#include <stdio.h>

typedef int ElemType;

void Insertsort(ElemType *array,int n);
void InitalArray(ElemType* array);
void PrintArray(ElemType* array);

const int ARRAY_NUMBER = 5;

/*
*将直接插入排序的查找过程改成折半查找，即可将直接插入排序变成折半插入排序
*/
void BinaryInsertionSort(ElemType array[], int n)
{
	int i,j;
	int start,end,mid;
	ElemType temp;
	for(i = 1; i < n; i++)
	{
		temp = array[i];
		start = 0;
		end = i - 1;
		//通过折中查找得到的start为temp值应该插入的位置
		//如1，4，5，17，26，33中，27经过折中查找后位置为5
		while(end >= start)
		{
		        mid = start + (end - start) / 2;
		        if(temp > array[mid])
		        {
		                start = mid + 1;
		        }else if(temp < array[mid])
		        {
		                end = mid - 1;
		        }else
		        {
		                break;
		        }
		}
		for(j = i - 1; j >= start; j--)//array[j]必须大于temp才是合适的位置
		{
			array[j+1] = array[j];//元素开始后移		
		}
		array[start] = temp;
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
    BinaryInsertionSort(array,ARRAYNUMBER);
    printf("排序结果为：");
    PrintArray(array);
    return 0;
}
