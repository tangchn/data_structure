/*************************************************************************
	> File Name: heap_sort.c
	> Description: 堆排序
	> Author: Yves
	> Mail: mail: me@tangye.me
	> Created Time: 2015-5-6. 23:54:51
 ************************************************************************/
#include <stdlib.h>
#include <stdio.h>

#define ARRAYNUMBER 12
typedef int ElemType;

void HeapSort(ElemType *array, int n);
void HeapAdjust(ElemType *array, int start, int end);
void InitalArray(ElemType* array);
void PrintArray(ElemType* array);


//堆筛选函数
//已知H[start~end]中除了start之外均满足堆的定义
//本函数进行调整，使H[start~end]成为一个大顶堆
void HeapAdjust(ElemType *array, int start, int end)
{


    int i;
    ElemType temp = array[start];; //取出根节点
    i = 2 * start + 1;  //左孩子节点

    while (i <= end) {
        if (i <= end - 1 && array[i] < array[i + 1])//比较左右孩子，取出较大的孩子
            i++;

        if (temp >= array[i]) //如果根节点大于孩子节点则退出循环，不用调整
            break;

        array[(i - 1) / 2] = array[i];//较大的孩子节点值赋值给根节点

        i = 2 * i + 1;//继续寻找左孩子
        PrintArray(array);
    }
    array[(i - 1) / 2] = temp;//将根节点赋值给最后一个空出来的节点

    /*for(i = 2*start + 1; i<=end; i*=2)
    {
        //因为假设根结点的序号为0而不是1，所以i结点左孩子和右孩子分别为2i+1和2i+2
        if(i<end && array[i]<array[i+1])//左右孩子的比较(原博客有误，此处不是左右子树)
        {
            ++i;//i为较大的记录的下标
        }

        if(temp > array[i])//左右孩子中获胜者与父亲的比较,如果根节点大于孩子节点则退出循环，不用调整
        {
            break;
        }

        //将孩子结点上位，则以孩子结点的位置进行下一轮的筛选
        array[start]= array[i];//较大的孩子节点值赋值给根节点
        start = i;//调整子树

        printf("此时数组为：");
        PrintArray(array);
    }
    array[start]= temp; //插入最开始不和谐的元素*/
}

void HeapSort(ElemType *array, int n)
{
    int i;
    //先建立大顶堆
    for(i=n/2; i>=0; --i)//非叶节点最大序号值为n/2
    {
        HeapAdjust(array,i,n-1);//从倒数第二层的最后一个根节点开始调整堆
        PrintArray(array);
    }
    printf("初始化堆为：");
    PrintArray(array);
    //进行排序
    for(i = n-1; i >= 0; --i)
    {

        //最后一个元素和第一元素进行交换
        ElemType temp=array[i];//取出最后一个元素
        array[i] = array[0];//取出第一个元素，即顶层根节点
        array[0] = temp;//交换位置

        //然后将剩下的无序元素继续调整为大顶堆
        HeapAdjust(array,0,i-1);
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
    HeapSort(array,ARRAYNUMBER);
    printf("排序结果为：");
    PrintArray(array);
    return 0;
}
