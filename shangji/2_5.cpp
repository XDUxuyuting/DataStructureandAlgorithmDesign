#include<stdio.h>
#include<string.h>
void StrInsert(char *&S,char *T,int i)
{
	int m,n,k,j;
	m=strlen(S);
	n=strlen(T);
	char L[m],O[n+m-i+1]; 
	if(i>n)
	{
		printf("非法插入");
	}
	else
	{
		for(j=i,k=0;j<=m-1;j++,k++)
		{
			L[k]=S[j];
		}
		strcpy(O,T);
		strcat(O,L);
		S[i]='\0';
		strcat(S,O);
	} 
}
