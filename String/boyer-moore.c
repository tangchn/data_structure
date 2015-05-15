/*************************************************************************
	> File Name: boyer-moore.c
	> Author: Yves
	> E-mail: ty@msn.cn
	> Created Time: 2015-05-16. 16:13:43
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int ASCII_SIZE = 256;

/*字符串中每个字符最靠右的位置*/
static void rightmost(const char* pattern, const size_t pLen, int* right)
{
	size_t i;
	for(i = 0; i < ASCII_SIZE; i++)
	{
		right[i] = m;
	}
	for(i = 0; i < pLen; i++)
	{
		right[(unsigned char)pattern[i]] = m - 1 - i;
	}
}

int main(void)
{
	const char target[] = "abaaabbababbababba;abaababbababaabba";
	const char pattern[] = "ababbaba";
	int right[ASCII_SIZE];
	const size_t tLen = strlen(target);
	const size_t pLen = strlen(pattern);
	
	rightmost(pattern, pLen, right);
}


