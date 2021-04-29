#include <stdio.h>
#include <stdlib.h>

struct node
{
	int item;
	int priority_no;
	struct node *next;
};

void insert(struct node **f, struct node **r, int data, int pr_no)
{
	struct node *n, *t1, *t2;
	n=(struct node *)malloc(sizeof(struct node));
	n->item=data;
	n->priority_no=pr_no;
	n->next=NULL;

	if(*r==NULL)
	{
		*f=n;
		*r=n;
	}
	else if((*f)->priority_no > n->priority_no)
	{
		n->next=*f;
		*f=n;
	}
	else if((*r)->priority_no <= n->priority_no)
	{
		(*r)->next=n;
		*r=n;
	}
	else
	{
		t1=*f;
		t2=NULL;

		while(t1!=NULL)
		{
			t2=t1;
			t1=t1->next;
			if(t2->priority_no <= n->priority_no  && t1->priority_no > n->priority_no)
			{
				n->next=t2->next;
				t2->next=n;
			}
		}
	}
}

void delete(struct node **f, struct node **r)
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

void traverse(struct node *front)
{
	if(front==NULL)
	{
		printf("Queue is empty\n");
	}
	else
	{
		while(front!=NULL)
		{
			printf("%d (%d)",front->item, front->priority_no);
			front=front->next;
			if(front!=NULL)
				printf(" -> ");
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
	front=rear=NULL;

	int data, pr;
	while(1)
	{
		system("cls");
		traverse(front);
		switch(menu())
		{
			case 1:
			printf("Enter value and pr_no: ");
			scanf("%d%d",&data, &pr);
			insert(&front, &rear, data, pr);
			break;

			case 2:
			delete(&front, &rear);
			break;

			case 3:
			exit(0);
			break;
			default:
			printf("invalid choice\n");
			break;
		}
	}
	return 0;
}
