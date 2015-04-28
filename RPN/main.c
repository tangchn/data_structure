/*************************************************************************
	> File Name: main.c
	> Description: 简单逆波兰计算器的实现，目前只能做到整型加减乘除，不能完成浮点数和小数的运算
	> Author: Yves
	> Mail: mail: me@tangye.me
	> Created Time: 2015-2-12. 00:03:51
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define ERROR -1
#define STACKSIZE 100
#define STACKINCREMENT 10
#define BUFFERSIZE 100  //定义临时缓冲区大小

typedef int Status; //定义返回状态
typedef char ElemType;

typedef struct  //定义堆栈
{
    ElemType* base;//应该定义为void的更灵活
    ElemType* top;
    int stackSize;
}myStack;

Status InitStack(myStack *s); //初始化栈
Status Push(myStack *s,ElemType e); //入栈
Status Pop(myStack *s,ElemType *e); //出栈
Status ClearStack(myStack *s); //清空栈内所有元素
Status DestroyStack(myStack *s); //销毁栈
int GetStackLen(myStack *s); //获取已入栈元素个数
Status CalculatePostfix(char *arr,double *result); //计算表达式结果：参数一：arr为使用空格分隔的采用后缀表达式表示的要计算的字符串,例：arr={"3 5 + "}。参数二：result存放计算结果。
Status InfixToPostfix(char *infix,char *postfix); //将中缀表达式转换为后缀表达式。例：infix={"3+5\n"} ,转换后，postfix={"3 5 + "};
Status my_err(char *str); //自定义错误处理函数
int GetPriority(ElemType c);
Status GetTopElement(myStack *s,ElemType *e);
Status IsEmpty(myStack *s);


int main(int argc,char *argv[])
{
    printf("请输入中缀表达式：\n"); //输入中缀表达式。
    char src[BUFFERSIZE]={'\0'}; //存放中缀表达式的临时缓冲区
    char *infix=src;
    char postfix[BUFFERSIZE]={'\0'}; //存放后缀表达式的临时缓冲区
    fgets(infix,BUFFERSIZE,stdin); //从标准输入流中读取要计算的四则运算表达式
    printf("中缀表达式为：%s",infix);
    InfixToPostfix(infix,postfix); //将中缀转换为后缀表达式
    printf("后缀表达式为：%s\n",postfix);
    double result;
    CalculatePostfix(postfix,&result); //计算后缀表达式的结果
    printf("计算结果为：%f\n",result);

    return 0;
}


Status InitStack(myStack* s)
{
    s->base = (ElemType*)malloc(STACKSIZE*sizeof(ElemType));
    if(!s->base)
    {
        return ERROR;
    }
    s->top = s->base;
    s->stackSize = STACKSIZE;
    return TRUE;
}

Status Push(myStack* s,ElemType e)
{
    if(s->top - s->base >= s->stackSize)//注意此处指针的加减运算
    {
        s->base = (ElemType*)realloc(s->base,s->stackSize + STACKINCREMENT);
        if(!s->base)
        {
            return ERROR;
        }
        s->stackSize = s->stackSize + STACKINCREMENT;//改变栈的大小
    }
    *(s->top) = e;
    s->top++;
    return TRUE;
}

Status Pop(myStack* s,ElemType *e)
{
    if(s->top == s->base)
    {
        return FALSE;
    }
    (s->top)--;
    *e= *(s->top);
     return TRUE;
}


int GetStackLen(myStack *s)
{
    return s->top - s->base;
}

Status GetTopElement(myStack *s,ElemType *e)
{
    *e = *(s->top - 1);
    return TRUE;
}

Status IsEmpty(myStack *s)
{
    if(s->base == s->top)
    {
        return TRUE;
    }else if(s->base < s->top)
    {
        return FALSE;
    }else
    {
        return ERROR;
    }
}

Status ClearStack(myStack *s)
{

    return TRUE;
}

Status DestroyStack(myStack *s)
{
    free(s->base);
    return TRUE;
}


Status my_err(char *str)
{
  perror(str);
  exit(1);
}


/*
*将中缀表达式转换为后缀表达式
*/
Status InfixToPostfix(char *infix,char *postfix)
{
    myStack s;
    ElemType c,temp;
    //int index=0,len,i=0,sum=0;
    InitStack(&s);

    do
    {
        c = *(infix++);
        if(c >= '0'&& c<= '9' )//如果是数字
        {
            *(postfix++) = c;
        }else
        {
            if((c == '(') || (c == '[') || (c == '{'))
            {
                Push(&s,c);
            }else if((c == ')') || (c == ']') || (c == '}'))
            {

                while(1)
                {
                    Pop(&s,&temp);
                    if(IsEmpty(&s) || (temp == '('))
                    {
                        break;
                    }
                    *(postfix++) = temp;
                }
            }
            else if((c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '%') || (c == '^'))
            {
                while(1)
                {
                    if(IsEmpty(&s))
                    {
                        Push(&s,c);
                        break;
                    }else
                    {
                        GetTopElement(&s,&temp);
                        if(GetPriority(temp) >= GetPriority(c))
                        {
                            Pop(&s,&temp);
                            *(postfix++) = temp;
                        }else
                        {
                            Push(&s,c);
                            break;
                        }
                    }
                }

            }else
            {
                printf("%c为非法输入!\n",c);
            }
        }
    }while( *infix != '\n');
    //将剩下的输出
    while(!IsEmpty(&s))
    {
        Pop(&s,&c);
        *(postfix++) = c;
    }
    DestroyStack(&s);
    return TRUE;
}

int GetPriority(ElemType c)
{
    switch(c){
    case '[':
    case ']':
    case '{':
    case '}':
    case '(':
    case ')':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return ERROR;
}

/*
*计算后缀表达式的值
*/
Status CalculatePostfix(char *arr,double *result)
{
    myStack s;
    ElemType c,temp;
    double top1,top2;
    InitStack(&s);
    c = *arr;
    do
    {
        if(c >= '0'&& c<= '9' )//如果是数字直接入栈
        {
            Push(&s,c);
        }else
        {
            switch(c)
            {
            case '+':
                Pop(&s,&temp);
                top1 = (double)(temp - '0');
                Pop(&s,&temp);
                top2 = (double)(temp - '0');
                temp = top1 + top2 + '0';
                Push(&s,temp);
                break;
            case '-':
                Pop(&s,&temp);
                top1 = (double)(temp - '0');
                Pop(&s,&temp);
                top2 = (double)(temp - '0');
                temp = top2 - top1 + '0';
                Push(&s,temp);
                break;
            case '*':
                Pop(&s,&temp);
                top1 = (double)(temp - '0');
                Pop(&s,&temp);
                top2 = (double)(temp - '0');
                temp = top1 * top2 + '0';
                Push(&s,temp);
                break;
            case '/':
                Pop(&s,&temp);
                top1 = (double)(temp - '0');
                Pop(&s,&temp);
                top2 = (double)(temp - '0');
                if(top1 != 0)
                {
                    temp = top2 / top1 + '0';
                    Push(&s,temp);
                }else
                {
                    return ERROR;
                }

                break;
            default:
                break;
            }
        }
        c = *(++arr);

    }while(c != '\000');
    Pop(&s,&c);
    *result = (double)(temp - '0');
    return TRUE;
}
