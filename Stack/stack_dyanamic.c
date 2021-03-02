#include <stdio.h>
#include <stdlib.h>

struct stack
{
	int capacity;
	int top;
	int *ptr;
};

struct stack *create_stack(int cap)
{
	struct stack *s;
	s=malloc(sizeof(struct stack));
	s->capacity=cap;
	s->top=-1;
	s->ptr=malloc(sizeof(int)* cap);
	return s;
}

void resize(struct stack *s)
{
	int *temp;
	temp=malloc(sizeof(int)* s->capacity*2);

	for(int i=0; i<=s->top; i++)
	{
		temp[i]=s->ptr[i];
	}
	free(s->ptr);
	s->ptr=temp;
	s->capacity*=2;
}

void push(struct stack *s, int data)
{
	if(s->top == s->capacity-1)
	{
		resize(s);
		s->top+=1;
		s->ptr[s->top]=data;
	}
	else
	{
		s->top+= 1;
		s->ptr[s->top]=data;
	}
}

void half(struct stack *s)
{
	int *temp;
	temp=malloc(sizeof(int)* s->capacity/2);

	for(int i=0; i<=s->top; i++)
	{
		temp[i]=s->ptr[i];
	}
	free(s->ptr);
	s->ptr=temp;
	s->capacity/=2;
}

void pop(struct stack *s)
{
	if(s->top==-1)
	{
		printf("Underflow\n");
	}
	else
	{
		s->top-= 1;
	}
	if(s->top+1 == s->capacity/2)
	{
		half(s);
	}
}

void peek(struct stack *s)
{
	if(s->top==-1)
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("Top Element: %d\n",s->ptr[s->top]);
	}
}

int menu()
{
	int choice;
	printf("\n1.Enter PUSH to insert or append: ");
	printf("\n2.Enter POP to delete: ");
	printf("\n3.Exit: ");
	printf("\nEnter your choice: ");
	scanf("%d",&choice);
	return choice;
}

int main()
{
	/*struct stack *s1;
	s1=create_stack(2);
	push(s1,10);
	push(s1,20);
	push(s1,30);
	push(s1,40);

	pop(s1);
	pop(s1);
	peek(s1);
	printf("Capacity: %d\n",s1->capacity);*/

	struct stack *s1;
	int size,data;

	printf("Enter how many blocks to create: ");
	scanf("%d",&size);
	s1=create_stack(size);

	while(1)
	{
		system("cls");
		peek(s1);
		switch(menu())
		{
			case 1:
			printf("Enter value: ");
			scanf("%d",&data);
			push(s1,data);
			break;

			case 2:
			pop(s1);
			break;

			case 3:
			exit(0);
			break;
			default:
			printf("\nInvalid choice");
			break;
		}
	}
	return 0;
}