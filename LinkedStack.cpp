#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
typedef struct node//结点结构体 
{
	datatype data;
	struct node*next;//后继结点指针 
}StackNode;//链栈结点类型 
typedef struct
{
	StackNode*Top;//指向栈顶结点的指针 
}LinkStack;
void InitStack(LinkStack*&S)//建立空链栈 
{
	S=(LinkStack*)malloc(sizeof(LinkStack));
	S->Top=NULL;
}
void SetNull(LinkStack*S)//链栈置空 
{
	S->Top=NULL;
} 
int Empty(LinkStack*S) 
{
	if(S->Top==NULL)return 1;
	else return 0;
}
void Push(LinkStack*S,datatype x)//链栈入栈 
{
	StackNode*p=(StackNode*)malloc(sizeof(StackNode));//产生一个新结点 
	p->data=x;
	p->next=S->Top;//头插法 头结点给P后继 
	S->Top=p;//更新头结点 
}
int Pop(LinkStack*S,datatype&x)//链栈栈顶元素出栈 
{
	StackNode*p=S->Top;
	if(Empty(S))
	{	
		printf("栈空");
		return 0;
	}
	else
	{
		x=p->data;
		S->Top=p->next;//更新栈顶结点 
		free(p);
		return 1;
	}
} 
int GetTop(LinkStack*S,datatype&x)//取栈顶元素 
{
	StackNode*p=S->Top;
	if(Empty(S))
	{
		printf("栈空");
		return 0;
	} 
	else
	{
		x=p->data;
		return 1;
	}
} 
