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

void traverse(struct node *start)
{
	while(start)
	{
		printf("%d ",start->item);
		start=start->next;
	}
	printf("\n");
}

int count_node(struct node *start)
{
	struct node *t;
	t=start;
	int count=1;
	while(t->next!=start)
	{
		t=t->next;
		count++;
	}
	return count;
}

int cycle(struct node *start)
{
	struct node *slow, *fast;
	slow=start;
	fast=start;

	while(slow && fast && fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow == fast)
		{
			  return count_node(slow);
		}
	}
	return 0;
}

void make_cycle(struct node *start, int position)
{
	struct node *new;
	int count=1;
	while(start->next!=NULL)
	{
		if(count == position)
		{
			new=start;
		}
		count++;
		start=start->next;
	}
	start->next=new;
}

int main()
{
	struct node *start;
	start=NULL;

	insert_last(&start,1);
	insert_last(&start,2);
	insert_last(&start,3);
	insert_last(&start,4);
	insert_last(&start,5);
	insert_last(&start,6);

	make_cycle(start,3);
	//traverse(start);

	int c=cycle(start);

	if(c==0)
		printf("Not Detected");
	else
		printf("Nodes: %d",c);
	return 0;
}