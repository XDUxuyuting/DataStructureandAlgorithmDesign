#include<stdio.h>
#include<stdlib.h>
typedef char datatype;
typedef struct node
{
	datatype data;
	struct node *lchild,*rchild;
}bitree;
int find(bitree*t,datatype n)//按值查找 
{	
	int flag=0;
	if(t!=NULL)
	{
		find(t->lchild,n);
		find(t->rchild,n);
		if(t->lchild->data==n||t->rchild->data==n)
		{
			flag=1;
			printf("双亲值为%c",t->data);
		}
	}
	return flag;
}
int main()
{
	bitree *t;
	datatype n;
	if(t->data==n)
	{
		printf("该结点没有双亲结点");
		return 0;
	}
	if(!find(t,n))
	{
		printf("没有找到该结点");
		return 0;
	}
	return 1;
}
