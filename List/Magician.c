//魔术师发牌问题
//2015.2.11
#include <stdio.h>
#include <stdlib.h>

typedef struct list_node{
	int data;
	struct list_node* next;
}LNode,LHead;

void CreatList(LHead** list_head,int n);
void Magician(LHead** list_head,int n);
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
        temp->data = 0;
        p->next = temp;
        p = temp;
        i++;
    }
    p->next = (*list_head)->next;//最后一个节点指向头一个节点
    printf("点数模型创建成功\n");
}

void Print(LHead** list_head)
{
    LHead *p;
    p = (*list_head)->next;//首先使其指向第一个节点
    printf("扑克牌点数排列如下: \n");
    while(1)
    {
        if(p->next == (*list_head)->next)//最后一个元素
        {
            printf("%d",p->data);
            break;
        }else
        {
            printf("%d->",p->data);
            p = p->next;
        }
    }
    printf("\n");
}

void Magician(LHead** list_head, int n)
{
    LHead *p;
    p = *list_head;
    int i,temp;

    for(i = 1; i <= n; i++)
    {
        temp = i;
        while(temp)
        {
            p = p->next;
            if(p->data == 0)//如果该位置的牌没有被拿走
            {
                temp--;
            }
        }
        p->data = i;
    }

}

int main(void)
{
    int n =13;
    LHead *list_head;
    list_head = (LHead*)malloc(sizeof(LHead));
    CreatList(&list_head,n);//创建一个13个节点的循环链表
    Print(&list_head);

    Magician(&list_head,n);
    Print(&list_head);

    return 0;
}
