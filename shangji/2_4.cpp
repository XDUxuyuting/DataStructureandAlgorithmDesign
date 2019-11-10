#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
typedef struct Node
{
	datatype data;
	struct Node *next;
}CQueueNode;
typedef struct
{
	CQueueNode *rear;
}CLinkQueue;
CLinkQueue *q;
void InitCLinkQueue()
{
	CLinkQueue*q=(CLinkQueue*)malloc(sizeof(CLinkQueue));//指向结构体指针 
	q->rear->next=q->rear;
}

void EnQueue(CLinkQueue*&q,datatype x)
{
	CQueueNode*s;
	s=(CQueueNode*)malloc(sizeof(CQueueNode));
	s->data=x;
	s->next=q->rear->next; 
	q->rear->next=s;
	q->rear=s;
}
void DeQueue(CLinkQueue*&q,datatype key)//按值删除结点 
{
	CQueueNode*p,*s;
	p=(CQueueNode*)malloc(sizeof(CQueueNode));
	p=q->rear;
	while(p->next->data!=key)p=p->next;
	s=p->next;
	p->next=p->next->next;
	free(s);
} 

