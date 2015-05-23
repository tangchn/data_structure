/*************************************************************************
	> Author: Yves
	> E-mail: tangye@hotmail.com
	> File Name: BiThreadTreeNew.cpp
	> Description: ...
	> Created  Time: 2015-05-20. 10:20:53
	> Modified Time: 2015-05-23. 21:56:53
 ************************************************************************/

#include<stack>
#include<cstdlib>
#include<stdio.h>
#include<iostream>
using namespace std;

typedef char ElemType;
typedef enum {Link, Thread} ThrFlag;
typedef struct tagBiTreeNode
{
    ElemType data;
    struct tagBiTreeNode* leftChild;
    struct tagBiTreeNode* rightChild;
    ThrFlag lFlag;
    ThrFlag rFlag;
}BiTreeNode, *pBiTreeNode;//指向BiTNode的指针

//创建二叉树
static void CreatBiTree(pBiTreeNode *root);
//访问树
static void VisitTree(pBiTreeNode p, const int level);
//前序线索化树
static void PreOrderThreading(pBiTreeNode root);
//中序线索化树
static void InOrderThreading(pBiTreeNode root);
//后序线索化树
static void PostOrderThreading(pBiTreeNode root);

pBiTreeNode pre;

static void CreatBiTree(pBiTreeNode *root)
{
    /*Here we creat the tree in preorder, so the input 
    sequences must comply with the preorder*/
    ElemType c;
    cin>>c;
    if(c != '#')
    {
	*root = (BiTreeNode*)malloc(sizeof(BiTreeNode));
    	(*root)->data = c;
    	(*root)->lFlag = Link;
    	(*root)->rFlag = Link;
        CreatBiTree(&(*root)->leftChild);
        CreatBiTree(&(*root)->rightChild);
    }else
    {
		*root = NULL;
		return;
    }
}

static void VisitTree(pBiTreeNode p, const int level)
{
	if(level > 0)
	{
		cout<<p->data<<" is on the level "<<level<<"."<<endl;
	}
	else
	{
		cout<<p->data<<" ";
	}
}

static void PreOrderThreading(pBiTreeNode root)
{
	if(root == NULL)
	{
		return;
	}else
	{
		if(!root->leftChild)
		{
			p->lFlag = Thread;
			root->leftChild = pre;
		}
		if(!pre->rightChild)
		{
			pre->rFlag = Thread;
			pre->rightChild = root;
		}
		pre = root;
		InOrderThreading(root->leftChild);
		InOrderThreading(root->rightChild);
	}
}

static void InOrderThreading(pBiTreeNode root)
{
	if(root == NULL)
	{
		return;
	}else
	{
		InOrderThreading(root->leftChild);
		if(!root->leftChild)
		{
			p->lFlag = Thread;
			root->leftChild = pre;
		}
		if(!pre->rightChild)
		{
			pre->rFlag = Thread;
			pre->rightChild = root;
		}
		pre = root;
		InOrderThreading(root->rightChild);
	}
}

static void PostOrderThreading(pBiTreeNode root)
{
	if(root == NULL)
	{
		return;
	}else
	{
		InOrderThreading(root->leftChild);
		InOrderThreading(root->rightChild);
		if(!root->leftChild)
		{
			p->lFlag = Thread;
			root->leftChild = pre;
		}
		if(!pre->rightChild)
		{
			pre->rFlag = Thread;
			pre->rightChild = root;
		}
		pre = root;
	}
}

int main(void)
{
    pBiTreeNode root;
    
    cout<<"Please input the node of the tree(preorder sequence):  "<<endl;
    CreatBiTree(&root);
    cout<<endl;

    cout<<"Threading the tree in preorder:  "<<endl;
    PreOrderThreading(root);
    cout<<endl;
   
    cout<<"Threading the tree in inorder:  "<<endl;
    InOrderThreading(root);
    cout<<endl;

    
    cout<<"Threading the tree in postorder:  "<<endl;
    PostOrderThreading(root);
    cout<<endl;

    return 0;
}
