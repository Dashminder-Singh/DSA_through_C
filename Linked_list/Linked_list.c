#include <stdio.h>
#include <stdlib.h>

struct node
{
	int item;
	struct node *next;
};

void insert_last(struct node **s, int data)
{
	struct node *n, *t;
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

void insert_first(struct node **s, int data)
{
	struct node *n;
	n=malloc(sizeof(struct node));
	n->item= data;
	n->next= *s;
	*s=n;
}

void insert_after(struct node *t, int data)
{
	struct node *n;
	n=malloc(sizeof(struct node));
	n->item= data;
	n->next= t->next;
	t->next=n;
}

void delete_first(struct node **s)
{
	struct node *r;
	if(*s==NULL)
	{
		printf("Nothing to delete\n");
	}
	else 
	{
		r=*s;
		*s=r->next;
		free(r);
	}
}

void delete_last(struct node **s)
{
	struct node *t1, *t2;

	if(*s==NULL)
	{
		printf("Nothing to delete\n");
	}
	else
	{
		t1=*s;
		t2=NULL;
		while(t1->next!=NULL)
		{
			t2=t1;
			t1=t1->next;
		}
		if(t2!=NULL)
		{
			t2->next=NULL;
		}
		else
		{
			*s=NULL;
		}
		free(t1);
	}
}

void delete_particular(struct node **s, struct node *r)
{
	struct node *t;

	if(*s==r)
	{
		*s=r->next;
	}
	else
	{
		t=*s;
		while(t->next!=r)
		{
			t=t->next;
		}
		t->next=r->next;
	}
	free(r);
}

struct node *search(struct node *start, int data)  // pass by value
{
	while(start)
	{
		if(start->item==data)
		{
			return start;
		}
		start=start->next;
	}
	return NULL;
}

void display(struct node **s)
{
	struct node *t;
	t=*s;
	while(t!=NULL)
	{
		printf("%d ",t->item);
		t=t->next;
	}
	printf("\n");
}

int main()
{
	struct node * start;
	start=NULL;

	insert_first(&start,10);
	insert_last(&start,60);  		// pass by address
	display(&start);


	struct node *s1;
	s1=search(start,10);
	insert_after(s1,20);

	s1=search(start,20);
	insert_after(s1,30);

	s1=search(start,30);
	insert_after(s1,40);

	s1=search(start,40);
	insert_after(s1,50);

	s1=search(start,60);
	insert_after(s1,70);

	display(&start);



	struct node *s2;
	s2=search(start,30);
	delete_particular(&start,s2);

	display(&start); 


	delete_first(&start);
	delete_last(&start);
	display(&start); 

	delete_first(&start);
	delete_last(&start);
	display(&start);
	return 0;
}