#include <stdio.h>
#include <string.h>
struct student
{
	int rollno;
	char name[20];
};

int hash_func(int key)
{
	int index;
	index=key%5;
	return index;
}

int main()
{
	struct student s1[5];
	int index,x;

	char y[20];

	for(int i=0; i<5; i++)
	{
		printf("Enter rollno and name of %d: ",i+1);
		scanf("%d %s",&x,&y);
		index=hash_func(x);
		s1[index].rollno=x;
		strcpy(s1[index].name,y);
	}

	for(int i=0; i<5; i++)
	{
		printf("%d %s\n",s1[i].rollno,s1[i].name);
	}
	printf("\n");

	return 0;
}