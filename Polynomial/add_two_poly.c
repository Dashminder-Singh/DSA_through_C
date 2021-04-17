#include <stdio.h>
#include <stdlib.h>

struct node
{
	int c;
	int e;
	struct node *next;
};

void insert_last(struct node **s, int coff, int exp)
{
	struct node *n, *t;
	n=(struct node *)malloc(sizeof(struct node));
	n->c=coff;
	n->e=exp;
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

struct node *add_two(struct node *s1, struct node *s2)
{
	struct node *start;
	start=NULL;

	while(s1!=NULL && s2!=NULL)
	{
		if(s1->e> s2->e)
		{
			insert_last(&start,s1->c,s1->e);
			s1=s1->next;
		}
		else if(s1->e== s2->e)
		{
			insert_last(&start, s1->c + s2->c, s1->e);
			s1=s1->next;
			s2=s2->next;
		}
		else
		{
			insert_last(&start, s2->c, s2->e);
			s2=s2->next;
		}
	}

	while(s1!=NULL)
	{
		insert_last(&start,s1->c, s1->e);
		s1=s1->next;
	}

	while(s2!=NULL)
	{
		insert_last(&start,s2->c, s2->e);
		s2=s2->next;
	}
	
	return start;
}

void traverse(struct node *start)
{
	while(start!=NULL)
	{
		printf("%dX^%d",start->c, start->e);
		start=start->next;
		if(start!=NULL)
			printf("+ ");
	}
	printf("\n");
}

int main()
{
	struct node * first, *second, *result;
	first=second=result=NULL;

	insert_last(&first, 5, 3);
	insert_last(&first, 4, 2);
	insert_last(&first, 2, 1);

	printf("\nfirst poly: ");
	traverse(first);

	insert_last(&second, 7, 4);
	insert_last(&second, 6, 3);
	insert_last(&second, 1, 2);

	printf("\nsecond poly: ");
	traverse(second);

	result=add_two(first, second);
	printf("\naddtion of two poly: ");
	traverse(result);

	return 0;
}