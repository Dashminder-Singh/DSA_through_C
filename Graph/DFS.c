#include <stdio.h>
#include <stdlib.h>
#define Ready 1
#define Waiting 2
#define Processed 3

struct stack
{
	int capacity;
	int top;
	int *arr;
};

struct node
{
	int v_no;
	struct node *next;
};

struct Graph
{
	int V;
	struct node **adj;
	int *status;
};

struct stack * create_stack(int cap)
{
	struct stack *s;
	s=(struct stack *)malloc(sizeof(struct stack));
	s->capacity=cap;
	s->top=-1;
	s->arr=malloc(sizeof(int) * cap);
	return s;
}

struct Graph * Create_graph(int v_count, int e)
{
	int u, v;
	struct Graph *G;
	G=(struct Graph *)malloc(sizeof(struct Graph));
	G->V=v_count;

	G->adj=(struct node **)malloc(sizeof(struct node *)* (G->V));
	G->status=(int *)malloc(sizeof(int)* (G->V));

	for(int i=0; i<v_count; i++)
	{
		G->adj[i]=NULL;
		G->status[i]=-1;
	}

	for(int i=0; i<e; i++)
	{
		printf("Enter edges %d: ",i);
		scanf("%d%d",&u,&v);

		struct node *n;
		n=(struct node *)malloc(sizeof(struct node));
		n->v_no=v;
		n->next=G->adj[u-1];
		G->adj[u-1]=n;

		n=(struct node *)malloc(sizeof(struct node));
		n->v_no=u;
		n->next=G->adj[v-1];
		G->adj[v-1]=n;
	}
	return G;
}

void push(struct stack *s, int data)
{
	if(s->top==-1)
	{
		s->top=0;
		s->arr[s->top]=data;
	}
	else if(s->top== s->capacity-1)
	{
		printf("overflow\n");
	}
	else
	{
		s->top+=1;
		s->arr[s->top]=data;
	}
}

int pop(struct stack *s)
{
	int data;
	if(s->top==-1)
	{
		printf("underflow\n");
	}
	else
	{
		data=s->arr[s->top];
		s->top-=1;
	}
	return data;
}

void print_graph(struct Graph *G)
{
	struct node *t;
	for(int i=0; i<G->V; i++)
	{
		t=G->adj[i];
		printf("[%d] ", i);
		while(t!=NULL)
		{
			printf("%d ", t->v_no);
			t=t->next;
		}
		printf("\n");
	}
}
void view_stack(struct stack *s)
{
	if(s->top==-1)
	{
		printf("stack is empty\n");
	}
	else
	{
		printf("Top element: %d\n", s->arr[s->top]);
	}
}

void DFS(struct Graph * G)
{
	int v;
	struct stack *s;
	struct node *t;
	s=create_stack(G->V);

	for(int i=0; i<G->V; i++)
	{
		G->status[i]=Ready;
	}

	push(s, 1);
	G->status[0]=Waiting;

	while(s->top!=-1)
	{
		v=pop(s);
		G->status[v-1]=Processed;
		printf("V%d ",v);

		t=G->adj[v-1];
		while(t!=NULL)
		{
			if(G->status[t->v_no-1]== Ready)
			{
				push(s,t->v_no);
				G->status[t->v_no-1]=Waiting;
			}
			t=t->next;
		}
	}
}

int main()
{
	struct Graph *g;

	g=Create_graph(5,6);
	DFS(g);
	return 0;
}