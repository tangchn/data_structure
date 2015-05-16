
#include <stdio.h>
#include <stdlib.h>

int fib(int i);
int a[11] = {0};

int main(void)
{
    int i = 10;
    fib(10);
}

int fib(int i)
{
    int temp;

    if(i < 2)
    {
        temp = (i == 0)?0:1;
    }else
    {
        temp = fib(i-2) + fib(i-1);//顺序决定了其输出的次序
        //printf("%-5d",temp);
    }
    if(a[i] == 0)//注意！！！！！！！！！！！！！1
    {
        a[i] = 1;
        printf("%-5d",temp);
    }
    return temp;
}
