#include<stdio.h>
#include<stdlib.h>
#define maxsize 1024
typedef int datatype;
typedef struct
{
	datatype data[maxsize];
	int front;
	int rear;
}SeQueue;
SeQueue*sq=(SeQueue*)malloc(sizeof(SeQueue));
void InitQueue(SeQueue*&sq)//空循环队列 
{
	sq=(SeQueue*)malloc(sizeof(SeQueue));
	sq->front=sq->rear=0;//头尾指针相同 
}
void SetNull(SeQueue*)//置空 
{
	sq->front=sq->rear=0;
}
int Length(SeQueue*sq)//求队列长度 
{
	return (sq->rear-sq->front+maxsize)%maxsize;//避免产生一个负数，加一个M，再取余 
}
int EnQueue(SeQueue*sq, datatype x)//入队 
{
	if(sq->front==(sq->rear+1)%maxsize)//采用少一个元素空间来区分队满和队空 
	{
		printf("队满");
		return 0;
	}
	else
	{
		sq->rear=(sq->rear+1)%maxsize;//插入队尾 
		sq->data[sq->rear]=x;
		return 1;
	}
}
int Dequeue(SeQueue*sq, datatype&x)//出队 
{
	if(sq->front==sq->rear)
	{
		printf("队空");
		return 0;
	}
	else
	{
		sq->front=(sq->front+1)%maxsize;//front处不存储数据 
		x=sq->data[sq->front];
		return 1;
	}
}
int GetFront(SeQueue*sq,datatype&x)//取队头元素 
{
	if(sq->front==sq->rear)
	{
		printf("栈空");
		return 0;
	}
	else
	{
		x=sq->data[(sq->front+1)%maxsize];
		return 1;
	}
}


