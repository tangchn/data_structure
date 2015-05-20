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

static int BiSearch(const ElemType* array, const ElemType key);
static void QuickSort(ElemType *array, size_t left, size_t right);
static void InitalArray(ElemType* array);
static void PrintArray(ElemType* array);

int main(void)
{
	ElemType array[ARRAY_NUMBER];
	InitalArray(array);
	QuickSort(array, 0, ARRAY_NUMBER - 1);
	PrintArray(array);
	ElemType key = 59;
	printf("%d is the %dth element of the array.\n", key, BiSearch(array, key));
	return 0;
}

static int BiSearch(const ElemType* array, const ElemType key)
{
	if(key > array[ARRAY_NUMBER - 1])
	{
		return -1;
	}
	size_t start, end, mid;
	start = 0;
	end = ARRAY_NUMBER;
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
    if(left >= right)
    {
        return;
    }
    int i,j;
    ElemType temp, base;
    base = array[left];
    i = left;
    j = right;
    while(i < j)
    {
        //顺序很重要，要先从右边开始找
        while(array[j] >= base && j > i)
        {
            j--;
        }
        array[i] = array[j];
        while(array[i] <= base && i < j)
        {
            i++;
        }
        array[j] = array[i];
        //上述在查找过程中同时完成了数据的交换
     	/*也可以比较完了之后再交换
        /*方法二
        if(i < j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp; 
        }
        //方法二while循环完了之后，加上下面的语句
        array[left] = array[i];//j先行保证了此时a[i]是小于temp的，因此也可以是array[left] = array[j];
        */
    }
    //最终将基准数归位
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
