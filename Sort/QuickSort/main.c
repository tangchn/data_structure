#include <stdlib.h>
#include <stdio.h>

#define ARRAYNUMBER 12
typedef int ElemType;

void QuickSort(ElemType *array,int left,int right);
void InitalArray(ElemType* array);
void PrintArray(ElemType* array);

void QuickSort(ElemType *array,int left,int right)
{
    int i,j;
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
    QuickSort(array,0,ARRAYNUMBER-1);
    printf("排序结果为：");
    PrintArray(array);
    return 0;
}
