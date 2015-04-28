/*************************************************************************
	> File Name: MST-Prim.c
	> Description: Prim算法实现最小生成树
	> Author: Yves
	> Mail: mail: me@tangye.me
	> Created Time: 2015-2-21. 10:28:51
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define VERTEXNUM 6
#define MAXVALUE 10000

int prim();
void createGraph(int (*edge)[VERTEXNUM],int start, int end, int weight);
void displayGraph(int (*edge)[VERTEXNUM]);
void getPostion(int (*edge)[VERTEXNUM],int value, int x, int* y);

int main(void)
{
    int (*edge)[VERTEXNUM] = (int (*)[VERTEXNUM])malloc(sizeof(int)*VERTEXNUM*VERTEXNUM);
      int i,j;
    for(i = 0; i < VERTEXNUM; i++)
    {
        for(j = 0; j < VERTEXNUM; j++)
        {
            edge[i][j] = MAXVALUE;
        }
    }

    printf("原始的矩阵为:\n");
    displayGraph(edge);

    createGraph(edge,1,3,2);
    createGraph(edge,1,2,4);
    createGraph(edge,1,4,3);

    createGraph(edge,2,3,5);
    createGraph(edge,2,5,3);
    createGraph(edge,2,4,4);
    createGraph(edge,2,1,4);

    createGraph(edge,3,6,4);
    createGraph(edge,3,2,5);
    createGraph(edge,3,1,2);
    createGraph(edge,3,4,1);

    createGraph(edge,4,1,3);
    createGraph(edge,4,2,4);
    createGraph(edge,4,6,2);
    createGraph(edge,4,3,1);
    createGraph(edge,4,5,6);

    createGraph(edge,5,6,4);
    createGraph(edge,5,2,3);
    createGraph(edge,5,4,6);

    createGraph(edge,6,3,4);
    createGraph(edge,6,4,2);
    createGraph(edge,6,5,4);

    printf("初始化后的邻接矩阵为:\n");
    displayGraph(edge);

    printf("最小生成树的权值为：%d\n",prim());

    return 0;
}

void createGraph(int (*edge)[VERTEXNUM],int start, int end, int weight)
{
    edge[start-1][end-1] = weight;
}

void displayGraph(int (*edge)[VERTEXNUM])
{
    int i,j;
    for(i = 0; i < VERTEXNUM; i++)
    {
        for(j = 0; j < VERTEXNUM; j++)
        {
            printf("%-8d ",edge[i][j]);
        }
        printf("\n");
    }
}

int prim(int (*edge)[VERTEXNUM])
{
    printf("\n\n访问节点及其权值为:\n");
    int result,i,j,k,min,pos;
    int x1,y1;
    int visited[VERTEXNUM];
    int low[VERTEXNUM];

    result = 0;
    pos = 0;

    for(i = 0; i < VERTEXNUM; i++)
    {

        if(pos == i)
        {
            low[i] = 0;
        }else
        {
            low[i] = edge[pos][i];
        }
        visited[i] = 0;
    }
    visited[0] = 1;

    for(j = 0; j < VERTEXNUM; j++)
    {
        min = MAXVALUE;
        for(k = 0; k < VERTEXNUM; k++)
        {
            if(j != k && visited[k] == 0 && low[k] < min)
            {
                min = low[k];
                pos = k;
            }
        }
        if(min < MAXVALUE)
        {
            x1 = pos;
            y1 =0;
            getPostion(edge,min,x1,&y1);
            printf("%c -> %c: %d\n",y1 + 'A',x1 + 'A',min);

            //权值相加
            result += min;
            visited[pos] = 1;
            //更新low[]数组
            for(i = 0; i < VERTEXNUM; i++)
            {
                if(visited[i] == 0 && low[i] > edge[pos][i] && edge[pos][i] > 0)
                low[i] = edge[pos][i];
            }
            //将此时获得的节点信息保存
        }
    }
    return result;
}

void getPostion(int (*edge)[VERTEXNUM],int value,int x, int* y)
{
    int i;
    for(i = 0; i < VERTEXNUM; i++)
    {
        if(edge[x][i] == value)
        {
            *y = i;
            break;
        }
    }
}
