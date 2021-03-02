#include <stdio.h>
#include <stdlib.h>

struct node
{
	int item;
	struct node *next;
};

void insert_last(struct node **s, int data)
{
	struct node *n,*t;
	n=malloc(sizeof(struct node));
	n->item=data;
	n->next=NULL;

	if(*s==NULL)
	{
		*s=n;
	}
	else
	{
		t=*s;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=n;
	}
}

struct node *reverse(struct node **s)
{
	struct node *t1, *t2;
	t1=t2=NULL;

	while(*s!=NULL)
	{
		t2=(*s)->next;
		(*s)->next=t1;
		t1=*s;
		*s=t2;
	}
	return t1;
}

void traverse(struct node * start)
{
	while(start)
	{
		printf("%d ",start->item);
		start=start->next;
	}
	printf("\n");
}

int main()
{
	struct node *start;
	start=NULL;

	int n,value;
	printf("Enter how many values: ");
	scanf("%d",&n);

	for(int i=1; i<=n; i++)
	{
		printf("Enter the  %d value: ",i);
		scanf("%d",&value);
		insert_last(&start,value);
	}
	traverse(start);
	printf("\n");

	start=reverse(&start);
	traverse(start); //new start
	return 0;
}