#include <stdio.h>
#include <stdlib.h>

struct Queue
{
	int capacity;
	int front, rear;
	int *ptr;
};

struct Queue *create(int cap)
{
	struct Queue *Q;
	Q=malloc(sizeof(struct Queue));
	Q->capacity=cap;
	Q->front=-1;
	Q->rear=-1;
	Q->ptr=malloc(sizeof(int)* cap);
	return Q;
}

void resize(struct Queue *Q)
{
	int *temp;
	Q->capacity=Q->capacity*2;

	temp=malloc(sizeof(int)* Q->capacity);
	for(int i=Q->front,j=0; i<=Q->rear; j++)
	{
		temp[j]=Q->ptr[i];
		if(i==Q->capacity/2-1 && Q->rear!=i)
			i=0;
		else
			i++;
	}	
	free(Q->ptr);
	Q->ptr=temp;
	Q->front=0;
	Q->rear=Q->capacity/2-1;
}

void insertion(struct Queue *Q, int data)
{
	if(Q->rear==-1)
	{
		Q->front=0;
		Q->rear=0;
		Q->ptr[Q->rear]=data;
	}
	else if(Q->front==0 && Q->rear== Q->capacity-1 || Q->rear== Q->front-1)
	{
		resize(Q);
		Q->rear+=1;
		Q->ptr[Q->rear]=data;
	}
	else if(Q->rear== Q->capacity-1)
	{
		Q->rear=0;
		Q->ptr[Q->rear]=data;
	}
	else
	{
		Q->rear+=1;
		Q->ptr[Q->rear]=data;
	}
}

void half(struct Queue *Q)
{
	int *temp,l;
	temp=malloc(sizeof(int)* Q->capacity/2);

	l=Q->capacity/2;
	for(int i=0,j=Q->front; i<l; i++)
	{
		temp[i]=Q->ptr[j];
		if(j== Q->capacity-1)
			j=0;
		else
			j++;
	}
	free(Q->ptr);
	Q->ptr=temp;
	Q->capacity=l;

	Q->front=0;
	Q->rear=Q->capacity-1;
}

void deletion(struct Queue *Q)
{
	int size=0;
	if(Q->front==-1)
	{
		printf("Underflow\n");
	}
	else if(Q->front== Q->rear)
	{
		Q->front=-1;
		Q->rear=-1;
	}
	else if(Q->front== Q->capacity-1)
	{
		Q->front=0;
	}
	else
	{
		Q->front+=1;
	}
	for(int i=Q->front; i!=Q->rear;)
	{
		size++;
		if(i==Q->capacity-1)
			i=0;
		else
			i++;
	}
	size++;
	if(size== Q->capacity/2) 
	{
		half(Q);
	}
}

void display(struct Queue *Q)
{
	if(Q->front==-1)
	{
		printf("Queue is empty\n");
	}
	else if(Q->rear>=Q->front)
	{
		for(int i=Q->front; i<=Q->rear; i++)
		{
			printf("%d ", Q->ptr[i]);
		}
	}
	else
	{
		for(int i=Q->front; i<Q->capacity; i++)
		{
			printf("%d ", Q->ptr[i]);
		}
		for(int i=0; i<=Q->rear; i++)
		{
			printf("%d ", Q->ptr[i]);
		}
	}
}

int menu()
{
	int choice;
	printf("\n1.Insertion in Queue: ");
	printf("\n2.Deletion in Queue: ");
	printf("\n3.Exit: ");
	printf("\nEnter your choice: ");
	scanf("%d",&choice);
	return choice;
}

int main()
{
	struct Queue *q;
	int size, data;
	printf("Enter capacity to create Queue: ");
	scanf("%d",&size);
	q=create(size);

	while(1)
	{
		system("cls");
		display(q);
		printf("\nCapacity: %d\n", q->capacity);
		printf("\nFront: %d  Rear: %d\n",q->front, q->rear);

		switch(menu())
		{
			case 1:
			printf("Enter value: ");
			scanf("%d",&data);
			insertion(q,data);
			break;
			case 2:
			deletion(q);
			break;
			case 3:
			exit(0);
			break;
			default:
			printf("Invalid choice\n");
			break;
		}
	}
	return 0;
}