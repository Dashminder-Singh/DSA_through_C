#include <stdio.h>
#include <stdlib.h>

struct node
{
	int item;
	struct node * next;
};

void traversal(struct node *t)
{
	while(t!=NULL)
	{
		printf("%d ",t->item);
		t=t->next;
	}
	printf("\n");
}

void insert_first(struct node **s,int data)
{
	struct node *n;
	n=malloc(sizeof(struct node));
	n->item=data;
	n->next=*s;
	*s=n;
}

/*struct node *insert_index(struct node *s, int data, int index)
{
	struct node *n,*t;
	n=malloc(sizeof(struct node));
	n->item=data;

	int i=0;
	t=s;
	while(i!=index-1)
	{
		t=t->next;
		i++;
	}
	n->next=t->next;
	t->next=n;
	return s;
}*/

void insert_index(struct node **s, int data, int index)
{
	struct node *n,*t;
	n=malloc(sizeof(struct node));
	n->item=data;

	int i=0;
	t=*s;
	while(i!=index-1)
	{
		t=t->next;
		i++;
	}
	n->next=t->next;
	t->next=n;
}

void insert_last(struct node **s, int data)
{
	struct node *n,*t;
	n=malloc(sizeof(struct node));
	n->item=data;
	n->next=NULL;

	t=*s;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next=n;
}

void insert_after(struct node *t,int data)
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
	*s=r->next;
	free(r);
}

void delete_index(struct node **s, int index)
{
	struct node *r, *t;
	t=*s;
	r=(*s)->next;
	int i=0;
	while(i!= index-1)
	{
		t=t->next;
		r=r->next;
		i++;
	}
	t->next=r->next;
	free(r);
}

void delete_last(struct node **s)
{
	struct node *r, *t;
	t=*s;
	r=(*s)->next;

	while(r->next!=NULL)
	{
		t=t->next;
		r=r->next;
	}
	t->next=NULL;
	free(r);
}

/*void delete_particular(struct node **s, struct node *r)
{
	struct node *t;
	t=*s;
	while(t->next!=r)
	{
		t=t->next;
	}
	t->next=r->next;
	free(r);
}*/

void delete_particular(struct node **s, int data)
{
	struct node *t, *r;
	t=*s;
	r=(*s)->next;
	while(r->next!=NULL && r->item!=data)
	{
		t=t->next;
		r=r->next;
	}

	if(r->item==data)
	{
		t->next=r->next;
		free(r);
	}
}


int main()
{
	struct node * start, *second, *third, *fourth;
	start= malloc(sizeof(struct node));
	second= malloc(sizeof(struct node));
	third= malloc(sizeof(struct node));
	fourth= malloc(sizeof(struct node));

	start->item=7;
	start->next=second;

	second->item=11;
	second->next=third;

	third->item=22;
	third->next=fourth;

	fourth->item=31;
	fourth->next=NULL;

	traversal(start);
	//insert_first(&start,9);  // pass by address
	//start=insert_index(start,15,3);  // pass by value

	//insert_index(&start, 15, 1);
	//insert_last(&start,36);
	//insert_after(second,88);
	//delete_first(&start);
	//delete_index(&start,1);
	//delete_last(&start);
	delete_particular(&start,11);
	//delete_particular(&start,third);
	traversal(start);

	return 0;
}