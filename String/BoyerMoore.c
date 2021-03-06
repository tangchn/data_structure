/*************************************************************************
	> File Name: BoyerMoore.c
	> Author: Yves
	> E-mail: tangye@hotmail.com
	> Created Time: 2015-05-16. 16:13:43
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int ASCII_SIZE = 256;

static void BadCharacter(const char* pattern, const size_t pLen, int* badSuffixes);
static void CalculatSuffixes(const char* pattern, const size_t pLen, int* suff);
static void GoodSuffixes(const char* pattern, const size_t pLen, int* goodSuffixes);
static void BoyerMoore(const char* target, const size_t tLen, const char* pattern, const size_t pLen, int* const result);

/*字符串中每个字符距离最右的大小*/
static void CalculateBadCharacter(const char* pattern, const size_t pLen, int* badSuffixes)
{
	size_t i;
	for(i = 0; i < ASCII_SIZE; i++)
	{
		badSuffixes[i] = pLen;
	}
	for(i = 0; i < pLen; i++)
	{
		badSuffixes[(unsigned char)pattern[i]] = pLen - 1 - i;
	}
}

/*suff[i]表示pattern中第i个字符左边，有suff[i]个字符和pattern的后缀相匹配*/
static void CalculatSuffixes(const char* pattern, const size_t pLen, int* suff)
{
	size_t i, j;
	suff[pLen -1] = pLen;
	for(i = pLen - 2, j = 0; i >=0; i--)
	{
		for(j = 0; pattern[pLen - 1 - j] == pattern[i - j] && j <= i; j++);
		suff[i] = j;
	}
}

/*好后缀*/
static void CalculateGoodSuffixes(const char* pattern, const size_t pLen, int* goodSuffixes)
{
	size_t i, j;
	int suff[pLen];
	CalculatSuffixes(pattern, pLen, suff);
	//全部设为pLen，这是后缀前缀都没有的情况3
	for(i = 0; i < pLen; i++)
	{
		suff[i] = pLen;
	}
	j = 0;
	for(i = pLen - 1; i >= 0; i--)
	{
		//没有子串匹配上好后缀，但找到一个最大前缀
		if(suff[i] == i + 1)
		{
			for(; j < pLen - 1 - i; j++ )
			{
				//这样保证只有一次修改
				if(goodSuffixes[j] == pLen)
				{
					goodSuffixes[j] = pLen - 1 - i;
				}
			}
		}
	}
	for(i = 0; i < pLen -2; i++)
	{
		goodSuffixes[pLen- 1 - suff[i]] = pLen - i - 1;
	}
}

static void BoyerMoore(const char* target, const size_t tLen, const char* pattern, const size_t pLen, int* const result)
{
	size_t i, j, k;

	int badSuffixes[ASCII_SIZE];
	CalculateBadCharacter(pattern, pLen, badSuffixes);
	int goodSuffixes[pLen];
	CalculateGoodSuffixes(pattern, pLen, goodSuffixes);
	
	for(i = 0; i < tLen; result[i++] = -1);

	i = j = k = 0;
	while(i < tLen - pLen)
	{
		for(j = pLen - 1; target[i + j] == pattern[j] && j >=0; j--);
		if(j < 0)
		{
			result[k++] = i;
			i += goodSuffixes[0];
		}else
		{	
			int temp = badSuffixes[target[i + j]] - pLen + j + 1;			
			if(goodSuffixes[j] >= temp)
			{
				i+= goodSuffixes[j];
			}else
			{
				i+= temp;
			}				
			
		}
	}
}

int main(void)
{
	const char target[] = "abaaabbababbababba;abaababbababaabba";
	const char pattern[] = "ababbaba";
	
	const size_t tLen = strlen(target);
	const size_t pLen = strlen(pattern);	
	
	int result[tLen];
	BoyerMoore(target, tLen, pattern, pLen, result);
	int i;	
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
	
	return 0;
}
