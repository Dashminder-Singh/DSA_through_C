#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct stack
{	
	int capacity;
	int top;
	int  *arr;
};

struct stack * create(int cap)
{
	struct stack *s;
	s=(struct stack *)malloc(sizeof(struct stack));
	s->capacity=cap;
	s->top=-1;
	s->arr=(int *)malloc(sizeof(int) * cap);

	return s;
}

void push(struct stack *s, char data)
{
	if(s->top==s->capacity-1)
	{
		printf("Overflow\n");
	}
	else
	{
		s->top+=1;
		s->arr[s->top]=data;
	}
}

char pop(struct stack *s)
{
	char data;
	if(s->top==-1)
	{
		printf("Empty\n");
	}
	data=s->arr[s->top];
	s->top-=1;
	return data;
}

int evluate_post(char * P)
{
	struct stack *s;
	s=create(20);
	int i=0;

	int x, y;
	while(P[i]!='\0')
	{
		if(isdigit(P[i]))
		{
			push(s, P[i]- '0');
			i++;
		}
		else 
		{
			x=pop(s);
			y=pop(s);
			switch(P[i])
			{
				case '+': push(s, y+x);
				break;
				case '-': push(s, y-x);
				break;
				case '*': push(s, y*x);
				break;
				case '/': push(s, y/x);
				break;
			}
			i++;
		}
	}

	return pop(s);
}

int main()
{
	char *exp="2354-*+6+";

	printf("Evaluate: %d\n",evluate_post(exp));
	return 0;
}