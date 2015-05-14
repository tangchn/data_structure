/*************************************************************************
	> File Name: strstr.c
	> Author: Yves
	> E-mail: ty@msn.cn
	> Created Time: 2015-05-13. 23:44:40
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

static char* strstr(const char* target, const char* pattern);


int main(void)
{
	const char* target = "abbfdabaaeefeabbafasdffaa";
	const char* pattern = "abba";
	char* position;
	position = strstr(target, pattern);
	if(position != NULL)
	{
		printf("Have found! The positon in target is %d\n", position - target + 1);
		while(*pattern)
		{
			pattern++;
			printf("%c", *position++);
		}
		printf("\n");
	}else
	{
		printf("%s doesn't contains %s\n", target, pattern);
	}
	return 0;
}

static char* strstr(const char* target, const char* pattern)
{
	assert( target != NULL);
	if(pattern == NULL)
	{
		return (char*)target;
	}
	const char* p1;
	const char* p2;
	const char* pChar = target;
	char* old_p1;
	for(p2 = &pattern[1]; *p2; p2++)
	{
		pChar++;
	}
	for(p1 = target; *pChar; pChar++)
	{
		old_p1 = (char*)p1;
		p2 = pattern;
		while(*p1 == *p2 && *p1 && *p2)
		{
			p2++;
			p1++;
		}
		if(!*p2)
		{
			return old_p1;
		}
		//move to the next positon in target
		p1 = old_p1 + 1;
	}
	return NULL;
}
