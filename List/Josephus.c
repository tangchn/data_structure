//约瑟夫问题

#include <stdio.h>
#include <stdlib.h>

typedef struct list_node{
	int data;
	struct list_node* next;
}LNode,LHead;

void CreatList(LHead** list_head,int n);
void Josephus(LHead** list_head,int n,int m);
void Print(LHead** list_head);

void CreatList(LHead** list_head,int n)
{

    LHead *p;
    LNode *temp;
    p = *list_head;
    int i = 1;
    while(i<=n)
    {
        temp = (LNode*)malloc(sizeof(LNode));
        temp->data = i++;
        p->next = temp;
        p = temp;
    }
    p->next = (*list_head)->next;//最后一个节点指向头一个节点
    printf("链表创建成功\n");
}

void Print(LHead** list_head)
{
    LHead *p;
    p = (*list_head)->next;//首先使其指向第一个节点
    printf("链表数据: \n");
    do
    {
        printf("%-3d",p->data);
        p = p->next;
    }while(p != (*list_head)->next);
    printf("\n");
}

void Josephus(LHead** list_head, int n, int m)
{
    LHead *p,*temp;
    p = *list_head;
    n = n-1;
    while(n--)
    {
        int i = m;
        while(--i)
        {
            p = p->next;
        }
        temp = p->next;//待删除节点
        printf("%d->",temp->data);
        p->next = temp->next;
        free(temp);
    }
    printf("%d\n",p->data);
}

int main(void)
{
    int n =41,m=3;
    LHead *list_head;
    list_head = (LHead*)malloc(sizeof(LHead));
    CreatList(&list_head,n);
    Print(&list_head);

    printf("\n约瑟夫问题（人数 %d 人，序号为 %d 的倍数的人自杀）的解为：\n",n,m);
    Josephus(&list_head,n,m);
}
