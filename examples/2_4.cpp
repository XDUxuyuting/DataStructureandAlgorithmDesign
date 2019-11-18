#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
typedef struct node
{
	datatype data;
	struct node*next;
}linklist;
linklist*head;
linklist* Createlist()
{
	linklist*head=(linklist*)malloc(sizeof(linklist));
	datatype x;
	head->data=x;
	head->next=head;
}
linklist* merge(linklist*head1,linklist*head2)
{
	linklist*p;
	p=head1;
	while(p->next!=head1)
	{
		p=p->next;
	}
	p->next=head2;
	p=p->next;
	while(p->next!=head2)
	{
		p=p->next;
	}
	p->next=head1;
	return head1;
} 
//以下是书上的代码
linklist* connect(linklist*La,linklist*Lb)//use the rear point
{
	linklist*p=La->next;
	La->next=Lb->next->next;
	free(Lb->next);  //释放B表头结点 
	Lb->next=p;      //尾结点指针域指向头结点 
	return Lb;       //返回表尾指针 
}

void Connect(linklist*La,linklist*Lb)
{
	linklist*p=La->next;
	while(p->next!=La)p=p->next;
	p->next=Lb->next;
	while(p->next!=Lb)p=p->next;
	free(p->next);
	p->next=La;
} 



