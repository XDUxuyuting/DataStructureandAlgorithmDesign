#include<stdio.h>
#include<stdlib.h>
typedef char datatype;
typedef struct node
{
	datatype data;
	struct node*next;
}linklist;
linklist*head, *p;


void Insert(linklist*head,datatype x)
{
	linklist*p;
	p=head;
	linklist*q=(linklist*)malloc(sizeof(linklist));
	q->data=x;
	q->next=NULL;
	while(p->next!=NULL&&p->next->data>=x)
	{
		p=p->next;
	}
	if(p->next==NULL)p->next=q;
	else
	{
		q->next=p->next;
		p->next=q;
	} 
} 

