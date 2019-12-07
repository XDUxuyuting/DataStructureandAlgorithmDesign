#include<stdio.h>
#include<stdlib.h>
#define maxsize 1024
typedef char datatype;
//稀疏矩阵的三元组存储 
typedef struct
{
	int i,j;//行列 
	datatype v;//数据 
}Node;
typedef struct
{
	int m,n,t;//行列数，有非零元素数 
	Node data[maxsize];
}spmatrix;
void TransMat(spmatrix *a,spmatrix *b)
{
	int ano,bno,col;//结点序号和行号 
	b->m=a->n;
	b->n=a->m;
	b->t=a->t;//初始参数
	if(b->t>0)
	{
		bno=0;
		for(col=1;col<=a->n;col++)//遍历行 
			for(ano=0;ano<a->t;ano++)//遍历非零元素 
				if(a->data[ano].j==col)
				{
					b->data[bno].i=a->data[ano].j;
					b->data[bno].j=a->data[ano].i;//交换行列 
					b->data[bno].v=a->data[ano].v;//存入信息 
					bno++;
				} 
	} 
} 


//稀疏矩阵 十字链表存储 
typedef struct node
{
	int row;
	int col;
	struct nose *right,*down;
	union
	{
		datatype value;
		struct node *next;
	}tag;
}MatNode;


