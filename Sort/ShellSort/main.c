#include <stdlib.h>
#include <stdio.h>

#define ARRAYNUMBER 12
typedef int ElemType;

void ShellSort(ElemType *array,int n);
void InitalArray(ElemType* array);
void PrintArray(ElemType* array);


/*void ShellSort(int *array, int n)
{
    int group, i, j, temp;
    for (group = n / 2; group > 0; group /= 2)
    {
        for (i = group; i < n; i++)
        {
            //此种方法简单但是效率不高
            for (j = i - group; j >= 0; j -= group)
            {
                if (array[j] > array[j + group])
                {
                    temp = array[j];
                    array[j] = array[j + group];
                    array[j + group] = temp;
                }
            }
            if(array[i] < array[i - group])
            {
                temp = array[i];
			    //找到一个后面比前面小的，然后开始找位置
			    for (j = i - group; j >= 0 && array[j] > temp; j-= group)//array[j]必须大于temp才是合适的位置
                {
                    array[j + group] = array[j];//元素开始后移
                }
			    array[j + group] = temp;
            }
        }
        printf("group = %d 时，数组为：",group);
        PrintArray(array);
    }
}*/

void ShellSort(ElemType *array, int n)
{
	int gap;
	int i,j;
	ElemType temp;
	while(gap > 1)
	{
		gap = gap / 3 + 1;
		for(i = gap; i < n; i++)
		{
			temp = array[i];
			for(j = i - gap; array[j] > temp && j > 0; j -= gap)
			{
				array[j + gap] = array[j];
			}
			array[j + gap] = temp;
		}
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
    ShellSort(array,ARRAYNUMBER);
    printf("排序结果为：");
    PrintArray(array);
    return 0;
}
