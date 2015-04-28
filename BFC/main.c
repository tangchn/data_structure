#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int ElemType;
typedef struct _qElement{
        ElemType data;
        struct _qElement* pre;
        struct _qElement* next;
        int isSearched;
}qElement,*qPtrElement;

typedef struct
{
    qPtrElement front;//指向队首
    qPtrElement rear;//指向队尾
}Queue;

#define VERTEXNUM 10


void createGraph(int (*edge)[VERTEXNUM], int start, int end);
void displayGraph(int (*edge)[VERTEXNUM]);
void InitialQueue(Queue *q);
void InQueue(Queue *q,ElemType e);
void OutQueue(Queue *q,ElemType *e);
void BFSRec(int (*edge)[VERTEXNUM],int i,Queue *q);
void BFS(int (*edge)[VERTEXNUM]);

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

    printf("广度优先遍历的结果为:\n");
    BFS(edge);

    return 0;
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

void BFS(int (*edge)[VERTEXNUM])
{
    int i;
    Queue q;
    InitialQueue(&q);
    for(i = 0; i < VERTEXNUM; i++)
    {
        BFSRec(edge,i,&q);
    }
}

void BFSRec(int (*edge)[VERTEXNUM],int i,Queue *q)
{
    int j;
    InQueue(q,i);//首先进队列
    ElemType temp;
    OutQueue(q,&temp);
    while(temp >= 0)
    {
        if(searchFlag[temp] == 0)
        {
            printf("%d ", temp);
            searchFlag[temp] = 1;
            for(j = 0; j < VERTEXNUM; j++)
            {
                if(edge[temp][j] == 1)
                {
                    InQueue(q,j);
                }
            }
        }
        OutQueue(q,&temp);
    }

}

void InitialQueue(Queue *q)
{
    q->front = q->rear = NULL;
}

void InQueue(Queue *q,ElemType e)
{
    qPtrElement elem  = (qPtrElement)malloc(sizeof(qElement));
    elem->data = e;
    elem->next = NULL;
    elem->pre = NULL;
    if(q->front == NULL || q->rear == NULL)
    {
        q->front = q->rear = elem;
    }else
    {
        q->rear->next = elem;
        elem->pre = q->rear;
        q->rear = elem;
    }
}

void OutQueue(Queue *q,ElemType *e)
{
    if(q->front == NULL || q->rear == NULL)
    {
        *e = -1;
    }else
    {
        qPtrElement elem = q->front;
        *e = elem->data;
        q->front = elem->next;
        if(elem->next == NULL)
        {
            q->rear = q->front;
        }else
        {
            elem->next->pre = NULL;//下个元素的前驱置为零
        }
        free(elem);
        elem = NULL;
    }
}
