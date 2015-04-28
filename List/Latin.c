/*************************************************************************
	> File Name: Latin.c
	> Description: 拉丁方阵的C实现
	> Author: Yves
	> Mail: mail: me@itang.me
	> Created Time: 2015-2-11. 09:58:51
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct list_node{
	int data;
	struct list_node* next;
}LNode,LHead;

void CreatList(LHead** list_head,int n);
void Latin(LHead** list_head,int n);
void Print(LHead** list_head,int n,int i);

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

void Print(LHead** list_head,int n ,int i)
{
    LHead *p;
    p = (*list_head)->next;//首先使其指向第一个节点
    while(--i)
    {
        p = p->next;
    }
    while(n--)
    {
        printf("%-5d",p->data);
        p = p->next;
    }
    printf("\n");
}

void Magician(LHead** list_head, int n)
{
    LHead *p;
    p = *list_head;
    int i;

    for(i = 1; i <= n; i++)
    {
        Print(list_head,n,i);
    }
}

int main(void)
{
    int n =15;
    LHead *list_head;
    list_head = (LHead*)malloc(sizeof(LHead));
    CreatList(&list_head,n);//创建一n个节点的循环链表
    //Print(&list_head,n,1);

    Magician(&list_head,n);

    return 0;
}
