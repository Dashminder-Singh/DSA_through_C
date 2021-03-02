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
		printf("Overflow\n");
	}
	else if(Q->rear== Q->capacity-1 && Q->front!=0)
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

void deletion(struct Queue *Q)
{
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
}

void display(struct Queue *Q)
{
	if(Q->front== -1)
	{
		printf("Queue is empty\n");
	}

	else if(Q->rear>=Q->front)
	{
		for(int i=Q->front; i<=Q->rear; i++)
		{
			printf("%d ", Q->ptr[i]);
		}
		printf("\n");
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
		printf("\n");
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
	/*struct Queue *q;
	q=create(4);
	insertion(q,10);
	insertion(q,20);
	insertion(q,30);
	insertion(q,40);
	
	deletion(q);
	deletion(q);
	insertion(q,60);

	display(q);*/

	struct Queue *q;
	int size, data;
	printf("Enter capacity to create Queue: ");
	scanf("%d",&size);
	q=create(size);

	while(1)
	{
		system("cls");
		display(q);
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
