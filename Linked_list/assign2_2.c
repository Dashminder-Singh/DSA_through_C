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

int loop_detected(struct node *start)
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
			return 1;
		}
	}
	return 0;
}
void traverse(struct node * start)
{
	while(start)
	{
		printf("%d ",start->item);
		start=start->next;
	}
	printf("\n");
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
	insert_last(&start,7);

	make_cycle(start,4);
	//traverse(start);

	if(loop_detected(start)!=1)
	{
		printf("Not Detected");
	}
	else{
		printf("Cycle is Detected");	
	}
	return 0;
}