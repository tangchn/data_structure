/*************************************************************************
	> Author: Yves
	> E-mail: tanngye@hotmail.com
	> File Name: AVL.cpp
	> Description: ...
	> Created  Time: 2015-05-22. 10:46:18
	> Modified Time: 2015-05-22. 10:46:18
 ************************************************************************/

#include<iostream>
#include<stack>
#include<cstdlib>

using namespace std;

typedef int ElemType;
typedef enum {FAILURE,SUCCESS} Status;

typedef struct _BiTreeNode
{
	ElemType data;
	struct _BiTreeNode* leftChild;
	struct _BiTreeNode* rightChild;
}BiTreeNode, *pBiTreeNode;//指向BiTNode的指针


static void CreatBiTree(pBiTreeNode* root);
static void DefaultCreatBiTree(pBiTreeNode* root);
static void InOrderTraversal(const pBiTreeNode root);
static Status SearchBST(const pBiTreeNode root, ElemType key, pBiTreeNode father, pBiTreeNode* p);
static Status InsertBST(const pBiTreeNode root, ElemType key);
static Status DeleteBST(const pBiTreeNode root, ElemType key);

ElemType treeNode[21] = {62,58,47,35,404,37,404,404,51,404,404,404,88,73,404,404,99,93,404,404,404};
size_t k = 0;

int main(void)
{
	pBiTreeNode root;
	//cout<<"Please input the node data:"<<endl;
	DefaultCreatBiTree(&root);
	InOrderTraversal(root);
	
	cout<<"Please input the number to be searched:"<<endl;
	ElemType e;
	pBiTreeNode p;
	cin>>e;
	if(SearchBST(root, e, NULL, &p))
	{
		cout<<"Search succeeds"<<endl;
	}else
	{
		cout<<"Search fails"<<endl;
	}
	return 0;
}

static void CreatBiTree(pBiTreeNode* root)
{
	ElemType e;
	cin>>e;
	if(e == 404)
	{
		*root = NULL;
		return;
	}else
	{
		*root =  (BiTreeNode*)malloc(sizeof(BiTreeNode));
		(*root)->data = e;
		CreatBiTree(&(*root)->leftChild);
		CreatBiTree(&(*root)->rightChild);
	}
}


static void DefaultCreatBiTree(pBiTreeNode* root)
{
	if(treeNode[k] == 404)
	{
		*root = NULL;
		k++;
		return;
	}else
	{
		*root = (pBiTreeNode)malloc(sizeof(pBiTreeNode));
		(*root)->data = treeNode[k];
		k++;
		DefaultCreatBiTree(&(*root)->leftChild);
		DefaultCreatBiTree(&(*root)->rightChild);
	}
}

static void InOrderTraversal(const pBiTreeNode root)
{
	if(root == NULL)
	{
		cout<<"The tree is empty"<<endl;
		return;
	}
	cout<<"The accessing order when explits InOrderTraversal:"<<endl;
	stack<pBiTreeNode> s;
	pBiTreeNode p = root;
	while(!s.empty() || p != NULL)
	{
		while(p!= NULL)
		{
			s.push(p);
			p = p->leftChild;
		}
		if(!s.empty())
		{
			p = s.top();
			s.pop();
			cout<<p->data<<" ";
			p = p->rightChild;
		}
	}
	cout<<endl;
}

static Status SearchBST(pBiTreeNode root, ElemType key, pBiTreeNode father, pBiTreeNode* p)
{
	if(root == NULL)
	{
		*p = father;
		return FAILURE;
	}else if( key == root->data)
	{
		*p = root;
		return SUCCESS;
	}else if(key < root->data)
	{
		return SearchBST(root->leftChild, key, root, p);
	}else
	{
		return SearchBST(root->rightChild, key, root, p);
	}
}
