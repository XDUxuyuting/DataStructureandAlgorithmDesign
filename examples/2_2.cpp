#include<stdio.h>
#include<stdlib.h>
#define maxsize 1024
typedef int datatype;

typedef struct
{
	datatype data[maxsize];
	int last;
}SQList;
void merge(SQList*A,SQList*B,SQList*&C)
{

	int i=0,j=0,k=0;
	while (1)
	{
	
		while(A->data[i]<=B->data[j]&&i<A->last)
		{
			C->data[k]=A->data[i];
			k++;
			C->last++;
			i++;
		}
		while(B->data[j]<=A->data[i]&&j<B->last)
		{
			C->data[k]=B->data[j];
			k++;
			C->last++;
			j++;
		}
		if(C->last==(A->last+B->last))break;
	}
}

