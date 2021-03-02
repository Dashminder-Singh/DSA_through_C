#include <stdio.h>
#include <stdlib.h>

struct node
{
	int item;
	struct node *next;
	struct node *prev;
};

void insert_last(struct node **s,int data)
{
	struct node *n;
	n=malloc(sizeof(struct node));
	n->item=data;
	
	if(*s==NULL)
	{
		*s=n;
		(*s)->next=*s;
		(*s)->prev=*s;
	}
	else
	{
		n->next=*s;
		n->prev=(*s)->prev;
		(*s)->prev->next=n;
		(*s)->prev=n;
	}
}

void insert_first(struct node **s, int data)
{
	struct node *n;
	n=malloc(sizeof(struct node));
	n->item=data;
	
	if(*s==NULL)
	{
		*s=n;
		(*s)->next=*s;
		(*s)->prev=*s;
	}
	else
	{
		n->next=*s;
		n->prev=(*s)->prev;
		(*s)->prev->next=n;
		(*s)->prev=n;
		*s=n;
	}
}

void insert_after(struct node *t, int data)
{
	struct node *n;
	n=malloc(sizeof(struct node));
	n->item=data;
	n->next=t->next;
	t->next=n;
}

void delete_first(struct node **s)
{
	struct node *r;
	r=*s;
	if(*s==NULL)
	{
		printf("Nothing to delete\n");
	}
	else if(*s==r->next)
	{
		*s=NULL;
		free(r);
	}
	else
	{	
		(*s)->prev->next=r->next;
		r->next->prev=(*s)->prev;
		*s=r->next;
		free(r);
	}
}

void delete_last(struct node **s)
{
	struct node *r,*t;
	t=*s;
	r=(*s)->prev;

	if(*s==NULL)
	{
		printf("Nothing to delete\n");
	}
	else if(*s==t->next)
	{
		*s=NULL;
		free(t);
	}
	else
	{
		do
		{
			t=t->next;
		}
		while(t->next!=r);
		(*s)->prev=t;
		t->next=r->next;
		r->prev->next=*s;
		free(r);
	}
}


/*void delete_last(struct node **s)  // Both are same ^ results
{
	struct node *r,*t;
	t=*s;
	r=(*s)->next;

	if(*s==NULL)
	{
		printf("Nothing to delete\n");
	}
	else if(*s==t->next)
	{
		*s=NULL;
		free(t);
	}
	else
	{
		do
		{
			t=t->next;
			r=r->next;
		}
		while(r->next!=*s);
		t->next=r->next;
		free(r);
	}
}*/

void delete_particular(struct node **s, struct node *r)
{
	struct node *t;
	t=*s;

	if(*s==r)
	{
		*s=r->next;
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

struct node * search(struct node *start, int data)
{
	struct node *t;
	t=start;
	do
	{
		if(t->item == data)
		{
			return t;
		}
		t=t->next;
	}
	while(t!=start);
	printf("%d is not found",data);
	printf("\n");
	return start;
}

void traverse(struct node **s)
{
	struct node *t;
	t=*s;
	do
	{
		printf("%d ",t->item);
		t=t->next;
	}
	while(t!=*s);
	printf("\n");
}

int main()
{
	struct node *start;
	start=NULL;

	insert_last(&start,28);
	insert_last(&start,36);
	insert_first(&start,10);
	insert_first(&start,8);
	traverse(&start);

	struct node *s1;
	s1=search(start,10);
	insert_after(s1,15);
	traverse(&start);

	struct node *s2;
	s2=search(start,15);
	delete_particular(&start,s2);
	traverse(&start);

	delete_first(&start);
	delete_last(&start);
	traverse(&start);
	return 0;
}