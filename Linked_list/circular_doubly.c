#include <stdio.h>
#include <stdlib.h>
struct node
{
	int item;
	struct node *next;
	struct node *prev;
};

void traverse(struct node *start)
{
	struct node *t;
	t=start;
	do
	{
		printf("%d ",t->item);
		t=t->next;
	}
	while(t!=start);
	printf("\n");
}

int main()
{
	struct node *start, *second, *last;

	start=malloc(sizeof(struct node));
	second=malloc(sizeof(struct node));
	last=malloc(sizeof(struct node));

	start->item=8;
	start->next=second;
	start->prev=last;

	second->item=11;
	second->next=last;
	second->prev=start;

	last->item=15;
	last->next=start;
	last->prev=second;

	traverse(start);

	return 0;
}