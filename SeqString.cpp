#include<stdio.h>
#include<stdlib.h>
#define maxsize 256
typedef struct
{
	char ch[maxsize];
	int length;
}SeqString;
SeqString *s;
int StrLength(char *s)//求串长度 
{
	int i=0;
	while(s[i]!='\0')//字符串结束标志 
		i++;
	return i;
}
void StrCopy(char *s1,char *s2)
{
	int i=0;
	while(s2[i]!='\0')
	{
		s1[i]=s2[i];
		i++;
	}
	s1[i]='\0';
} 
int StrCmp(char *s1,char *s2)
{
	int i=0;
	while(s1[i]==s2[i]&&s1[i]!='\0')//S1小则返回负值，S2小返回正值 
		i++;
	return s1[i]-s2[i];
}
int StrCat(char *s1,char *s2)
{
	int i=0,j=0,len1,len2;
	len1=StrLength(s1);
	len2=StrLength(s2);
	if(len1+len2>maxsize-1)
	{
		return 0;
	} 
	while(s1[i]!='\0')
		i++;//找到S1表尾 
	while(s2[j]!='\0')
		s1[i++]=s2[j++];
	s1[i]='\0';
	return 1;
}
int Index(SeqString *T,SeqString *P,int pos)
{
	int i,j;
	i=pos;
	j=1;
	while(i<=T->length&&j<=P->length)
	{
		if(T->ch[i-1]==P->ch[j-1])
		{
			i++; 
			j++;
		} //接着比较后面的字符 
		else
		{
			i=i-j+2;//先退回原来的位置（i-j+1)再加一 
			j=1;
		} 
	}
	if(j>P->length)//匹配 
		return i-P->length; 
	else return 0;//不匹配 
}


