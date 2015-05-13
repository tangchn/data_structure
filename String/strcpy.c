/*************************************************************************
	> File Name: strcpy.c
	> Author: Yves
	> E-mail: ty@msn.cn
	> Created Time: 2015-05-13. 23:44:53
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

static char* strcpy(const char* src, char* dst);

int main(void)
{
	char* src = "Hello Yves";
	size_t len = strlen(test_string);
	char* dst = (char*)malloc(len*sizeof(char));
	dst = strcpy(src,dst);
	printf("The content 'dst' is: %s\n",dst);
}

static char* strcpy(const char* src, char* dst)
{
	assert(dst != NULL && src != NULL);
	char* cp = dst;
	while((*(++dst) = *(++src)) != '\0');
	return dst;
}
