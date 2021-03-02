#include <stdio.h>
#include <stdlib.h>

struct node
{
	int item;
	struct node *next;
};

void reverse(struct node **s)
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
	struct node *start, *second, * third, *last;

	start=malloc(sizeof(struct node));
	second=malloc(sizeof(struct node));
	third=malloc(sizeof(struct node));
	last=malloc(sizeof(struct node));

	start->item=10;
	start->next=second;

	second->item=20;
	second->next=third;

	third->item=30;
	third->next=last;

	last->item=40;
	last->next=NULL;

	traverse(start);
	reverse(&start);
	traverse(last);
	return 0;
}