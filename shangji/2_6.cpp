#include<stdio.h>
#include<string.h>
#define CHUNKSIZE 4
typedef struct node
{
	char ch[CHUNKSIZE];
	struct node*next;
}Chunk;
typedef struct
{
	Chunk *head,*tail;
	int length;
}LinkString;
LinkString s;

char find(LinkString *S, LinkString *T)
{
	int flag=0;
	int i,j;
	Chunk *p,*q;
	p=S->head->next;
	while(p!=NULL)
	{
		for(i=0;i<CHUNKSIZE&&p->ch[i]!='\0';i++)
		{
			q=T->head->next;
			while(q!=NULL)
			{
				for(j=0;j<CHUNKSIZE&&q->ch[j]!='\0';j++)
				{
					if(p->ch[i]==q->ch[j])//找到 
					{
						flag=1;
						break;
					}
				}
				if(flag==1)break;
				q=q->next;
			}
			if(flag==0)return (p->ch[i]);
		}
		p=p->next;
	}
}
