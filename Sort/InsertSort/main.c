#include <stdlib.h>
#include <stdio.h>

#define ARRAYNUMBER 5
typedef int ElemType;

void Insertsort(ElemType *array,int n);
void InitalArray(ElemType* array);
void PrintArray(ElemType* array);

/*void Insertsort(ElemType array[], int n)
{
	int i, j;
	for (i = 1; i < n; i++)
		if (array[i] < array[i - 1])
		{
			int temp = array[i];
			//找到一个后面比前面小的，然后开始找位置
			for (j = i - 1; j >= 0 && array[j] > temp; j--)//array[j]必须大于temp才是合适的位置
            {
                array[j + 1] = array[j];//元素开始后移
            }
			array[j + 1] = temp;
		}
		//还有一种方法,但是这种貌似效率不好
	for(j = i - 1; j >=0 && array[j] > array[j+1]; j--)
        {
            int temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
        }
}*/

void Insertsort(ElemType array[], int n)
{
	int i,j;
	ElemType temp;
	for(i = 1; i < n; i++)
	{
		temp = array[i];
		for(j = i - 1; j >= 0 && array[j] > temp; j--)
		{
			array[j+1] = array[j];		
		}
		array[j+1] = temp;
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
    Insertsort(array,ARRAYNUMBER);
    printf("排序结果为：");
    PrintArray(array);
    return 0;
}
