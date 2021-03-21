#include <stdio.h>

struct student
{
	int rollno;
};

int hash_func(int key)
{
	int index;
	index=key%5;
	return index;
}

void insert(struct student s[], int index, int data)
{
	s[index].rollno=data;
}

void search(struct student s[], int index, int data)
{
	if(s[index].rollno==data)
		printf("%d is found\n",s[index].rollno);
	else
		printf("Not found\n");
}

void delete(struct student s[], int index, int data)
{
	if(s[index].rollno==data)
		s[index].rollno=-1;
	else
		printf("%d Not found\n",data);
}

void display(struct student s[])
{
	for(int i=0; i<5; i++)
	{
		printf("%d ",s[i].rollno);
	}
	printf("\n");
}

int main()
{
	struct student s1[5];

	int index,a,b,c;

	printf("Enter Key: ");
	for(int i=0; i<5; i++)
	{
		scanf("%d",&a);
		index=hash_func(a);
		insert(s1,index,a);
	}
	display(s1);

	printf("\nEnter value to search: ");
	scanf("%d",&b);
	index=hash_func(b);
	search(s1,index,b);

	printf("\nEnter value to delete: ");
	scanf("%d",&c);
	index=hash_func(c);
	delete(s1,index,c);

	display(s1);
	return 0;
}

/*int index;
	index=hash_func(15);

	s1[index].rollno=15;
	printf("%d\n", s1[index].rollno);
	
	int index,x;

	printf("Enter Key: ");
	for(int i=0; i<5; i++)
	{
		scanf("%d",&x);
		index=hash_func(x);

		s1[index].rollno=x;
	}
	*/
