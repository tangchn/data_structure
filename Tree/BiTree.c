/*************************************************************************
	> File Name: BiTree.c
	> Description: 二叉树的各种实现
	> Author: Yves
	> E-mail: tangye@hotmail.com
	> Created Time: 2015-2-14. 12:35:51
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct _BiTNode
{
    ElemType data;
    struct _BiTNode* leftChild;
    struct _BiTNode* rightChild;
}BiTNode, *pBiTNode;//指向BiTNode的指针

void CreatBiTree(pBiTNode *p);//创建二叉树
void PreOrderTraverse(pBiTNode p,int level);//前序遍历
void InOrderTraverse(pBiTNode p,int level);//中序遍历
void PostOrderTraverse(pBiTNode p,int level);//后序遍历


int main(void)
{
    pBiTNode root;
    printf("请输入数据:  \n");
    CreatBiTree(&root);
    printf("\n");

    printf("前序遍历结果:  \n");
    PreOrderTraverse(root,1);
    printf("\n");

    printf("中序遍历结果:  \n");
    InOrderTraverse(root,1);
    printf("\n");

    printf("后序遍历结果:  \n");
    PostOrderTraverse(root,1);
    printf("\n");

    return 0;
}

void CreatBiTree(pBiTNode *p)
{
    ElemType c;
    fflush(stdin);
    scanf("%c",&c);
    if(c != '#')
    {
	*p = (BiTNode*)malloc(sizeof(BiTNode));
        (*p)->data = c;
        CreatBiTree(&(*p)->leftChild);
        CreatBiTree(&(*p)->rightChild);
    }else
    {
	*p = NULL;
	return;
    }
}

void PreOrderTraverse(pBiTNode p,int level)
{
    if(p)
    {
        printf("%c 在第 %d 层\n",p->data,level);
        PreOrderTraverse(p->leftChild,level+1);
        PreOrderTraverse(p->rightChild,level+1);
    }
}

void InOrderTraverse(pBiTNode p,int level)
{
    if(p)
    {
        InOrderTraverse(p->leftChild,level+1);
        printf("%c 在第 %d 层\n",p->data,level);
        InOrderTraverse(p->rightChild,level+1);
    }
}

void PostOrderTraverse(pBiTNode p,int level)
{
    if(p)
    {
        PostOrderTraverse(p->leftChild,level+1);
        PostOrderTraverse(p->rightChild,level+1);
        printf("%c 在第 %d 层\n",p->data,level);
    }
}
