#include <stdio.h>
#include <stdlib.h>

struct Dyanamic
{
	int *ptr;
	int lastindex;
	int capacity;
};

struct Dyanamic * createarray(int cap)
{
	struct Dyanamic *dy;
	dy=malloc(sizeof(struct Dyanamic));
	dy->capacity=cap;
	dy->lastindex=-1;
	dy->ptr=malloc(sizeof(int) * cap);
	return dy;
}

void resize(struct Dyanamic * dy)
{
	int *temp;
	temp=(int *)malloc(sizeof(int) * dy->capacity*2);
	for(int i=0; i<=dy->lastindex; i++)
	{
		temp[i]=dy->ptr[i];
	}
	free(dy->ptr);
	dy->ptr=temp;
	dy->capacity*= 2;
}

void append(struct Dyanamic * dy, int data)
{

	if(dy->lastindex == dy-> capacity-1)
	{	
		resize(dy);
		append(dy,data);
	}
	else
	{
		dy->lastindex+= 1;
		dy->ptr[dy->lastindex]=data;
	}
}

void insert(struct Dyanamic *dy, int index, int data)
{

	if(index<0 || index> dy->lastindex+ 1)
	{
		printf("\nInvaid index");
	}
	
	else if(dy-> lastindex == dy-> capacity-1)
	{
		resize(dy);
		insert(dy,index,data);
	}
	else
	{
		for(int i=dy->lastindex; i>=index; i--)
		{
			dy->ptr[i+1] = dy->ptr[i];
		}
		dy->ptr[index]=data;
		dy->lastindex+= 1;
	}
}

int count(struct Dyanamic *dy)
{
	return dy->lastindex+1;
}

int getitem(struct Dyanamic *dy, int index)
{
	if(index>=0 && index<= dy-> lastindex)
	{
		return dy->ptr[index];
	}
	else{
		printf("\nInvalid");
		return -1;
	}
}

void edititem(struct Dyanamic *dy, int index,int data)
{
	if(index<0 || index> dy->lastindex)
	{
		printf("\nInvalid index");
	}
	else{
		dy->ptr[index]=data;
	}
}

void half(struct Dyanamic *dy)
{
	int *temp;
	temp=(int*)malloc(sizeof(int)* dy->capacity/2);
	for(int i=0; i<=dy->lastindex; i++)
	{
		temp[i]=dy->ptr[i];
	}
	free(dy->ptr);
	dy->ptr=temp;
	dy->capacity/= 2;
}


void delete(struct Dyanamic *dy, int index)
{
	if(index<0 || index> dy->lastindex)
	{
		printf("Invalid index\n");
	}
	else
	{
		for(int i=index; i<dy->lastindex; i++)
		{
			dy->ptr[i]=dy->ptr[i+1];
		}
		dy->lastindex-= 1;
	}
	if(dy->lastindex+1 == dy->capacity/2)
	{
		half(dy);
	}
	
}

void display(struct Dyanamic *dy)
{
	for(int i=0; i<=dy->lastindex; i++)
	{
		printf("%d ",dy->ptr[i]);
	}
	printf("\n");
}

void release(struct Dyanamic *dy)
{
	free(dy->ptr);
	free(dy);
}

int main()
{
	struct Dyanamic * d;
	d=createarray(4);
	insert(d,0,8);
	insert(d,1,12);
	insert(d,2,15);
	insert(d,3,17);
	display(d);
	printf("\n");
	insert(d,4,19);
	insert(d,5,21);
	insert(d,6,23);
	insert(d,7,28);
	display(d);

	int c=count(d);
	printf("No of items: %d\n", c);
	delete(d,2);
	delete(d,5);
	display(d);
	printf("Capacity: %d\n",d->capacity);
	release(d);
	return 0;
}