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
	s->ptr=malloc(sizeof(int) * cap);

	return s;
}

void push(struct stack *s, int data)
{
	if(s->top+1==s->capacity)
	{
		printf("Overflow\n");
	}
	else
	{
		s->top+= 1;
		s->ptr[s->top]=data;
	}
}

void pop(struct stack *s)
{
	if(s->top == -1)
	{
		printf("Underflow\n");
	}
	else
	{
		s->top-= 1;
	}
}

void peek(struct stack *s)
{
	if(s->top == -1)
	{
		printf("Stack is Empty\n");
	}
	else
	{
		printf("\nTop Element: %d\n",s->ptr[s->top]);
	}
}

int menu()
{
	int choice;
	printf("\n1.Enter PUSH to insert or append");
	printf("\n2.Enter POP to delete");
	printf("\n3.Exit");
	printf("\nEnter your choice: ");
	scanf("%d",&choice);
	return choice;
}

int main()
{
	struct stack *s1;
	int capacity, data;

	printf("Enter how many blocks to Create: ");
	scanf("%d",&capacity);
	s1=create_stack(capacity);

	while(1)
	{
		peek(s1);
		switch(menu())
		{
			case 1:
			printf("Enter value to append: ");
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
			printf("Invalid choice\n");
			break;
		}
	}
	return 0;
}