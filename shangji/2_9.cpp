#include<stdio.h>
#include<stdlib.h>
typedef char datatype;
typedef struct node
{
	datatype data;
	struct node *lchild,*rchild;
}bitree;
bitree *T;
void inorder(bitree* T)
{
	bitree *tempt;
	if(T!=NULL)
	{
		inorder(T->lchild);//遍历左子树 
		tempt = T->lchild;
		T->lchild=T->rchild;
		T->rchild=tempt;//交换左子树的所有子树 
		inorder(T->lchild);//遍历原右子树现左子树 
	 } 
}
