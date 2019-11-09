#include<stdio.h>
#include<stdlib.h>
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
