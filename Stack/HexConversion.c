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

const int STACK_SIZE = 100;
const int STACK_SIZE_INCREMENT = 10;

typedef int ElemType;

typedef struct
{
    ElemType data;
    ElemType* base;
    ElemType* top;
    int stackSize;
}myStack;

static void Push(myStack* s,ElemType e);
static void InitialStack(myStack* s);
static void Pop(myStack* s,ElemType *e);
static void ClearStack(myStack* s);
static int GetStackLen(myStack* s);
static void ConvertDecimalToOthers(int n, const int radix, myStack* s);
static void ConvertOthersToDecimal(int n, const int radix, myStack* s);

static void ConvertDecimalToOthers(int n, const int radix, myStack* s)
{
	//clear the data in the stack
	s->top = s->base;
	ElemType temp;
	while(n != 0)
	{
		temp = (ElemType)n % radix;
		Push(s, temp);
		n /= radix;
	}
	printf("The result of the converison is: ")
	while(s->top != s->base)
	{
		Pop(s, &temp);
		printf("%d",(int)temp);
	}
	printf("\n");
}


int main(void)
{
    myStack s;
    InitialStack(&s);
    ElemType e;
    int n, radix;
    printf("----------Testing the function that converts decimal number to others----------\n");
    printf("Please input the decimal number to be convert：");
    scanf("%d",&n);
    printf("Please input the radix used in this conversion：");
    scanf("%d",&radix);
    ConvertDecimalToOthers(n, radix, &s);
    printf("\n");
   
    /*while(e != '!')
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
    printf("%s转换后的十进制数据为：%d\n",binArray,sum);*/
    
    return 0;
}

static void InitialStack(myStack* s)
{
    /*Here I exploit the heap to implement the stack,so the address of s->top is high
    * and s->base is low. In the actual stack, it is opposed to the above-mentioned.
    */
    s->base = (ElemType*)malloc(STACK_SIZE*sizeof(ElemType));
    if(!s->base)
    {
        exit(0);
    }
    s->top = s->base;
    s->stackSize = STACK_SIZE;
}

static void InitStack(myStack* s)
{
    s->top = s->base;
    s->stackSize = STACK_SIZE;
}

static void Push(myStack* s,ElemType e)
{
    if(s->top - s->base >= s->stackSize)//注意此处指针的加减运算
    {
        s->base = (ElemType*)realloc(s->base,s->stackSize + STACK_SIZE_INCREMENT);
        if(!s->base)
        {
            exit(0);
        }
        s->stackSize = s->stackSize + STACK_SIZE_INCREMENT;//改变栈的大小
    }
    *(s->top) = e;
    s->top++;
}

static void Pop(myStack* s,ElemType *e)
{
    if(s->top == s->base)
    {
        return;
    }
    (s->top)--;
    *e= *(s->top);
}

static void ClearStack(myStack *s)
{
   free(s->base);
   printf("Stack is cleared\n");
   return; 
}

