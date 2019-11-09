#include<stdio.h>
#include<stdlib.h>
#define maxsize 1024
typedef int datatype;
typedef struct
{
	datatype data[maxsize];
	int last;//长度 
}sequenlist;

sequenlist*InitLsit()//通过函数返回值将结果带回主调函数 
{
	sequenlist*L=(sequenlist*)malloc(sizeof(sequenlist));//动态分配存储空间 
	L->last=0;
	return L;
}
void InitList(sequenlist**L)//采用指向指针的指针作为函数参数，通过函数参数带回主调结果 ??
{
	//sequenlist* ll = (sequenlist*)malloc(sizeof(sequenlist));
	
	*L=(sequenlist*)malloc(sizeof(sequenlist));
	(*L)->last=0;//此处书上有错误，带括号改变优先级 箭头比星号优先级高 
}
void InitList(sequenlist*&L)//采用指针的引用作为函数参数 
{
	L=(sequenlist*)malloc(sizeof(sequenlist));
	L->last=0;
}
int Insert(sequenlist *L, datatype x,int i)//顺序表插入 
{
	int j;
	if(L->last==maxsize)//判断表满 
	{
		printf("表已满");
		return 0; 
	}
	else if(i<1||i>L->last)//判断非法插入 
	{
		printf("非法插入位置");
		return 0; 
	}
	else
	{
		for(j=L->last;j>=i;j--)
			L->data[j]=L->data[j-1];//结点后移 
		L->data[i-1]=x;//插入到L->data[i-1] 
		L->last++;//长度加加 
		return 1;
	}
} 
int Delete(sequenlist *L, int i)//顺序表删除 
{
	int j;
	if((i<1)||(i>L->last))
	{
		printf("非法删除位置");
		return 0;
	} 
	else
	{
		for(j=i;j<=L->last-1;j++)
			L->data[j-i]=L->data[j];//结点前移 
		L->last--;//长度减减 
		return 1;
	} 
}



