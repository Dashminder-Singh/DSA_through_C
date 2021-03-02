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
	if(s->top+1 == s->capacity)
	{
		printf("Overflow\n");
	}
	else
	{
		s->top+= 1;
		s->ptr[s->top]=data;
	}
}

int pop(struct stack *s)
{
	int data;
	if(s->top == -1)
	{
		printf("Underflow\n");
		return -1;
	}
	data=s->ptr[s->top];
	s->top-= 1;
	return data;
}

void peek(struct stack *s)
{
	if(s->top == -1)
	{
		printf("Stack is Empty\n");
	}
	else
	{
		printf("Top Element: %d\n",s->ptr[s->top]);
	}
}

int main()
{
	struct stack *s1;
	s1=create_stack(4);
	
	push(s1,10);
	push(s1,20);
	push(s1,30);

	peek(s1);
	int data=pop(s1);
	printf("%d is Deleted\n",data);
	peek(s1);

	return 0;
}