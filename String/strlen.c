/*************************************************************************
	> File Name: strlen.c
	> Author: Yves
	> E-mail: ty@msn.cn
	> Created Time: 2015-05-13. 22:59:19
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

static size_t strlen(const char* str);

int main(void)
{
	char* test_string = "Hello Yves";
	printf("The size of 'test_string' is: %d\n",strlen(test_string));
}

static size_t strlen(const char* str)
{
	const char *s;
	s = str;
	while(*s)
	{
		s++;
	}
	return (s - str);
}
