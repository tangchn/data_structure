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
static void ConvertOthersToDecimal(char* num, const int radix, myStack* s);

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

static void ConvertOthersToDecimal(char* num, const int radix, myStack* s)
{
	s->top = s->base;
	int result;
	ElemType tempElem;
	char tempChar
	size_t i;
	if(radix == 16 || radix == 8)
	{
		i = 0;
		if(radix == 16)
		{
			if(num[0] == '0' && (num[1] == 'x' || num[1] == 'X')
			{
				i = 2;
			}
		}
		for(; num[i] != 0; i++)
		{
			tempChar = num[i];
			if(tempChar >= 'A' && tempChar <= "F")
			{
				tempElem = tempChar - 'A' + 10;
			}else if(tempChar >= 'a' && tempChar <= "f")
			{
				tempElem = tempChar - 'a' + 10;
			}else
			{
				tempElem = tempChar - '0';
			}
			Push(s, temp);
		}
		result = 0;
		while(s->top != s->base)
		{
			Pop(s, &tempElem);
			reulst = result * 10 + tempElem;
		}
		printf("The result of the converison is: %d", result);
	}else{
		printf("Radix is wrong.")
	}
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
   printf("Stack is cleared.\n");
   return; 
}

int main(void)
{
    myStack s;
    InitialStack(&s);
    ElemType e;
    int n, radix;
    printf("----------Testing the function that converts decimal number to others----------\n");
    printf("Please input the decimal number to be convert: ");
    scanf("%d",&n);
    printf("Please input the radix used in this conversion: ");
    scanf("%d",&radix);
    ConvertDecimalToOthers(n, radix, &s);
    printf("\n");
   
    char num[STACK_SIZE];
    printf("----------Testing the function that converts others number to decimal----------\n");
    printf("Please input the number to be convert: ");
    scanf("%s",num);
    printf("Please input the radix used in this conversion: ");
    scanf("%d",&radix);
    ConvertOthersToDecimal(num, radix, &s);
    printf("\n");
    return 0;
}
