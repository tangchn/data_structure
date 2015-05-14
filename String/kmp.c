/*************************************************************************
	> File Name: kmp.c
	> Author: Yves
	> E-mail: ty@msn.cn
	> Created Time: 2015-05-14. 12:48:15
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static void kmp(const char* target, const char* pattern, const size_t tLen, const size_t pLen, 
		int* result, int* next);
static void calculate_next(const char *pattern, const size_t pLen, int* next);

int main(void)
{
	const char target[] = "abaaabbababbababba;abaababbababaabba";
	const char pattern[] = "ababbaba";
	
	size_t tLen = strlen(target);
	size_t pLen = strlen(pattern);

	int next[pLen + 1];
	int result[tLen];

	/*Initial the result*/
	size_t i;
	for(i = 0; i < tLen; result[i++] = -1);

	/*Print the next array*/
	calculate_next(pattern, pLen, next);
	printf("The next array is: ");
	for(i = 0; i <= pLen; i++)
	{
		printf("%d ", next[i]);
	}
	printf("\n");

	/*Begin to match*/
	kmp(target, pattern, tLen, pLen, result, next);

	/*Print the matching result*/
	if(result[0] == -1)
	{
		printf("No match!\n");
		return 0;
	}else
	{
		printf("Matched!...\n");
		for(i = 0; i < tLen && result[i] >=0; i++)
		{
			printf("The %dth matching position is %d\n", i+1, result[i]);
		}
		return 0;
	}
}

static void kmp(const char* target, const char* pattern, const size_t tLen, const size_t pLen, 
				int* result, int* next)
{
	size_t i, j, k;
	i = k = 0;
	j = -1;
	while(i < tLen)
	{
		if(target[i] == pattern[j] || j == -1)
		{
			i++;
			j++;
		}else
		{
			j = next[j];
		}
		if(j == pLen)
		{
			result[k++] = i - j;
			j = -1;
		}
	}
}
static void calculate_next(const char *pattern, const size_t pLen, int* next)
{
	size_t i, j;
	j = -1;
	i = 0;
	next[i] = j;
	while(i < pLen)
	{
		if(pattern[i] == pattern[j] || j == -1)
		{
			i++;
			j++;
			//optimize the assignement
			if(pattern[i] != pattern[j])
			{
				next[i] = j;
			}else
			{
				next[i] = next[j];
			}
		}else
		{
			j = next[j];
		}
	}
}
