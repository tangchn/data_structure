//递归实现输入字符串的逆向输出

#include <stdio.h>
#include <stdlib.h>

void rec();

int main(void)
{
    printf("请输入：\n");
    rec();

    return 0;
}

void rec()
{
    char c;
    scanf("%c",&c);
    if(c != '#')
    {
        rec();
    }
    if(c != '#')//这里比较重要，返回后就执行这一步
    {
        printf("%c",c);
    }
}
