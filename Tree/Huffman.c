/*************************************************************************
	> File Name: Huffman.c
	> Description: 哈夫曼树和哈夫曼编码
	> Author: Yves
	> E-mail: tangye@hotmail.com
	> Created Time: 2015-2-15. 11:07:51
 *
 *心得:构造数组，自己走一遍就好了
 *
 *
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#const int SUCCESS         1
#const int FAILURE         0
#const int ERROR           -1
#const int MAXBIT          100
#const int MAXVALUE        10000
#const int MAXLEAFNUMBER      20
#const int MAXNODENUMBER       2*MAXLEAFNUMBER-1

typedef char ElemType;
typedef struct _HNode
{
    ElemType data;//节点数据
    double weight;//节点权重
    int parent;//父节点在数组中的位置索引
    int leftChild;//左孩子在数组中的位置索引
    int rightChild;//右孩子在数组中的位置索引
}HNode,*pHNode;

typedef struct QHCode{
    char code[MAXLEAFNUMBER];//记录编码
    int start;
}HCode;

HNode HuffNode[MAXNODENUMBER];
HCode HuffCode[MAXLEAFNUMBER];

int creatHuffmanTree(HNode* HuffNode,int n);
int HuffmanDecode();
int HuffmanEncode(HNode* HuffNode, HCode* HuffCode,int n);
int DisplayHuffCode(HNode* HuffNode, HCode* HuffCode,int n);

int main(void)
{
    int n;//实际的叶结点数目
	printf("请输入需要生成的哈夫曼树叶结点的数目n（n<%d）= ",MAXLEAFNUMBER);
	scanf("%d",&n);
	if(n > MAXLEAFNUMBER)
	{
		return 0;
	}
	creatHuffmanTree(HuffNode,n);
    HuffmanEncode(HuffNode,HuffCode,n);
    //HuffmanDecode();
    DisplayHuffCode(HuffNode,HuffCode,n);

    return 0;
}

int creatHuffmanTree(HNode* HuffNode,int n)
{
    int i,j;
    double minL,minR;
    int iL,iR;

    /* 初始化各个叶子节点 */
    for(i = 0; i < MAXNODENUMBER; i++)
    {
        HuffNode[i].weight = -1;
        HuffNode[i].leftChild  = -1;
        HuffNode[i].rightChild = -1;
        HuffNode[i].parent     = -1;
    }

    /* 输入 n 个叶子结点的权值*/
    for (i = 0; i < n; i++)
    {
        HuffNode[i].data = 'a' + i;
        printf ("请输入第 %d 个叶子节点%c的权值: \n", i,HuffNode[i].data);
        scanf ("%lf", &HuffNode[i].weight);
    }

    /* 开始构造 */
    for (i = n; i < 2*n - 1; i++)
    {
        minL = minR = MAXVALUE;//设置minL < minR
        for(j = 0; j < i; j++) //目前有i个节点
        {
            if(HuffNode[j].weight < minL && HuffNode[j].parent == -1)//如果比minL还小
            {
                iR = iL;
                minR = minL;
                iL = j;
                minL = HuffNode[j].weight;
            }else if(HuffNode[j].weight < minR && HuffNode[j].parent == -1)//如果处于两者之间
            {
                iR = j;
                minR = HuffNode[j].weight;
            }
        }
        //找到minL和minR后
        HuffNode[iL].parent = i;
        HuffNode[iR].parent = i;
        HuffNode[i].weight = minL + minR;
        HuffNode[i].leftChild = iL;
        HuffNode[i].rightChild = iR;
    }
    return SUCCESS;
}

int HuffmanDecode()
{
    return SUCCESS;
}

int HuffmanEncode(HNode* HuffNode, HCode* HuffCode,int n)
{
    int i,j,k;

    for(i = 0; i < n; i++)
    {
        HCode tempCode;
        j = i;
        k = HuffNode[j].parent;
        tempCode.start = n - 1;
        while(k != -1)//如果有父节点
        {
            if(HuffNode[k].leftChild == j)//左孩子
            {
                tempCode.code[tempCode.start--] = '0';
            }else
            {
                tempCode.code[tempCode.start--] = '1';
            }
            j = k;
            k = HuffNode[j].parent;
        }
        tempCode.start++;
        HuffCode[i] = tempCode;
    }
    return SUCCESS;
}

int DisplayHuffCode(HNode* HuffNode, HCode* HuffCode,int n)
{
    int i,j;
    printf("生成的哈夫曼编码为:\n");
    for(i = 0; i < n; i++)
    {
        printf("符号%c编码为: ",HuffNode[i].data);
        for(j = HuffCode[i].start; j < n; j++)
        {
            printf("%c",HuffCode[i].code[j]);
        }
        printf("\n");
    }
    return SUCCESS;
}
