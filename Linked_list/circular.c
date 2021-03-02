#include <stdio.h>
#include <stdlib.h>

struct node
{
	int item;
	struct node *next;
};

/*
void traverse(struct node *start)
{
	struct node *t;
	t=start;
	while(t->next!=start)
	{
		printf("%d ",t->item);
		t=t->next;
	}
	printf("%d ",t->item);
	printf("\n");
}*/

void traverse(struct node *start)
{
	struct node *t;
	t=start;
	do{
		printf("%d ", t->item);
		t=t->next;
	}
	while(t!=start);
	printf("\n");
}

void insert_first(struct node **s, int data)
{
	struct node *n,*t;
	n=malloc(sizeof(struct node));
	n->item=data;
	t=*s;
	while(t->next!=*s)
	{
		t=t->next;
	}

	n->next=t->next;  //n->next=*s; (same as last node point first node)
	t->next=n;
	*s=n;
}

void insert_last(struct node **s, int data)
{
	struct node *n,*t;
	n=malloc(sizeof(struct node));
	n->item=data;
	t=*s;
	while(t->next!=*s)
	{
		t=t->next;
	}
	n->next=*s;
	t->next=n;
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
	struct node *r,*t;
	t=r=*s;
	while(t->next!=*s)
	{
		t=t->next;
	}
	t->next=r->next;
	*s=r->next;
	free(r);
}

void delete_last(struct node **s)
{
	struct node *t,*r;
	t=*s;
	r=(*s)->next;
	while(r->next!=*s)
	{
		t=t->next;
		r=r->next;
	}
	t->next=*s;
	free(r);
}

void delete_particular(struct node **s, struct node *r)
{
	struct node *t;
	t=*s;

	if(*s==r)
	{
		while(t->next!=*s)
		{
			t=t->next;
		}
		t->next=r->next;
		*s=r->next;
		free(r);
	}
	else
	{
		while(t->next!=r)
		{
			t=t->next;
		}
		t->next=r->next;
		free(r);
	}
}

/*
struct node *search(struct node *start, int data)
{
	struct node *t;
	t=start;
	while(t->next!=start)
	{
		if(t->item== data)
		{
			return t;
		}
		t=t->next;
	}
	return start;
}*/

struct node *search(struct node *start, int data)
{
	struct node *t;
	t=start;
	do{
		if(t->item== data)
		{
			return t;
		}
		t=t->next;
	}
	while(t!=start);
	return start;
}

int main()
{
	struct node *start, *second, *third, *last;

	start=malloc(sizeof(struct node));
	second=malloc(sizeof(struct node));
	third=malloc(sizeof(struct node));
	last=malloc(sizeof(struct node));

	start->item=8;
	start->next=second;

	second->item=11;
	second->next=third;

	third->item=21;
	third->next=last;

	last->item=26;
	last->next=start;

	traverse(start);
	insert_first(&start, 6);
	insert_last(&start,32);
	
	traverse(start);
	
	struct node *s1;
	s1=search(start,11);
	insert_after(s1,15);
	traverse(start);


	struct node *s2;
	s2=search(start,8);
	delete_particular(&start,s2);
	traverse(start);

	delete_first(&start);
	delete_last(&start);
	traverse(start);
	return 0;
}