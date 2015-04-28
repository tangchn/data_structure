/*************************************************************************
	> File Name: BiLinklist.c
	> Description: 双向链表的C实现
	> Author: Yves
	> Mail: mail: me@tangye.me
	> Created Time: 2015-2-7. 12:40:51
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
//定义链表的节点
typedef struct node{
    ElemType data;
    struct node *next;
    struct node *prev;
}LinkNode, *LinkList;

void InitList(LinkList *l); //初始化双向链表
void CreatList(LinkList *l);//创建双向链表
void InsertList(LinkList *l,int i,ElemType e); //在双向链表的第i个位置插入元素e
void DeleteList(LinkList *l,int i,ElemType *e); //删除单链表的第i个位置的元素,把删除的元素存入*e
int  LocateElem(LinkList *l,ElemType e); //在链表中查找元素e,找到返回位置,未找到返回-1
void GetElem(LinkList *l,int i,ElemType *e); //返回链表中第i个位置的元素,存入*e
void Print(LinkList *l); //打印链表
void Push_front(LinkList *l,ElemType e); //倒序插入元素
void Push_back(LinkList *l,ElemType e); //正序插入元素
void DestroyList(LinkList *l); //清空链表
int GetLen(LinkList *l); //得到链表长度

static LinkList present; //来个指针
int num = 10;

//初始化链表
void InitList(LinkList *l)
{
    *l = (LinkList)malloc(sizeof(LinkNode));
    (*l)->next = NULL;
    (*l)->prev = NULL;
    present = (*l);
}

//创建链表
void CreatList(LinkList *l)
{

    printf("请输入双向链表的数据个数: ");
    ElemType data;
    present = *l;
    scanf("%d",&num);
    while(num--)
    {
        LinkList temp = (LinkList)malloc(sizeof(LinkNode)); //创建新结点
        if(temp) //如果内存分配成功
        {
            temp->data = rand()%100+1;
            temp->next = present->next;
            if(present->next == *l)//如果这是插入的第一个节点
            {
                temp->prev = NULL;
            }else
            {
                temp->prev = present;
            }
            present->next = temp;
            present = present->next;
        }
    }
}

//打印链表
void Print(LinkList *l)
{
    LinkList p = (*l)->next;
    printf("数据：");
    while(p)
    {

        printf("%-5d",p->data);
        p = p->next;
    }
    printf("\n\n");
}

//得到链表长度
int GetLen(LinkList *l)
{
    LinkList p = *l;
    int j = 0;
    while(p)
    {
        p = p->next;
        j++;
    }
    return j-1;
}

//清空链表
void DestroyList(LinkList *l)
{
    while((*l))
    {
        LinkList temp = *l;
        (*l) = (*l)->next;
        free(temp);
    }
}

//返回链表中第i个位置的元素,存入*e
void GetElem(LinkList *l,int i,ElemType *e)
{
    int j = 0;
    LinkList p;
    p = *l;
    for(j = 0; j < i; j++)
    {
        p = p->next;
    }
    *e = p->data;
}

//返回链表中元素e的位置
int LocateElem(LinkList *l,ElemType e)
{
    LinkList p;
    int j = 0;
    p = *l;
    while(p)
    {
        if(p->data == e)
        {
           return j;
        }
        ++j;
        p = p->next;
    }
    return -1;
}

//在双向链表的第i个位置插入元素e
void InsertList(LinkList *l,int i,ElemType e)
{
    int j = 0;
    LinkList p,temp;
    temp = (LinkList)malloc(sizeof(LinkNode)); //创建新结点
    p = *l;
    //使p指向插入元素前一个元素
    while(p && j < i-1)
    {
        ++j;
        p = p->next;
    }

    temp->data = e;
    temp->next = p->next;
    temp->prev = p;
    p->next->prev = temp;
    p->next = temp;
}

//删除双链表的第i个位置的元素,把删除的元素存入*e
void DeleteList(LinkList *l,int i,ElemType *e)
{
    int j = 0;
    LinkList temp ,p;
    p = *l;

    while(p && j < i - 1) //移动到要删除的结点的前一个结点
    {
        p = p->next;
        ++j;
    }
    temp = p->next;
    *e = temp->data;
    p->next = temp->next;
    temp->next->prev = p;
    free(temp);
}


int main(void)
{
    LinkList l;
    ElemType e;
    int i;
    InitList(&l);
    printf("初始化链表成功......\n");

    CreatList(&l);
    printf("链表创建成功......\n");
    printf("链表的元素为:\n");
    Print(&l);

    printf("将元素88插入到链表的第4个位置\n");
    e = 88;
    InsertList(&l,4,e);
    printf("元素插入成功......链表长度为 %d \n",GetLen(&l));
    Print(&l);

    printf("将链表中第6个位置上的元素删除\n");
    DeleteList(&l,6,&e);
    printf("元素删除成功......链表长度为 %d \n",GetLen(&l));
    Print(&l);

    printf("元素32在链表中的位置为%d\n",LocateElem(&l,32));

    GetElem(&l,6,&e);
    printf("链表中第6位的数据为%d\n",e);

    DestroyList(&l);
    printf("链表销毁成功......\n");
    return 0;
}

