/*************************************************************************
	> File Name: BubbleSort.c
	> Description: 冒泡排序
	> Author: Yves
	> E-mail: tangye@hotmail.com
	> Created Time: 2015-5-3. 22:58:51
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

const int ARRAY_NUMBER = 12;

typedef unsigned long long int u64;
typedef int ElemType;

static void Rdtsc(u64* const result);
static void InitalArray(ElemType* const array);
static void PrintArray(ElemType* const array);
static void BubbleSort(ElemType* const array);
static void BubbleSort2(ElemType* const array);
static void BubbleSort3(ElemType* const array);

static void Rdtsc(u64* result)
{
    asm(
        "rdtsc\n\t"
        :"=A"(*result)
    );
}

static void InitalArray(ElemType* const array)
{
    int i;
    for(i = 0; i < ARRAY_NUMBER ; i++)
    {
        array[i] = (ElemType)rand()%100;
    }
}

static void PrintArray(ElemType* const array)
{
    int i;
    for(i = 0; i < ARRAY_NUMBER ; i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}


static void BubbleSort(ElemType* const array)
{
    int i,j;
    ElemType temp;
    for(i = 0; i < ARRAY_NUMBER ; i ++)
    {
    	for(j = i + 1; j < ARRAY_NUMBER ; j++)
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
/*这才是“冒泡”吧*/
static void BubbleSort2(ElemType* const array)
{
    int i,j;
    ElemType temp;
    for(i = 0; i < ARRAY_NUMBER ; i++)
    {
    	for(j = ARRAY_NUMBER - 1; j > i; j--)
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

static void BubbleSort3(ElemType* const array)
{
    int i,j,flag;
    ElemType temp;
    for(i = 0; i < ARRAY_NUMBER  && flag; i++)
    {
        flag = 0;
        for(j = ARRAY_NUMBER  - 1; j > i; j--)
        {
            if(array[j-1] > array[j])
            {
                temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
                flag = 1;//若该轮交换过置1，否则就跳过后面的
            }
        }
    }
}

static void BubbleSort4(ElemType* const array)
{
    int i,j;
    ElemType temp;
    int lastpos = 0,lastposition = 0;
    for(i = 0; i < ARRAY_NUMBER ; i++)
    {
        lastposition = lastpos;
        for(j = ARRAY_NUMBER  - 1; j > lastposition; j--)
        {
            if(array[j-1] > array[j])
            {
                temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
                lastpos = j;
            }
        }
        if(lastposition == lastpos)
        {
        	break;
        }
    }
}

int main(void)
{
    int i;
    u64 begin,end;
    ElemType* const array = (int*)malloc(sizeof(int)*ARRAY_NUMBER );
    InitalArray(array);
    PrintArray(array);

    ElemType* tempArray1 =  (int*)malloc(sizeof(int)*ARRAY_NUMBER );
    ElemType* tempArray2 =  (int*)malloc(sizeof(int)*ARRAY_NUMBER );
    ElemType* tempArray3 =  (int*)malloc(sizeof(int)*ARRAY_NUMBER );
    for(i = 0; i < ARRAY_NUMBER ; i++)
    {
        tempArray1[i] = array[i];
        tempArray2[i] = array[i];
        tempArray3[i] = array[i];
    }

    //冒泡排序
    Rdtsc(&begin);
    BubbleSort(array);
    Rdtsc(&end);
    printf("冒泡排序后的数组是:");
    PrintArray(array);
    printf("花费时间为:%llu \n",end - begin);

    Rdtsc(&begin);
    BubbleSort2(tempArray1);
    Rdtsc(&end);
    printf("冒泡排序2后的数组是:");
    PrintArray(tempArray1);
    printf("花费时间为:%llu \n",end - begin);

    Rdtsc(&begin);
    BubbleSort3(tempArray2);
    Rdtsc(&end);
    printf("冒泡排序3后的数组是:");
    PrintArray(tempArray2);
    printf("花费时间为:%llu \n",end - begin);
    
    Rdtsc(&begin);
    BubbleSort4(tempArray3);
    Rdtsc(&end);
    printf("冒泡排序4后的数组是:");
    PrintArray(tempArray3);
    printf("花费时间为:%llu \n",end - begin);

    return 0;
}
