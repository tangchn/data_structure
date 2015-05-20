/*************************************************************************
	> Author: Yves
	> E-mail: tanngye@hotmail.com
	> File Name: test.c
	> Description: ...
	> Created  Time: 2015-05-20. 14:38:39
	> Modified Time: 2015-05-20. 14:38:39
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

static void test(int a);

int main(void)
{
	test(0);
	return 0;
}

static void test(int a)
{
	int b;
	b = ++a;
	printf("This is the %dh recursion.\n",b);
	test(b);
}
