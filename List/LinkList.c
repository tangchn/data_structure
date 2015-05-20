/*************************************************************************
	> File Name: Linklist.c
	> Description: 单链表的C实现
	> Author: Yves
	> E-mail: tangye@hotmail.com
	> Created Time: 2015-2-7. 09:50:51
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
//定义链表的节点
typedef struct node{
    ElemType data;
    struct node *next;
}LinkNode, *LinkList;

void InitList(LinkList *l); //初始化单链表
void InsertList(LinkList *l,int i,ElemType e); //在单链表的第i个位置插入元素e
void DeleteList(LinkList *l,int i,ElemType *e); //删除单链表的第i个位置的元素,把删除的元素存入*e
int  LocateElem(LinkList *l,ElemType e); //在链表中查找元素e,找到返回位置,未找到返回-1
void GetElem(LinkList *l,int i,ElemType *e); //返回链表中第i个位置的元素,存入*e
void Print(LinkList *l); //打印链表
void Push_front(LinkList *l,ElemType e); //倒序插入元素
void Push_back(LinkList *l,ElemType e); //正序插入元素
void DestroyList(LinkList *l); //清空链表
void GetMidNode(LinkList *l,ElemType *e);//查找中间节点

static LinkList rear; //来个尾指针


//初始化链表
void InitList(LinkList *l)
{
    *l = (LinkList)malloc(sizeof(LinkNode));
    (*l)->next = NULL;
    rear = (*l);
}

//打印链表
void Print(LinkList *l)
{
    LinkList p = (*l)->next;
    while(p)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

//倒序插入元素
void Push_front(LinkList *l,ElemType e)
{
    LinkList temp =   (LinkList)malloc(sizeof(LinkNode));
    temp->next = (*l)->next;
    temp->data = e;
    (*l)->next = temp;
}

//正序插入元素
void Push_back(LinkList *l,ElemType e)
{
    LinkList temp = (LinkList)malloc(sizeof(LinkNode)); //创建新结点
    temp->data = e;
    temp->next = rear->next;//rear->next 实际上为NULL
    rear->next = temp;
    rear = temp; //使rear一直指向最后一个结点
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

int LocateElem(LinkList *l,ElemType e)
{
    LinkList p;
    /*p = *l;
    while(p)
    {
        if(p->data == e)
        {
            return 1;
        }
        p = p->next;
    }
    return 0;*/
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

//在单链表的第i个位置插入元素e
void InsertList(LinkList *l,int i,ElemType e)
{
    int j = 0;
    LinkList p1 ,p2,temp;
    temp = (LinkList)malloc(sizeof(LinkNode)); //创建新结点
    p1 = *l;
    for(j = 0; j <= i-1; j++)
    {
        p2 = p1;
        p1 = p1->next;
    }
    temp->data = e;
    temp->next = p2->next;
    p2->next = temp;
}

//删除单链表的第i个位置的元素,把删除的元素存入*e
void DeleteList(LinkList *l,int i,ElemType *e)
{
    int j = 0;
    LinkList p1 ,p2;
    p1 = *l;

    for(j = 0; j <= i-1; j++)
    {
        p2 = p1;
        p1 = p1->next;
    }
    p2->next = p1->next;
    *e = p1->data;
    free(p1);

    /*LinkList p = l->next;
    int j = 1;
    while(p && j < i - 1) //移动到要删除的结点的前一个结点
    {
        p = p->next;
        ++j;
    }
    if(p) //如果p不为NULL进行删除
    {
        LinkList temp = p->next; //使temp指向要删除结点
        p->next = temp->next; //使p->next指向要删除的结点的下一个结点
        *e = temp->data;
        free(temp); //删除结点
    }*/

}

//获取中间节点
void GetMidNode(LinkList *l,ElemType *e)
{
    LinkList quick,slow;
    quick = slow = (*l)->next;
    while(quick->next)
    {
        if(quick->next->next)
        {
            quick = quick->next->next;
            slow = slow->next;
        }else
        {
            //终点
            quick = quick->next;
        }
    }
    *e = slow->data;
}


/*
void InitList(LinkList *l) //初始化链表
{
    (*l) = (LinkList)malloc(sizeof(LinkNode)); //初始化l指向表头结点
    (*l)->next = NULL; //初始化表头结点的指针为NULL
}
void InsertList(LinkList l,int i,ElemType e) //在链表的第i个位置插入元素e
{
    LinkList p = l->next; //初始化p指向第一个结点
    int j = 1;
    while(p && j < i - 1) //使p成为要插入位置的前一个结点
    {
        p = p->next;
        ++j;
    }
    if(!p)
    {
        printf("超出范围插入失败\n");
        return;
    }
    else
    {
        LinkList temp = (LinkList)malloc(sizeof(LinkNode)); //分配一个新结点
        temp->data = e; //将要插入的元素赋值给新结点的数据域
        temp->next = p->next; //使新结点的指针域指向p的指针域所指向的位置
        p->next = temp; //使p的指针域指向新结点
    }
}
void DeleteList(LinkList l,int i,ElemType *e) //删除第i个位置的结点,将结点的数据赋值给*e
{
    LinkList p = l->next;
    int j = 1;
    while(p && j < i - 1) //移动到要删除的结点的前一个结点
    {
        p = p->next;
        ++j;
    }
    if(p) //如果p不为NULL进行删除
    {
        LinkList temp = p->next; //使temp指向要删除结点
        p->next = temp->next; //使p->next指向要删除的结点的下一个结点
        *e = temp->data;
        free(temp); //删除结点
    }
}
void GetElem(LinkList l,int i,ElemType *e) //将第i个元素的位置存入*e
{
    LinkList temp = l->next;
    int j = 1;
    while(temp && j < i)
    {
        temp = temp->next;
        ++j;
    }
    if(temp)
        *e = temp->data;
    else
        *e = INFINITY; //β值表示无穷大
}
int LocateElem(LinkList l,ElemType e) //在链表内查找元素e，如果找到返回所在位置,未找到返回-1
{
    int i = 0;
    LinkList p = l->next;
    while(p) //遍历链表
    {
        ++i;
        if(p->data == e) //如果找到返回所在的位置
            return i;
        p = p->next;
    }
    return -1; //否则返回-1;
}*/


int main(void)
{
    LinkList l;
    ElemType e;
    int i;
    InitList(&l);
    printf("初始化链表成功......\n");
    for(int i = 1;i < 12;i += 2)
    {
        Push_back(&l,i);
    }
    printf("链表创建成功......\n");
    printf("链表的元素为:\n");
    Print(&l);

    printf("--------------------------");
    //查找元素
    GetElem(&l,3,&e);
    printf("\n链表中的第3个元素为: %d\n",e);

    printf("--------------------------");
    //检测元素
    //printf("请输入待检测元素：\n");
    //scanf("%d",&e);
    e = 15;
    i = LocateElem(&l,e);
    if(i > 0)
    {
        printf("\n元素 %d 存在于链表中第 %d 个位置上\n",e,i);
    }else
    {
        printf("\n元素 %d 不存在于链表中\n",e);
    }

    printf("--------------------------");
    //插入节点
    printf("\n在第4个位置后插入元素55：\n");
    InsertList(&l,4,55);
    printf("插入成功...\n");
    printf("现在链表的元素为:\n");
    Print(&l);

    printf("--------------------------");
    //删除节点
    printf("\n删除第7个位置上的元素：\n");
    DeleteList(&l,7,&e);
    printf("删除成功...被删除的元素是 %d\n",e);
    printf("现在链表的元素为:\n");
    Print(&l);

    printf("--------------------------");
    //获取中间节点
    GetMidNode(&l,&e);
    printf("\n获取成功...中间节点元素是 %d\n",e);

    printf("--------------------------");
    DestroyList(&l);
    printf("\n链表删除成功......\n");

    return 0;
}

