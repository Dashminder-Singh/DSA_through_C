#include <stdio.h>
#include <stdlib.h>

struct student
{
	int rollno;
	struct student *next;
};

int HF(int key)
{
	int index;
	index=key%5;
	return index;
}

void insert(struct student *s[], int data)
{
	struct student *n, *t;

	int index;
	n=malloc(sizeof(struct student));
	n->rollno=data;
	n->next=NULL;

	index=HF(data);

	if(s[index]==NULL)
	{
		s[index]=n;
	}
	else
	{
		t=s[index];
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=n;
	}
}

void display(struct student *start[])
{
	struct student *t;
	for(int i=0; i<5; i++)
	{
		t=start[i];
		printf("[%d] ",i);
		while(t)
		{
			printf("%d ",t->rollno);
			t=t->next;
		}
		printf("\n");
	}
}

struct student *search(struct student *start[], int data)
{
	struct student *t;
	for(int i=0; i<5; i++)
	{
		t=start[i];
		while(t)
		{
			if(t->rollno== data)
				return t;
			t=t->next;
		}
	}
	return NULL;
}

int main()
{
	struct student *start[5];

	for(int i=0; i<5; i++)
	{
		start[i]=NULL;
	}
	insert(start,15);
	insert(start,16);
	insert(start,17);
	insert(start,18);
	insert(start,23);
	insert(start,21);

	display(start);

	struct student *s1;
	s1=search(start,19);
	if(s1!=NULL)
		printf("%d is found\n",s1->rollno);
	else
		printf("Not found\n");
	return 0;
}