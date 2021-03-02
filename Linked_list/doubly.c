#include <stdio.h>
#include <stdlib.h>

struct node
{
	int item;
	struct node *next;
	struct node *prev;
};

void insert_last(struct node **s, int data)
{
	struct node *n, *t;
	n=malloc(sizeof(struct node));
	n->item=data;
	n->next=NULL;

	if(*s==NULL)
	{
		n->prev=NULL;
		*s=n;
	}
	else
	{
		t=*s;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		n->prev=t;
		t->next=n;
	}
}

void insert_first(struct node **s, int data)
{
	struct node *n;
	n=malloc(sizeof(struct node));
	n->item=data;
	n->prev=NULL;
	n->next=*s;

	if(*s!=NULL)
	{
		(*s)->prev=n;
	}
	*s=n;
}

void insert_after(struct node *t, int data)
{
	struct node *n;
	n=malloc(sizeof(struct node));
	n->item=data;
	n->next=t->next;
	n->prev=t;
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
		r->next->prev=NULL;
		//*s=r->next;
		*s=(*s)->next;
		free(r);
	}
}
/*
void delete_last(struct node **s)
{
	struct node *t;
	if((*s)->next==NULL)
	{
			free(*s);
			*s=NULL;
	}
	else
	{
		t=*s;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->prev->next=NULL;
		free(t);
	}
}*/

void delete_last(struct node **s)
{
	struct node *t,*r;
	t=*s;
	r=(*s)->next;
	if(*s==NULL)
	{
		printf("Nothing to delete\n");
	}
	else
	{
		while(r->next!= NULL)
		{
			t=t->next;
			r=r->next;
		}
		t->next=NULL;
		free(r);
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

struct node *search(struct node *start, int data)
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
	while(t)
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
	insert_last(&start,60);


	struct node *s1;
	s1=search(start,10);
	insert_after(s1,20);

	s1=search(start,20);
	insert_after(s1,30);

	display(&start);
	
	delete_last(&start);
	delete_last(&start);

	display(&start);
	struct node *s2;
	s2=search(start,20);
	delete_particular(&start,s2);
	display(&start);

	insert_first(&start,8);
	insert_last(&start, 19);
	display(&start);
	delete_first(&start);
	display(&start);

	return 0;
}