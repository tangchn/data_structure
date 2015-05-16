/*************************************************************************
	> File Name: HexConversion.c
	> Description: 利用栈将数字在不同的进制之间进行转换
	> Author: Yves
	> Mail: mail: ty@msn.cn
	> Created Time: 2015-2-11. 10:36:51
	> Modifid TIme: 2015-5-16
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#const int STACKSIZE 100
#const int STACKINCREMENT 10

typedef char ElemType;

typedef struct
{
    ElemType data;
    ElemType* base;
    ElemType* top;
    int stackSize;
}myStack;

static void Push(myStack* s,ElemType e);
static void InitStack(myStack* s);
static void Pop(myStack* s,ElemType *e);
static int GetStackLen(myStack *s);
static 

int main(void)
{

    myStack s;
    ElemType e;
    int index,len,temp,sum=0;

    InitStack(&s);
    printf("请输入需要转换的二进制数据：\n");
    scanf("%c",&e);
    /*while(scanf("%c",&e) != EOF)
    {
        Push(&s,e);
    }*/
    while(e != '!')
    {
        Push(&s,e);
        scanf("%c",&e);
    }
    getchar();//做到清空缓冲区的效果
    len = GetStackLen(&s);
    printf("此时栈的大小为：%d\n",len);
    char binArray[len];

    for(int i = 0; i < len; i++)
    {
        Pop(&s,&e);
        binArray[len-1-i] = e;
        temp = (int)(e - '0');
        //printf("%d\n",temp);
        index = i;
        while(index--)
        {
            temp = 2*temp;
        }
        sum = temp + sum;
    }
    printf("%s转换后的十进制数据为：%d\n",binArray,sum);
    return 0;
}

void InitStack(myStack* s)
{
    s->base = (ElemType*)malloc(STACKSIZE*sizeof(ElemType));
    if(!s->base)
    {
        exit(0);
    }
    s->top = s->base;
    s->stackSize = STACKSIZE;
}

void Push(myStack* s,ElemType e)
{
    if(s->top - s->base >= s->stackSize)//注意此处指针的加减运算
    {
        s->base = (ElemType*)realloc(s->base,s->stackSize + STACKINCREMENT);
        if(!s->base)
        {
            exit(0);
        }
        s->stackSize = s->stackSize + STACKINCREMENT;//改变栈的大小
    }
    *(s->top) = e;
    s->top++;
}

void Pop(myStack* s,ElemType *e)
{
    if(s->top == s->base)
    {
        return;
    }
    (s->top)--;
    *e= *(s->top);
}

int GetStackLen(myStack *s)
{
    return s->top - s->base;
}

