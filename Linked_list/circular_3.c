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

	if(*l==NULL)
	{
		*l=n;
		(*l)->next=*l;
	}
	else
	{
		t=*l;
		n->next=t->next;
		t->next=n;
		*l=n;
	}
	
}

void insert_first(struct node **l, int data)
{
	struct node *n,*t;
	n=malloc(sizeof(struct node));
	n->item=data;

	if(*l==NULL)
	{
		*l=n;
		(*l)->next=*l;
	}
	else
	{
		t=*l;
		n->next=t->next;
		t->next=n;
	}
}

void insert_after(struct node **l, struct node *t, int data)
{
	struct node *n;
	n=malloc(sizeof(struct node));
	n->item=data;
	n->next=t->next;
	t->next=n;
	if(t==*l)
	{
		*l=n;
	}
}

void delete_first(struct node **l)
{
	struct node *r,*t;
	t=*l;
	r=(*l)->next;
	if(*l==NULL)
	{
		printf("Nothing to delete\n");
	}
	else if(*l==t->next)
	{
		*l=NULL;
		free(t);
	}
	else
	{
		t->next=r->next;
		free(r);
	}
}

void delete_last(struct node **l)
{
	struct node *r,*t;
	r=*l;
	t=(*l)->next;
	if(*l==NULL)
	{
		printf("Nothing to delete\n");
	}
	else if(*l==r->next)
	{
		*l=NULL;
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
		*l=t;
		free(r);
	}
}

void delete_particular(struct node **l, struct node *r)
{
	struct node *t;
	t=(*l)->next;
	if((*l)->next==r)
	{	
		(*l)->next=r->next;
	}
	else
	{
		do
		{
			t=t->next;
		}
		while(t->next!=r);
		t->next=r->next;
	}
	free(r);
}

struct node *search(struct node *last, int data)
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

void traverse(struct node **l)
{
	struct node *t;
	t=(*l)->next;

	if((*l)==NULL)
	{
		printf("Nothing to print\n");
	}
	else
	{
		do
		{
			printf("%d ", t->item);
			t=t->next;
		}
		while(t!=(*l)->next);
		printf("\n");
	}
}

int main()
{
	struct node *last;
	last=NULL;
	insert_first(&last,8);
	insert_first(&last,6);
	insert_last(&last,26);
	insert_last(&last,31);

	traverse(&last);
	
	struct node *s1;
	s1=search(last,8);
	//printf("%d ", s1->item);
	insert_after(&last,s1,15);
	s1=search(last,15);
	insert_after(&last,s1,19);
	traverse(&last);

	delete_first(&last);
	delete_last(&last);
	traverse(&last);

	struct node *s2;
	s2=search(last,15);
	delete_particular(&last,s2);
	traverse(&last); 
	return 0;
}