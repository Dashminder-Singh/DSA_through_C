#include <stdio.h>
#include <stdlib.h>

struct node
{
	int item;
	struct node *next;
};

void insertion(struct node **f, struct node **r, int data)
{
	struct node *n;
	n=malloc(sizeof(struct node));
	n->item=data;
	n->next=NULL;

	if(*f==NULL)
	{
		*f=n;
		*r=n;
	}
	else
	{
		(*r)->next=n;
		*r=n;
	}
}

void deletion(struct node **f, struct node **r)
{
	struct node *q;

	if((*f)->next==NULL)
	{
		*f=NULL;
		*r=NULL;
		free(*f);
	}
	else
	{
		q=*f;
		*f=q->next;
		free(q);
	}
}

void traverse(struct node **f, struct node **r)
{
	struct node *t;

	if(*f==NULL)
	{
		printf("Queue is empty\n");
	}
	else
	{
		t=*f;
		while(t!=NULL)
		{
			printf("%d ",t->item);
			t=t->next;
		}
		printf("\n");
	}
}

int menu()
{
	int choice;
	printf("\n1. Insertion");
	printf("\n2. Deletion");
	printf("\n3. Exit");
	printf("\nEnter your choice: ");
	scanf("%d",&choice);
	return choice;
}

int main()
{
	struct node *front, *rear;
	front=NULL;
	rear=NULL;

	int data;
	while(1)
	{
		system("cls");
		traverse(&front, &rear);
		switch(menu())
		{
			case 1:
			printf("Enter value: ");
			scanf("%d",&data);
			insertion(&front, &rear, data);
			break;

			case 2:
			deletion(&front, &rear);
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

/*struct node *front, *rear;
	front=NULL;
	rear=NULL;

	insertion(&front, &rear, 10);
	insertion(&front, &rear, 20);
	insertion(&front, &rear, 30);

	deletion(&front, &rear);

	traverse(&front, &rear);*/
