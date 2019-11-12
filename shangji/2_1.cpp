#include <stdio.h>
#include <stdlib.h>
#define stacksize 100

typedef int datatype;
typedef struct
{
	datatype data[stacksize];
	int top;
}seqstack;
typedef struct node{
	datatype data;
	struct node *next;
}listnode;
typedef listnode *linklist;
linklist head;
linklist p;
int count;
linklist creatlist(int n)
{
	linklist head;
	listnode *p1,*p2;
	int i;
	head=(linklist)malloc(sizeof(listnode));
	head->next=NULL;
	p2=head;
	printf("please input the records of the chain\n");
	for(i=0;i<n;i++)
	{	
		p1=(linklist)malloc(sizeof(listnode));
		scanf("%d",&p1->data);
		p1->next=p2->next;
		p2->next=p1;
		p2=p1; 
	}	
	return (head);
}
void print(linklist head, int n)
{
	if(head==NULL)
		printf("list null\n");
	printf("Now these %d records are:\n",n);
	p=head->next;
	printf("%4d",p->data);
	count=1;
	while(p->next!=NULL)
	{
		count++;
		p=p->next;
		printf("%4d",p->data);
		if(!(count%10))
			printf("\n");
		
	}
}
datatype push(seqstack *s, int x)
{
	if(s->top==stacksize-1)
		printf("the stack is overflow\n");
	else 
		s->data[++s->top]=x;
}
datatype pop(seqstack *s)
{
	if(s->top==-1)
		printf("the stack is empty\n");
	else 
		return (s->data[s->top--]);
}
datatype deleted(linklist head)
{
	datatype temp;
	linklist p;
	p=head->next;
	temp=(p->data);
	head->next=p->next;
	free(p);
	return (temp);	
}
void invertedlist(linklist head,int n)
{
	seqstack s;
	int i,j,temp;
	s.top=-1;
	for(i=0;i<n;i++)
	{
		temp=deleted(head);
		push(&s, temp);
	}
	for(i=0;i<n;i++)
	{
		temp=pop(&s);
		printf("%5d",temp);
		if(!((i+1)%10))
			printf("\n");
	}
	printf("\n");
}
int main()
{
	linklist head;
	int n;
	printf("Please input the value of n:\n");
	scanf("%d",&n);
	head=creatlist(n);
	print(head,n);
	printf("After inverting,the records of the chain are:\n");
	invertedlist(head,n);
	system("pause");
	return 0;
} 
