#include<stdio.h>
#include<stdlib.h>
typedef char datatype;
typedef struct node//定义结点结构体 
{
	datatype data;
	struct node*next;//指向下一结点的指针 
}linklist;
linklist*head,*p;//头指针和工作指针 
linklist*CreatListF()//头插法建立单链表 
{
	linklist*head,*p;
	char ch;
	head=(linklist*)malloc(sizeof(linklist));
	head->next=NULL;
	while((ch==getchar())!='\n')
	{
		p=(linklist*)malloc(sizeof(linklist));
		p->data=ch;
		p->next=head->next;//头结点给新结点 
		head->next=p;//更新头结点 
	}
	
}
linklist*CreatListR()//尾插法建立单链表 
{
	linklist*head,*p,*r;
	char ch;
	head=(linklist*)malloc(sizeof(linklist));
	head->next=NULL;
	r=head;
	while((ch=getchar())!='\n')
	{
		p=(linklist*)malloc(sizeof(linklist));
		p->data=ch;
		r->next=p;//新结点插入尾部 
		r=p;//更新尾结点 
	}
}
linklist*Get(linklist*head,int i)//按序号查找单链表 
{
	linklist*p=head;
	int j=0;
	while(p->next!=NULL&&j<i)//按序号查找 
	{
		p=p->next;
		j++;
	} 
	if(i==j)
		return p;//查找到返回第I个结点地址 
	else return NULL;
}
linklist*Located(linklist*head,datatype key)//按值查找 
{
	linklist*p=head->next;//指向头结点
	while(p!=NULL&&p->data!=key)//按值查找 
	{
		p=p->next;
	}
	return p; 	
} 
void Insert(linklist*L, datatype x, int i)//单链表插入 
{
	linklist*p,*s;
	p=Get(L,i-1);
	if(p==NULL)
		printf("查不到插入位置");
	else
	{
		s=(linklist*)malloc(sizeof(linklist));
		s->data=x;
		s->next=p->next;//P后的链给新结点 
		p->next=s;//新结点给P 
	} 
}
void Delete(linklist*L, int i)//删除单链表 
{
	linklist*r;
	r=NULL;
	p=Get(L,i-1);//找到前驱结点 
	if(p!=NULL&&p->next!=NULL)
	{
		r=p->next;
		p->next=r->next;//删除结点 
		free(r);//释放结点空间 
	}
}

