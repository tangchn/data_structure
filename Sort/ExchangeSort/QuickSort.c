/*************************************************************************
	> File Name: QuickSort.c
	> Description: 快速排序
	> Author: Yves
	> E-mail: tangye@hotmail.com
	> Created Time: 2015-5-6. 21:28:51
 ************************************************************************/

#include <stdlib.h>
#include <stdio.h>

typedef int ElemType;

static void QuickSort(ElemType *array,int left,int right);
static void InitalArray(ElemType* array);
static void PrintArray(ElemType* array);

const int ARRAY_NUMBER = 12;

static void QuickSort(ElemType *array,int left,int right)
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
    int i;
    for(i = 0; i < ARRAY_NUMBER; i++)
    {
        array[i] = rand()%100;
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

int main(void)
{
    ElemType* array = (ElemType*)malloc(sizeof(ElemType)*ARRAY_NUMBER);
    InitalArray(array);
    PrintArray(array);
    QuickSort(array,0,ARRAY_NUMBER-1);
    printf("排序结果为：");
    PrintArray(array);
    return 0;
}
