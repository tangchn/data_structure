/*************************************************************************
	> Author: Yves
	> E-mail: tanngye@hotmail.com
	> File Name: BiSearch.c
	> Description: ...
	> Created  Time: 2015-05-20. 11:11:30
	> Modified Time: 2015-05-20. 11:11:30
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
const int ARRAY_NUMBER = 30;
typedef int ElemType;

static int BiSearch(const ElemType* array, const int n, const ElemType key);
static void QuickSort(ElemType *array, size_t left, size_t right);
static void InitalArray(ElemType* array);
static void PrintArray(ElemType* array);

int main(void)
{
	ElemType array[ARRAY_NUMBER];
	InitalArray(array);
	QuickSort(array, 0, ARRAY_NUMBER - 1);
	ElemType key = 55;
	printf("%d is the %dth element of the array.\n", key, 1 + BiSearch(array, 10, key));
	return 0;
}

static int BiSearch(const ElemType* array, const int n, const ElemType key)
{
	if(key > array[n - 1])
	{
		return -1;
	}
	size_t start, end, mid;
	start = 0;
	end = n;
	while(start <= end)
	{
		mid = (start + end) / 2;
		if(key > array[mid])
		{
			start = mid + 1;
		}else if(key < array[mid])
		{
			end = mid - 1;
		}else
		{
			return (int)mid;
		}
	}
	return -1;
}

static void QuickSort(ElemType *array, size_t left, size_t right)
{
    size_t i,j;
    ElemType temp, base;
    base = array[left];
    i = left;
    j = right;
    if(left > right)
    {
        return;
    }
    while(i < j)
    {
        //顺序很重要，要先从右边开始找
        while(array[j] >= base && j > i)
        {
            j--;
        }
        while(array[i] <= base && i < j)
        {
            i++;
        }
        //交换两个数在数组中的位置
        if(i < j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp; 
        }
    }
    //最终将基准数归位
    array[left] = array[i];//j先行保证了此时a[i]是小于temp的，因此也可以是array[left] = array[j];
    array[i] = base;
    
    QuickSort(array,left,i-1);//继续处理左边的，这里是一个递归的过程
    QuickSort(array,i+1,right);//继续处理右边的 ，这里是一个递归的过程
}

static void InitalArray(ElemType* array)
{
    size_t i;
    for(i = 0; i < ARRAY_NUMBER; i++)
    {
        array[i] = (int)rand()%100;
    }
}

static void PrintArray(ElemType* array)
{
    size_t i;
    for(i = 0; i < ARRAY_NUMBER; i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}
