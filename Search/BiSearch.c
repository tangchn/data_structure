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

static int BiSearch(const int* array, const int n, const int key);
static void QuickSort(int* array, const int n);

int main(void)
{
	int array[10] = {1,7,9,23,33,55,67,89,233,654};
	int key = 55;
	printf("%d is the %dth element of the array.\n", key, 1 + BiSearch(array, 10, key));
	return 0;
}

static int BiSearch(const int* array, const int n, const int key)
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

static void QuickSort(int* array, const int n)
{

}
