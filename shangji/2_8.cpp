#include<stdio.h>
#include<stdlib.h>
#define maxsize 1024
int array[maxsize];

int main()
{
	int front,rear,temp;
	front=0;
	rear=maxsize-1;

	while(front!=rear)
	{
		if((array[rear]%2)==1)
		{
			temp=array[rear];
			if((array[front]%2)==0)
			{
				array[rear]=array[front];
				array[front]=temp;
				front++;
				rear--;
			}
			else front++;
		}
		else
		{
			front++;
			rear--;
		}
	}
}
