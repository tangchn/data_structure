/*************************************************************************
	> File Name: hanoi.c
	> Author: Yves
	> E-mail: ty@msn.cn
	> Created Time: 2015-05-16. 10:09:23
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

static int times;

static void hanoi(int n, char from, char to, char temp);

int main(void)
{
	int level;
	printf("Plese set the level of the hanoi tower: ");
	scanf("%d", &level);
	hanoi(level, 'A', 'B', 'C');
	printf("The total times is %d\n", times);
}

static void hanoi(int n, char from, char to, char temp)
{
	if(n == 1)
	{
		times++;
		printf("Move %d from %c to %c\n", n, from, to);
		return;
	}
	hanoi(n - 1, from, temp, to);
	times++;
	printf("Move %d from %c to %c\n", n, from, to);
	hanoi(n - 1, temp, to, from);
}
