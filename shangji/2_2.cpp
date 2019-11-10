#include<stdio.h>
#include<stdlib.h>
#define maxsize 100
typedef int datatype;
typedef struct
{
	datatype data[maxsize];
	int Top;
}SeqStack;
void InitStack(SeqStack *&S)
{
	S=(SeqStack*)malloc(sizeof(SeqStack));
	S->Top=-1;
}
int EmptyStack(SeqStack *S)
{
	if(S->Top==-1) return 1;
	else return 0;
}
int Push(SeqStack *S, datatype x)
{
	if(S->Top==maxsize-1)
	{
		printf("栈上溢");
		return 0;
	}
	else
	{
		S->data[++S->Top]=x;
		return 1;
	}
}
int Pop(SeqStack *S, datatype &x)
{
	if(Empty(S))
	{
		printf("栈下溢");
		return 0; 
	}
	else
	{
		x=S->data[S->Top--];
		return 1;
	}
}
void Conversion(int n, int base)
{
	Stack *S;
	int bit;
	InitStack(S);
	while(n!=0)
	{
		Push(S,n%base);
		n=n/base;//除基数取余 
	}
	while(!EmptyStack(S))//出栈判断是否为空 
	{
		bit=Pop(S);
		if(bit>9)printf("%c",bit+55);//转换字符输出 
		else printf("%c",bit+48);
	}
	printf("/n");
}
