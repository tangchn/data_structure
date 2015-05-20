/*************************************************************************
	> File Name: strlen.c
	> Author: Yves
	> E-mail: tangye@hotmail.com
	> Created Time: 2015-05-13. 22:59:19
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

static size_t strlen(const char* str);

int main(void)
{
	const char* const test_string = "cas@live.com";
	const char* const mailname = "tangye@hotmail.com";
	printf("The size of %s is: %d\n",mailname, strlen(mailname));
	printf("The size of %s is: %d\n",test_string, strlen(test_string));
}

static size_t strlen(const char* str)
{
	const char *s;
	for(s = str; *s; s++);
	return (s - str);
}
