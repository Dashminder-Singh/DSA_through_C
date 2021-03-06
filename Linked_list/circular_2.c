#include <stdio.h>
#include <stdlib.h>

struct node
{
	int item;
	struct node * next;
};

void insert_last(struct node **l, int data)
{
	struct node *n,*t;
	n=malloc(sizeof(struct node));
	n->item=data;
	t=*l;
	n->next=t->next;
	t->next=n;
	*l=n;
}

void insert_first(struct node **l, int data)
{
	struct node *n,*t;
	n=malloc(sizeof(struct node));
	n->item=data;
	t=*l;
	n->next=t->next;
	t->next=n;
}

void insert_after(struct node **l, struct node *t, int data)
{
	struct node *n;
	n=malloc(sizeof(struct node));
	n->item=data;
	n->next=t->next;
	t->next=n;
	if(t==*l)
		*l=n;
}

void delete_first(struct node **l)
{
	struct node *r,*t;
	t=*l;
	r=(*l)->next;
	t->next=r->next;
	free(r);
}

void delete_last(struct node **l)
{
	struct node *r,*t;
	t=(*l)->next;
	r=t->next;
	do
	{
		t=t->next;
		r=r->next;
	}
	while(r->next!=(*l)->next);
	t->next=r->next;
	*l=t;
	free(r);

}

void delete_particular(struct node **l, struct node *r)
{
	struct node *t;
	t=(*l)->next;

	if((*l)->next==r)
	{
		(*l)->next=r->next;
		free(r);
	}
	else
	{
		do
		{
			t=t->next;
		}
		while(t->next!=r);
		t->next=r->next;
		free(r);
	}
}

struct node* search(struct node *last, int data)
{
	struct node *t;
	t=last->next;
	do
	{
		if(t->item==data)
		{
			return t;
		}
		t=t->next;
	}
	while(t!=last->next);
	printf("%d is not found",data);
	printf("\n");
	return last;
}

void traverse(struct node *last)
{
	struct node *t;
	t=last->next;
	do
	{
		printf("%d ",t->item);
		t=t->next;
	}
	while(t!=last->next);
	printf("\n");
}

int main()
{
	struct node * start, *second, *third, *last;

	start=malloc(sizeof(struct node));
	second=malloc(sizeof(struct node));
	third=malloc(sizeof(struct node));
	last=malloc(sizeof(struct node));

	start->item=8;
	start->next=second;

	second->item=11;
	second->next=third;

	third->item=19;
	third->next=last;

	last->item=23;
	last->next=start;

	traverse(last);
	insert_last(&last, 26);
	insert_first(&last,6);
	
	traverse(last);

	struct node *s1;
	//printf("%d ",s1->item);
	s1=search(last,26);
	insert_after(&last,s1,31);

	traverse(last);

	delete_first(&last);
	delete_last(&last);
	traverse(last);

	struct node *s2;
	s2=search(last,8);
	delete_particular(&last,s2);
	traverse(last);
	return 0;
}