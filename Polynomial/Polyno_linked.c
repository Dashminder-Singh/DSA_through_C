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

void traverse(struct node *start)
{
	while(start!=NULL)
	{
		printf("%dx^%d",start->c, start->e);
		start=start->next;
		if(start!=NULL)
			printf("+ ");
	}
	printf("\n");
}

int main()
{
	struct node * start;
	start=NULL;

	insert_last(&start,2,2);
	insert_last(&start,4,1);
	insert_last(&start,7,0);
	traverse(start);
	return 0;
}