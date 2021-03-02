#include <stdio.h>
#include <stdlib.h>

struct node
{
	int item;
	struct node *next;
};

struct node *detection_loop(struct node *start)
{
	struct node *slow,*fast;
	slow=fast=start;

	while(slow && fast && fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow == fast)
		{
			return fast;
		}
	}
	return NULL;
}

/*void detection_loop(struct node *start)
{
	struct node *slow,*fast;
	slow=fast=start;

	while(slow && fast && fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow == fast)
		{
			printf("Loop is Detected");
		}
	}
	printf("Not Detected");
}*/

int main()
{
	struct node *start, *second, * third, *fourth, *last;

	start=malloc(sizeof(struct node));
	second=malloc(sizeof(struct node));
	third=malloc(sizeof(struct node));
	fourth=malloc(sizeof(struct node));
	last=malloc(sizeof(struct node));

	start->item=10;
	start->next=second;

	second->item=20;
	second->next=third;

	third->item=30;
	third->next=fourth;

	fourth->item=40;
	fourth->next=last;

	last->item=50;
	last->next=second;

	//detection_loop(start);

	struct node * res;
	res=detection_loop(start);

	if(res!=NULL)
	{
		printf("Loop is found");	
	}
	else
	{
		printf("Doesn't have a Loop");
	}
	return 0;
}