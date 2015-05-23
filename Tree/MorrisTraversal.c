
/*************************************************************************
	> File Name: MorrisTraversal.c
	> Description: 线索二叉树的实现
	> Author: Yves
	> E-mail: tangye@hotmail.com
	> Created Time: 2015-5-23. 22:51:16
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct tagBiTreeNode
{
    ElemType data;
    struct tagBiTreeNode* leftChild;
    struct tagBiTreeNode* rightChild;
}BiTreeNode, *pBiTreeNode;//指向BiTNode的指针

static void CreatBiTree(pBiTreeNode *root);//创建二叉树
static void PreOrderMorrisTraversal(pBiTreeNode root);//前序Morris遍历
static void InOrderMorrisTraversal(pBiTreeNode root);//中序Morris遍历
static void PostOrderMorrisTraversal(pBiTreeNode root);//后序Morris遍历

pBiTNode pre;

int main(void)
{
    pBiTreeNode root;
    printf("Please input the node of the tree(preorder sequence): ");
    CreatBiTree(&root);
    printf("Traverse the tree in PreOrderMorrisTraversal\n");
    PreOrderMorrisTraversal(root);
    printf("Traverse the tree in InOrderMorrisTraversal\n");
    InOrderMorrisTraversal(root);
    printf("Traverse the tree in PostOrderMorrisTraversal\n");
    PostOrderMorrisTraversal(root)
    
    return 0;
}

static void CreatBiTree(pBiTreeNode *root)
{
    ElemType c;
    scanf("%c",&c);
    if(c == '#')
    {
        *root = NULL;
    }else
    {
        *root = (pBiTreeNode)malloc(sizeof(BiTreeNode));
        (*root)->data = c;
        CreatBiTree(&(*root)->leftChild);
        CreatBiTree(&(*root)->rightChild);
    }
}

static void PreOrderMorrisTraversal(pBiTreeNode root)
{
	if(root == NULL)
    {
    	return;
    }
    pBiTreeNode cur,pre,temp;
    cur = root;
    while(cur != NULL)
    {
    	if(!cur->leftChild)
    	{
    		printf("%c ", cur->data);
    		pre = cur;
    		cur = cur->rightChild;
    	}else
    	{
    		for(temp = cur->leftChild; temp->rightChild != NULL && temp->rightChild != cur; temp = temp->rightChild);
    		if(temp->rightChild == NULL)
    		{
    			temp->rightChild = cur;
    			printf("%c ", cur->data);
    			pre = cur;
    			cur = cur->leftChild;
    		}else
    		{
    		
    			temp->rightChild = NULL;
    			cur = cur->rightChild;
    		}
    	}
    }
}


static void InOrderMorrisTraversal(pBiTreeNode root)
{
    if(root == NULL)
    {
    	return;
    }
    pBiTreeNode cur,pre,temp;
    cur = root;
    while(cur != NULL)
    {
    	if(!cur->leftChild)
    	{
    		printf("%c ", cur->data);
    		pre = cur;
    		cur = cur->rightChild;
    	}else
    	{
    		for(temp = cur->leftChild; temp->rightChild != NULL && temp->rightChild != cur; temp = temp->rightChild);
    		if(temp->rightChild == NULL)
    		{
    			temp->rightChild = cur;
    			cur = cur->leftChild;
    		}else
    		{
    			printf("%c ", cur->data);
    			temp->rightChild = NULL;
    			pre = cur;
    			cur = cur->rightChild;
    		}
    	}
    }
}

static void PostOrderMorrisTraversal(pBiTreeNode root)
{
	
}

