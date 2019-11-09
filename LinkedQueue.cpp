#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
typedef struct node
{
	datatype data;
	struct node*next;
}QueueNode;
typedef struct
{
	QueueNode *front, *rear;
}LinkQueue;
void InitQueue(LinkQueue*&q)//队列初始化 
{
	q=(LinkQueue*)malloc(sizeof(LinkQueue));//产生指向结构体指针 
	q->front=q->rear=(QueueNode*)malloc(sizeof(QueueNode));//产生头尾节点指针 
	q->front=NULL;
	q->rear=NULL;
}
void SetNull(LinkQueue*q)//置空链队 
{
	q->rear=q->front;//头尾指针对齐 
	q->front->next=NULL;//置空第一个结点 （第一个结点不存储数据） 
} 
int Empty(LinkQueue*q)//判断空队 
{
	if(q->front==q->rear)return 1;
	else return 0;
} 
void EnQueue(LinkQueue*q,datatype x)//入队 
{
	q->rear->next=(QueueNode*)malloc(sizeof(QueueNode));//生成新结点，尾结点指向新结点 
	q->rear=q->rear->next;//更新尾结点 
	q->rear->data=x;//元素入队 
	q->rear->next=NULL;//尾结点后继置空 
}
int DeQueue(LinkQueue*q,datatype&x)//出队 
{
	QueueNode*s;
	if(Empty(q))
	{
		printf("队空");
		return 0; 
	} 
	else 
	{
		s=q->front->next;
		if(s->next==NULL)//队列只有一个结点存储数据，出队后为空队 
		{
			q->front->next=NULL;
			q->rear=q->front;//置空 
		} 
		else q->front->next=s->next;//出队
		x=s->data;//带出队头元素 
		free(s);
		return 1; 
	}
}
int GetFront(LinkQueue*q,datatype&x)//取队头元素 
{
	if(Empty(q))
	{
		printf("队空");
		return 0;
	}
	else
	{
		x=q->front->next->data;
		return 1;
	}
} 


