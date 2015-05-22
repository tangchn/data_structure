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
typedef enum {RH = -1, EH, LH} BalanceFactor;

typedef struct _BiTreeNode
{
	ElemType data;
	struct _BiTreeNode* leftChild;
	struct _BiTreeNode* rightChild;
	int BF;
}BiTreeNode, *pBiTreeNode;//指向BiTNode的指针

static void CreatAVL(pBiTreeNode* root);
static void LeftRotation(pBiTreeNode* root);
static void RightRotation(pBiTreeNode* root);
static void LeftBalance(pBiTreeNode* root);
static void RightBalance(pBiTreeNode* root)
static void InOrderTraversal(const pBiTreeNode root);
static void PreOrderTraversal(const pBiTreeNode root);
static Status SearchAVL(const pBiTreeNode root, ElemType key, pBiTreeNode father, pBiTreeNode* p);
static Status InsertAVL(const pBiTreeNode root, ElemType key);
static Status DeleteAVL(const pBiTreeNode root, ElemType key);

int main(void)
{
	pBiTreeNode root;
	//cout<<"Please input the node data:"<<endl;
	CreatAVL(&root);
	PreOrderTraversal(root);
	InOrderTraversal(root);
	LeftRotation(&root);
	PreOrderTraversal(root);
	InOrderTraversal(root);
	/*cout<<"Please input the number to be searched:"<<endl;
	ElemType e;
	pBiTreeNode p;
	cin>>e;
	if(SearchAVL(root, e, NULL, &p))
	{
		cout<<"Search succeeds"<<endl;
	}else
	{
		cout<<"Search fails"<<endl;
	}*/
	return 0;
}

static void CreatAVL(pBiTreeNode* root)
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
		CreatAVL(&(*root)->leftChild);
		CreatAVL(&(*root)->rightChild);
	}
}

static void LeftRotation(pBiTreeNode* root)
{
	pBiTreeNode r;
	r = (*root)->rightChild;
	(*root)->rightChild = r->leftChild;
	r->leftChild = (*root);
	(*root) = r;
}

static void RightRotation(pBiTreeNode* root)
{
	pBiTreeNode l;
	l = (*root)->leftChild;
	(*root)->leftChild = l->rightChild;
	l->rightChild = (*root);
	(*root) = l;
}

static void LeftBalance(pBiTreeNode* root)
{
	pBiTreeNode l, lr; /*lr means the right child of the left child of the root*/
	lc = (*root)->leftChild;
	switch(l->BF)
	{
		case LH: /*LL Type, use rightRotation just once*/
			(*root)->BF = EH;
			l->BF = EH;
			RightRotation(root);
			break；
		case RH: /*LR Type, just leftRotation first, then use rightRotation*/
			lr = l->rightChild;
			switch(lr->BF)
			{
				case LH:
					(*root)->BF = RH;
					l->BF = EH;
					break;
				case EH:
					(*root)->BF = EH;
					l->BF = EH;
					break;
				case RH:
					(*root)->BF = EH;
					l->BF = LH;
					break;
			}
			lr->BF = EH;
			LeftRotation(&l);
			RightRotation(root);
			break;
	}
}

static void RightBalance(pBiTreeNode* root)
{
	pBiTreeNode r, rl; /*lcr means the right child of the left child of the root*/
	r = (*root)->rightChild;
	switch(r->BF)
	{
		case RH: /*RR Type, use rightRotation just once*/
			(*root)->BF = EH;
			r->BF = EH;
			LeftRotation(root);
			break；
		case RH: /*RL Type, just leftRotation first, then use rightRotation*/
			rl = r->leftChild;
			switch(rl->BF)
			{
				case LH:
					(*root)->BF = EH;
					r->BF = LH;
					break;
				case EH:
					(*root)->BF = EH;
					r->BF = EH;
					break;
				case RH:
					(*root)->BF = LH;
					r->BF = EH;
					break;
			}
			rl->BF = EH;
			RightRotation(&r);
			LeftRotation(root);
			break;
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

static void PreOrderTraversal(const pBiTreeNode root)
{
	if(root == NULL)
	{
		cout<<"The tree is empty"<<endl;
		return;
	}
	cout<<"The accessing order when explits PreOrderTraversal:"<<endl;
	stack<pBiTreeNode> s;
	pBiTreeNode p = root;
	while(!s.empty() || p != NULL)
	{
		while(p!= NULL)
		{
			s.push(p);
			cout<<p->data<<" ";
			p = p->leftChild;
		}
		if(!s.empty())
		{
			p = s.top();
			s.pop();
			p = p->rightChild;
		}
	}
	cout<<endl;
}

static Status SearchAVL(pBiTreeNode root, ElemType key, pBiTreeNode father, pBiTreeNode* p)
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
		return SearchAVL(root->leftChild, key, root, p);
	}else
	{
		return SearchAVL(root->rightChild, key, root, p);
	}
}
