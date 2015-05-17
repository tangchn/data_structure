/*************************************************************************
	> Author: Yves
	> E-mail: ty@msn.cn
	> File Name: BiTreeNew.cpp
	> Description: ...
	> Created  Time: 2015-05-17. 15:51:24
	> Modified Time: 2015-05-17. 15:51:24
 ************************************************************************/

#include<stack>
#include<cstdlib>
#include<>
#include<iostream>
using namespace std;

typedef char ElemType;

typedef struct
{
    ElemType data;
    struct _BiTNode* leftChild;
    struct _BiTNode* rightChild;
}BiTreeNode, *pBiTreeNode;//指向BiTNode的指针

static void CreatBiTree(pBiTreeNode *p);//创建二叉树
static void VisitTree(pBiTreeNode p);
//前序递归遍历
static void PreOrderRecursiveTraversal(pBiTreeNode p, int level, void (*VisitTree)(pBiTreeNode p, const int level));
//前序非递归遍历
static void PreRecursiveTraversal(pBiTreeNode p, int level);
//中序递归遍历
static void InOrderrRecursiveTraverse(pBiTreeNode p, int level);
//中序非递归遍历
static void InOrdeTraversal(pBiTreeNode p, int level);
//后序递归遍历
static void PostOrderRecursiveTraverse(pBiTreeNode p, int level);
//后序非递归遍历
static void PostOrderTraverse(pBiTreeNode p, int level);

static void CreatBiTree(pBiTreeNode *p)
{
    /*Here we creat the tree in preorder, so the input 
    sequences must comply with the preorder*/
    ElemType c;
    fflush(stdin);
    scanf("%c",&c);
    if(c != '#')
    {
		*p = (BiTreeNode*)malloc(sizeof(BiTreeNode));
    	(*p)->data = c;
        CreatBiTree(&(*p)->leftChild);
        CreatBiTree(&(*p)->rightChild);
    }else
    {
		*p = NULL;
		return;
    }
}

static void VisitTree(pBiTreeNode p, const int level)
{
	cout<<p->data<<" is on the level "<<level<<"."<<endl;
}

static void PreOrderRecursiveTraversal(pBiTreeNode p, int level, void (*VisitTree)(pBiTreeNode p, const int level))
{
	if(p == NULL)
	{
		return;
	}
	VisitTree(p, level);
	PreOrderRecursiveTraversal(p->leftChild, level + 1, VisitTree);
	PreOrderRecursiveTraversal(p->leftChild, level + 1, VisitTree);
}
static void PreRecursiveTraversal(pBiTreeNode p,int level)
{
	
}
static void InOrderrRecursiveTraverse(pBiTreeNode p,int level)
{
	
}
static void InOrdeTraversal(pBiTreeNode p,int level)
{
	
}
static void PostOrderRecursiveTraverse(pBiTreeNode p,int level)
{
	
}
static void PostOrderTraverse(pBiTreeNode p,int level);
{
	
}


int main(void)
{
    BiTreeNode root;
    cout<<"Please input the node of the tree(preorder sequence):  "<<endl;
    CreatBiTree(&root);
    cout<<endl;

    cout<<"Traverse the tree in preorder:  "<<endl;
    PreOrderRecursiveTraversal(root,1);
    cout<<endl;
    
    /*cout<<"Traverse the tree in preorder(non-recursive):  "<<endl;
    PreRecursiveTraversal(root,1);
    cout<<endl;

    cout<<("Traverse the tree in inorder:  "<<endl;
    InOrderrRecursiveTraverse(root,1);
    cout<<endl;
    
    cout<<("Traverse the tree in inorder(non-recursive):  "<<endl;
    InOrdeTraversal(root,1);
    cout<<endl;

    cout<<("Traverse the tree in posteorder:  "<<endl;
    PostOrderRecursiveTraverse(root,1);
    cout<<endl;
    
    cout<<("Traverse the tree in postorder(non-recursive):  "<<endl;
    InOrderTraverse(root,1);
    PostOrderTraverse(root,1);
    cout<<endl;*/
    
    return 0;
}
