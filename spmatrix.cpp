#include<stdio.h>
#include<stdlib.h> 
#define maxsize 1000
typedef int datatype;
typedef struct
{
	int i,j;
	datatype v;
}Node;
typedef struct
{
	int m,n,t;
	Node data[maxsize];
}spmatrix;
