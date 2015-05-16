/*************************************************************************
	> File Name: BiThreadTree.c
	> Description: 线索二叉树的实现
	> Author: Yves
	> Mail: mail: ty@msn.cn
	> Created Time: 2015-2-14. 16:35:51
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef enum
{
    Link,  //表示孩子指针
    Thread //表示线索
}Pointer_flag;

typedef struct _BiTNode
{
    ElemType data;
    struct _BiTNode* leftChild;
    Pointer_flag lTag;
    struct _BiTNode* rightChild;
    Pointer_flag rTag;
}BiTNode, *pBiTNode;//指向BiTNode的指针

void CreatBiTree(pBiTNode *p);//创建二叉树
void InOrderTraverse(pBiTNode p);//中序遍历
void Threading(pBiTNode p);//中序线索化
void SetFrontPoint(pBiTNode *head, pBiTNode p);//线索化整个树，得到头节点

pBiTNode pre;

int main(void)
{
    pBiTNode root,head;
    printf("请输入数据:  ");
    CreatBiTree(&root);

    SetFrontPoint(&head,root);
    printf("\n");

    printf("中序遍历结果:  \n");
    InOrderTraverse(head);
    printf("\n");

    return 0;
}

void CreatBiTree(pBiTNode *p)
{
    ElemType c;
    scanf("%c",&c);
    if(c == '#')
    {
        *p = NULL;
    }else
    {
        *p = (BiTNode*)malloc(sizeof(BiTNode));
        (*p)->data = c;
        (*p)->lTag = Link;
        (*p)->rTag = Link;
        CreatBiTree(&(*p)->leftChild);
        CreatBiTree(&(*p)->rightChild);
    }
}


void InOrderTraverse(pBiTNode p)
{
    pBiTNode temp;
    char c;
    temp = p->leftChild;//指向根节点
    while(temp != p)
    {
        //遍历到中序遍历的第一个节点
        while(temp->lTag == Link)
        {
            temp = temp->leftChild;
        }
        c = temp->data;
        printf("%c",temp->data);
        while(temp->rTag == Thread && temp->rightChild != p)
        {
            temp = temp->rightChild;
            printf("%c",temp->data);
            c = temp->data;
        }
        temp = temp->rightChild; //p进入其右子树
    }
}


void Threading(pBiTNode p)
{
    if(p)
    {
        Threading(p->leftChild);
        if(!p->leftChild)
        {
            p->lTag = Thread;
            p->leftChild = pre;//如果左孩子为空，则将域指针置为前驱
        }
        if(!pre->rightChild)
        {
            pre->rTag = Thread;
            pre->rightChild = p;
        }
        pre = p;
        Threading(p->rightChild);
    }
}

void SetFrontPoint(pBiTNode *head, pBiTNode p)
{
    /*(*head) = (pBiTNode)malloc(sizeof(BiTNode));

    (*head)->rTag = Link;
    (*head)->rightChild = (*head);

    if(!p)
    {
        (*head)->lTag = Link;
        (*head)->leftChild = (*head);
    }else
    {

        (*head)->leftChild = p;
        (*head)->lTag = Link;
        pre = *head;
        Threading(p);

        pre->rTag = Thread;
        pre->rightChild = *head; //最后一个节点指向头节点

        (*head)->rightChild = pre; //头节点右孩子指向最后一个节点
    }*/


    (*head) = (pBiTNode)malloc(sizeof(BiTNode));
    (*head)->rightChild = *head;
    (*head)->rTag = Thread;

    if(!p)      //如果为NULL
    {
        (*head)->leftChild = *head;
        (*head)->lTag = Link;
    }
    else
    {
        pre = *head;
        (*head)->leftChild = p;        //第一步
        (*head)->lTag = Link;
        Threading(p);         //找到最后一个结点
        pre->rightChild = *head;        //第四步
        pre->rTag = Thread;
        (*head)->rightChild = pre;      //第二步
    }
}

