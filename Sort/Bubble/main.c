/*************************************************************************
	> File Name: BinaryInsertion.c
	> Description: 折半插入排序
	> Author: Yves
	> Mail: mail: me@tangye.me
	> Created Time: 2015-5-3. 22:58:51
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define ARRAYNUMBER 12

typedef unsigned long long int u64;
typedef int ElemType;

void Rdtsc(u64* result);
void InitalArray(ElemType* array);
void PrintArray(ElemType* array);
void BubbleSort(ElemType* array);//冒泡排序
void BubbleSort2(ElemType* array);
void BubbleSort3(ElemType* array);

void Rdtsc(u64* result)
{
    asm(
        "rdtsc\n\t"
        :"=A"(*result)
    );
}

void InitalArray(ElemType* array)
{
    int i;
    for(i = 0; i < ARRAYNUMBER; i++)
    {
        array[i] = (ElemType)rand()%100;
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

void BubbleSort(int* array)
{
    int i,j,temp;
    for(i = 0; i < ARRAYNUMBER; i++)
    {
        for(j = i + 1; j < ARRAYNUMBER; j++)
        {
            if(array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void BubbleSort2(int* array)
{
    int i,j,temp;
    for(i = 0; i < ARRAYNUMBER; i++)
    {
        for(j = ARRAYNUMBER - 1; j > i; j--)
        {
            if(array[j-1] > array[j])
            {
                temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
            }
        }
    }
}

void BubbleSort3(int* array)
{
    int i,j,temp,flag;
    flag = 0;
    for(i = 0; i < ARRAYNUMBER && flag; i++)
    {
        for(j = ARRAYNUMBER - 1; j > i; j--)
        {
            if(array[j-1] > array[j])
            {
                temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
                flag = 1;
            }
        }
    }
}

int main(void)
{
    int i;
    u64 begin,end;
    ElemType* array = (int*)malloc(sizeof(int)*ARRAYNUMBER);
    InitalArray(array);
    PrintArray(array);

    ElemType* tempArray =  (int*)malloc(sizeof(int)*ARRAYNUMBER);
    for(i = 0; i < ARRAYNUMBER; i++)
    {
        tempArray[i] = (ElemType)i;
    }

    //冒泡排序
    Rdtsc(&begin);
    BubbleSort(tempArray);
    Rdtsc(&end);
    printf("冒泡排序后的数组是:");
    PrintArray(tempArray);
    printf("花费时间为:%llu \n",end - begin);

    Rdtsc(&begin);
    BubbleSort2(tempArray);
    Rdtsc(&end);
    printf("冒泡排序2后的数组是:");
    PrintArray(tempArray);
    printf("花费时间为:%llu \n",end - begin);

    Rdtsc(&begin);
    BubbleSort3(tempArray);
    Rdtsc(&end);
    printf("冒泡排序3后的数组是:");
    PrintArray(tempArray);
    printf("花费时间为:%llu \n",end - begin);

    return 0;
}
