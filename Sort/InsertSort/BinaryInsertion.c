/*************************************************************************
	> File Name: BinaryInsertion.c
	> Description: 折半插入排序
	> Author: Yves
	> Mail: mail: me@tangye.me
	> Created Time: 2015-4-28. 23:17:51
 ************************************************************************/
 
#include <stdlib.h>
#include <stdio.h>

#define ARRAYNUMBER 5
typedef int ElemType;

void Insertsort(ElemType *array,int n);
void InitalArray(ElemType* array);
void PrintArray(ElemType* array);

/*
*将直接插入排序的查找过程改成折半查找，即可将直接插入排序变成折半插入排序
*/
void BinaryInsertion(ElemType array[], int n)
{
	int i,j;
	int start,end,mid;
	ElemType temp;
	for(i = 1; i < n; i++)
	{
		temp = array[i];
		start = 0;
		end = i - 1;
		while(end >= start)
		{
		        mid = start + (end - start) / 2;
		        if(temp > array[mid])
		        {
		                start = mid + 1;
		        }else(temp < array[mid])
		        {
		                end = mid - 1;
		        }else
		        {
		                break;
		        }
		}
		for(j = i - 1; j >= mid; j--)//array[j]必须大于temp才是合适的位置
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
    BinaryInsertion(array,ARRAYNUMBER);
    printf("排序结果为：");
    PrintArray(array);
    return 0;
}
