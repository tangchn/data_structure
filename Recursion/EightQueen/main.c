/*************************************************************************
	> File Name: EightQueen.c
	> Description: 八皇后问题
	> Author: Yves
	> Mail: mail: me@tangye.me
	> Created Time: 2015-2-13. 13:40:51
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define SAFE 1
#define UNSAFE 0
#define ERROR -1
typedef int Status; //定义返回状态

static char Queen[8][8];
static int a[8];
static int b[15];
static int c[15];
static int iQueenNum=0;  //记录总的棋盘状态数

void EightQueen(int iLine);

int main(void)
{
    int iLine,iColumn;

    /*棋盘初始化，空格为*，放置皇后的地方为@*/
    for(iLine=0; iLine<8; iLine++)
    {
        a[iLine]=0;      //列标记初始化，表示无列冲突
        for(iColumn=0; iColumn<8; iColumn++)
        {
            Queen[iLine][iColumn]='-';
        }
    }
    /*主、从对角线标记初始化，表示没有冲突*/
    for(iLine=0; iLine<15; iLine++)
    {
        b[iLine]=c[iLine]=0;
    }

    EightQueen(0);

    return 0;
}

void EightQueen(int iLine)
{
    int iColumn;
    for(iColumn = 0; iColumn < 8; iColumn++)
    {
        if((a[iColumn] ==0) && (b[iLine - iColumn + 7] == 0) && (c[iLine + iColumn] ==0))
        {
            Queen[iLine][iColumn]='@';
            a[iColumn] = 1;
            b[iLine - iColumn + 7] = 1;
            c[iLine + iColumn] = 1;
            if(iLine < 7)
            {
                EightQueen(iLine + 1);//迭代下一行
            }else
            {
                //输出
                int i,j;
                ++iQueenNum;
                if(iQueenNum < 10)
                {
                    printf("第%d种状态为：\n",iQueenNum);
                    for(i=0; i<8; i++)
                    {
                    for(j=0; j<8; j++)
                    {
                        printf("%c  ",Queen[i][j]);
                    }
                    printf("\n");
                    }
                    printf("\n\n");
                }


            }
            //如果不满足的话，则回溯
            //原因是所在iLine + 1尝试了所有的iColumn（0~7）后,均未打印出来，则参数出栈,说明该（iLine，iColumn）位置不能放置皇后
            //需要将其置为安全，并且尝试（iLine，iColumn + 1）
            //除了回溯，还具有回复Queen矩阵的功能
            Queen[iLine][iColumn]='-';
            a[iColumn] = 0;
            b[iLine - iColumn + 7] = 0;
            c[iLine + iColumn] = 0;
        }
    }
}
