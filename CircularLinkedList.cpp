#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
typedef struct dnode
{
	datatype data;
	struct dnode *prior,*next;
}dlinklist;
dlinklist*head;
void DInsertAfter(dlinklist*p,datatype x)//双链表后插法 
{
	dlinklist*s=(dlinklist*)malloc(sizeof(dlinklist));
	s->data=x;
	s->prior=p;//S前驱 
	s->next=p->next;//S后继 
	p->next->prior=s;//S给S后继的前驱 
	p->next=s;//S给P后继 
}
void DInsertBefore(dlinklist*p,datatype x)//双链表前插法 
{
	dlinklist*s=(dlinklist*)malloc(sizeof(dlinklist));
	s->data=x;
	s->prior=p->prior;//S前驱 
	s->next=p;//S后继 
	p->prior->next=s;//S给S前驱的后继 
	p->prior=s;//S给P前驱 
}
void DDelete(dlinklist*p)//双链表删除P结点，假设P不为尾结点 
{
	p->prior->next=p->next;//P后继给P前驱 
	p->next->prior=p->prior;//P前驱给P后继 
	free(p);
}
dlinklist*CreatDlinkList()//采用头插法建立带有头结点的双链表 
{
	char ch;
	dlinklist*head,*s;
	head=(dlinklist*)malloc(sizeof(dlinklist));
	head->prior=head;
	head->next=head;
	printf("Input any char string:\n");
	scanf("%c",&ch);
	while(ch!='\n')
	{
		s=(dlinklist*)malloc(sizeof(dlinklist));
		s->data=ch;
		s->prior=head;//头指针给S前驱 
		s->next=head->next;//头结点给S后继 
		head->next->prior=s;//S给原头结点前驱 
		head->next=s;//S给头指针后继 
		scanf("%c",&ch);
	}
	return head;
}


