#include <stdio.h>
#include <stdlib.h>

struct ArrayADT
{
	int *ptr;
	int capacity;
	int lastindex;
};

struct ArrayADT * createArray(int cap)
{
	struct ArrayADT *arr;
	arr=malloc(sizeof(struct ArrayADT));
	arr->capacity=cap;
	arr->lastindex=-1;
	arr->ptr=malloc(sizeof(int) * cap);
	return arr;
}

void append(struct ArrayADT * arr, int data)
{
	if(arr->lastindex == arr-> capacity-1)
	{
		printf("\nOverflow");
	}
	else{
		arr->lastindex +=1;
		arr->ptr[arr->lastindex]=data;
	}
}

void insert(struct ArrayADT * arr, int index, int data)
{
	if(index<0 || index > arr->lastindex+1)
	{
		printf("\nInvalid index");
	}
	else if(arr->lastindex == arr->capacity-1){
		printf("\nOverflow");
	}
	else
	{
		for(int i=arr->lastindex; i>=index; i--)
		{
			arr->ptr[i+1]= arr->ptr[i];
		}
		arr->ptr[index]=data;
		arr->lastindex= arr->lastindex +1;
	}
}

int count(struct ArrayADT *arr)
{
	return arr->lastindex+1;
}

int getitem(struct ArrayADT * arr, int index)
{
	if(index>=0 && index<=arr->lastindex)
	{
		return arr->ptr[index];
	}
	else{
		printf("\nInvalid index");
		return -1;
	}
}

void edititem(struct ArrayADT *arr, int index, int data)
{
	if(index<0 || index> arr->lastindex)
	{
		printf("\nInvalid index");
	}
	else{
		arr->ptr[index]=data;
	}
}

void delete(struct ArrayADT *arr, int index)
{
	if(index<0 || index> arr->lastindex)
	{
		printf("\nInvalid index");
	}
	else{
		for(int i=index; i<arr->lastindex; i++)
		{
			arr->ptr[i]= arr->ptr[i+1];
		}
		arr->lastindex -=1;
	}
}

void search(struct ArrayADT *arr, int data)
{
	int flag=1;
	for(int i=0; i<=arr->lastindex; i++)
	{
		if(data==arr->ptr[i])
		{
			printf("Search successful at : %d\n", i);
			flag=0;
		}
	}
	if(flag==1)
		printf("Search Unsuccessful\n");
}

void release(struct ArrayADT *arr)
{
	free(arr->ptr);
	free(arr);
}

void display(struct ArrayADT *arr)
{
	for(int i=0; i<=arr->lastindex; i++)
	{
		printf("%d ",arr->ptr[i]);
	}
	printf("\n");
}

int main()
{
	struct ArrayADT *a;
	a=createArray(6);
	insert(a,0,10);
	insert(a,1,20);
	insert(a,2,30);
	insert(a,3,35);
	insert(a,4,40);
	insert(a,5,45);

	display(a);
	int d=count(a);
	printf("No.of items: %d\n", d);
	printf("\n");

	int item=getitem(a,2);
	printf("Item: %d\n",item);
	printf("\n");

	edititem(a,5,50);
	display(a);
	search(a,20);

	printf("\n");
	delete(a,5);
	delete(a,0);
	delete(a,1);
	display(a);
	int e=count(a);
	printf("No.of items: %d\n", e);
	printf("capacity: %d\n",a->capacity);
	printf("\n");

	insert(a,1,12);
	display(a);
	int c=count(a);
	printf("No.of items: %d\n", c);
	printf("\n");
	release(a);

	/*insert(a,0,10);
	insert(a,1,20);
	insert(a,2,30);
	insert(a,3,35);
	//insert(a,5,45);
	append(a,60);  Not overflow, Capactiy=6, 6 or more->overflow
	insert(a,4,40);

	display(a);*/

	return 0;
}