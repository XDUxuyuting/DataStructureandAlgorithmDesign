#include<stdio.h>
#include<stdlib.h>
#define maxsize 1024
typedef int datatype;
typedef struct
{
	datatype data[maxsize];
	int Top;//栈顶指针（整数下标） 
}SeqStack;
void InitStack(SeqStack*&S)//指针引用，顺序栈初始化 
{
	
	S=(SeqStack*)malloc(sizeof(SeqStack));
	S->Top=-1;//栈顶指针置为-1 
} 
void SetNull(SeqStack*S)//顺序栈置空 
{
	S->Top=-1;
}
int Empty(SeqStack*S)//判断空栈 
{
	if(S->Top==-1) return 1;
	else return 0;
} 
int Push(SeqStack*S,datatype x)//顺序栈入栈 
{
	if(S->Top==maxsize-1)//判断栈满 
	{
		printf("栈满"); 
		return 0; 
	}
	else
	{
		S->data[++S->Top]=x;//栈顶指针先自增，同时存入数据 
		return 1;
	}
}
int Pop(SeqStack*S,datatype&x)//出栈，将栈顶元素带回 
{
	if(Empty(S))//判断栈空 
	{
		printf("栈空");
		return 0;
	}
	else
	{
		x=S->data[S->Top--];//先提取栈顶元素，栈顶指针减减 
		return 1;
	}
}
int GetTop(SeqStack*S,datatype&x)//获取栈顶元素 
{
	if(Empty(S))
	{
		printf("栈空");
		return 0;
	}
	else
	{
		x=S->data[S->Top];
		return 1;
	}
 } 
 
typedef struct
{
	datatype v[maxsize];
	int Top1, Top2;
}SeqStack2;
SeqStack2*S=(SeqStack2*)malloc(sizeof(SeqStack2));
void push(SeqStack2*S, datatype x, int i)
{
	if(S->Top1+1==S->Top2) printf("栈满");
	else if(i==1)
	{
		S->Top1++;
		S->v[S->Top1]=x;//入1号栈 
	}
	else
	
	{
		S->Top2--;//更新栈顶指针 
		S->v[S->Top2]=x; 
	}
}
datatype pop(SeqStack2*S, int i)//出栈 
{
	datatype x;
	if(i==1)
	{
		if(S->Top1==-1)printf("1号栈空");
		else
		{
			x=S->v[S->Top1];
			S->Top1--;//出1号栈 
		} 
	}
	else if(S->Top2==maxsize)printf("2号栈空");
		else
		{
			x=S->v[S->Top2];
			S->Top2++;//更新栈顶指针 
		}
 } 

