#include <stdio.h>
#include <stdlib.h>

struct node
{
	int item;
	struct node * prev;
	struct node * next;
};


/*void traverse(struct node **s)  // pass by ptr-to-ptr
{
	while(*s)
	{
		printf("%d ",(*s)->item);
		//*s=(*s)->prev;
		*s=(*s)->next;
	}
	printf("\n");
}*/


void traverse(struct node *start)
{
	while(start)
	{
		printf("%d ",start->item);
		start=start->prev;
		//start=start->next;
	}
	printf("\n");
}
int main()
{
	struct node * start, *second, *third;

	start=malloc(sizeof(struct node));
	second=malloc(sizeof(struct node));
	third=malloc(sizeof(struct node));

	start->item=9;
	start->prev=NULL;
	start->next=second;

	second->item= 11;
	second->prev=start;
	second->next=third;

	third->item=20;
	third->prev=second;
	third->next=NULL;

	traverse(third);
	//traverse(&start);
	return 0;
}