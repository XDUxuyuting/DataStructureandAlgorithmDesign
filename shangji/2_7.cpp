#include<stdio.h>
#include<stdlib.h> 
#define maxsize 1000
typedef int datatype;
typedef struct
{
	int i,j;
	datatype v;
}Node;
typedef struct
{
	int m,n,t;
	Node data[maxsize];
}spmatrix;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
void AddMat(spmatrix *&a,spmatrix *b)//加到A上 
{
	int x=0;
	int flag=0; 
	while(x<b->t)
	{
		int y=0;
		while(b->data[x].i!=a->data[y].i&&y<a->t)
		{
			if(b->data[x].i==a->data[y].i)
			{
				if(b->data[x].j==a->data[y].j)
				{
					a->data[y].v=a->data[y].v+b->data[x].v;
					flag=1;
				}
			}
			y++;
		}
		if(flag==0)
		{
			a->data[a->t].i=b->data[x].i;
			a->data[a->t].j=b->data[x].j;
			a->data[a->t].v=b->data[x].v;
			a->t++;
		}
		x++; 
	}
} 



