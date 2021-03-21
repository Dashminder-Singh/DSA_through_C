#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
	int rollno;
	char name[20];
	struct student *next;
};

int HF(int key)
{
	int index;
	index=key%5;
	return index;
}

void insert(struct student *s[], int data, char item[])
{
	struct student *n, *t;
	n=(struct student *)malloc(sizeof(struct student));
	n->rollno=data;
	strcpy(n->name, item);

	int index;
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
			printf("%d %s",t->rollno,t->name);
			t=t->next;
		}
		printf("\n");
	}
}

int main()
{
	struct student *start[5];

	for(int i=0; i<5; i++)
	{
		start[i]=NULL;
	}
	
	insert(start, 15, "Rohan");
	insert(start, 17, "ashu");
	insert(start, 19, "samar");
	display(start);

	return 0;
}