#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define VERTEXNUM 10

void createGraph(int (*edge)[VERTEXNUM], int start, int end);
void displayGraph(int (*edge)[VERTEXNUM]);
void DFSRec(int (*edge)[VERTEXNUM],int i);
void DFS(int (*edge)[VERTEXNUM]);

int* searchFlag;

int main()
{
    /**创建邻接矩阵*/
    int (*edge)[VERTEXNUM] = (int (*)[VERTEXNUM])malloc(sizeof(int)*VERTEXNUM*VERTEXNUM);
    searchFlag = (int*)malloc(sizeof(int)*VERTEXNUM);

    int i,j;
    for(i = 0; i < VERTEXNUM; i++)
    {
        for(j = 0; j < VERTEXNUM; j++)
        {
            edge[i][j] = 0;
        }
        searchFlag[i] = 0;
    }

    printf("原始的矩阵为:\n");
    displayGraph(edge);

    createGraph(edge,0,1);
    createGraph(edge,1,4);
    createGraph(edge,1,5);
    createGraph(edge,2,3);
    createGraph(edge,2,6);
    createGraph(edge,5,2);
    createGraph(edge,6,7);
    createGraph(edge,9,8);
    createGraph(edge,7,4);
    createGraph(edge,8,6);

    printf("初始化后的邻接矩阵为:\n");
    displayGraph(edge);

    printf("\n深度优先遍历的访问顺序为:\n");
    DFS(edge);

}

void createGraph(int (*edge)[VERTEXNUM],int start, int end)
{
    edge[start][end] = 1;
}

void displayGraph(int (*edge)[VERTEXNUM])
{
    int i,j;
    for(i = 0; i < VERTEXNUM; i++)
    {
        for(j = 0; j < VERTEXNUM; j++)
        {
            printf("%d ",edge[i][j]);
        }
        printf("\n");
    }
}

void DFS(int (*edge)[VERTEXNUM])
{
    int i,j,k;

    for(i = 0; i < VERTEXNUM; i++)
    {
        DFSRec(edge,i);
    }
}

//一个递归回溯调用
void DFSRec(int (*edge)[VERTEXNUM],int i)
{
    int j;
    if(searchFlag[i] == 1)
    {
        return;
    }
    printf("%d ",i);
    searchFlag[i] = 1;

    for(j = 0; j < VERTEXNUM; j++)
    {
        if(edge[i][j] == 1)//如果有邻接边切未被访问过
        {
            DFSRec(edge,j);
        }
    }
}

