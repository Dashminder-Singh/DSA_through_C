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

int main()
{
	struct student s1[5];

	/*int index;
	index=hash_func(15);

	s1[index].rollno=15;
	printf("%d\n", s1[index].rollno);*/
	
	int index,x;

	printf("Enter Key: ");
	for(int i=0; i<5; i++)
	{
		scanf("%d",&x);
		index=hash_func(x);

		s1[index].rollno=x;
	}
	
	for(int i=0; i<5; i++)
	{
		printf("%d ",s1[i].rollno);
	}
	printf("\n");
	return 0;
}