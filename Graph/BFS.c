#include <stdio.h>
#include <stdlib.h>
#define Ready 1
#define Waiting 2
#define Processed 3

struct Queue
{
	int capacity;
	int front, rear;
	int *ptr;
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

struct Queue *create_queue(int cap)
{
	struct Queue *Q;
	Q=malloc(sizeof(struct Queue));
	Q->capacity=cap;
	Q->front=-1;
	Q->rear=-1;

	Q->ptr=malloc(sizeof(struct Queue) *cap);
	return Q;
}

struct Graph *create_graph(int v_count, int e)
{
	struct Graph *G;
	G=(struct Graph *)malloc(sizeof(struct Graph));

	G->V=v_count;
	G->adj=(struct node **)malloc(sizeof(struct node *) *(G->V));
	G->status=malloc(sizeof(int)* v_count);

	int u,v;
	for(int i=0; i<v_count; i++)
	{
		G->adj[i]=NULL;
		G->status[i]=-1;
	}

	for(int i=0; i<e; i++)
	{
		printf("Enter vertices no which is connected edeg %d: ",i);
		scanf("%d%d",&u,&v);

		struct node *n;
		n=malloc(sizeof(struct node)); 
		n->v_no=v;
		n->next=G->adj[u-1];
		G->adj[u-1]=n;

		n=malloc(sizeof(struct node));
		n->v_no=u;
		n->next=G->adj[v-1];
		G->adj[v-1]=n;
	}
	return G;
}

void insert_queue(struct Queue *Q, int data)
{
	if(Q->front==0 && Q->rear==Q->capacity-1)
	{
		printf("Overflow\n");
	}
	else if(Q->rear==-1)
	{
		Q->rear=0;
		Q->front=0;
		Q->ptr[Q->rear]=data;
	}
	else 
	{
		Q->rear+=1;
		Q->ptr[Q->rear]=data;
	}
}

int delete_queue(struct Queue *Q)
{
	int data;
	if(Q->front==-1)
	{
		printf("Underflow\n");
	}
	else if(Q->front> Q->rear)
	{
		Q->front=-1;
		Q->rear=-1;
	}
	else
	{
		data=Q->ptr[Q->front];
		Q->front+=1;
	}
	return data;
}
void print_list(struct Graph *G)
{
	struct node *t;
	for(int i=0; i<G->V; i++)
	{
		t=G->adj[i];
		printf("[%d] ", i);
		while(t!=NULL)
		{
			printf("%d ",t->v_no);
			t=t->next;
		}
		printf("\n");
	}
}

void print_queue(struct Queue *Q)
{
	if(Q->front==-1)
	{
		printf("Queue is empty\n");
	}
	else
	{
		printf("\nQueue contains: ");
		for(int i=Q->front; i<=Q->rear; i++)
		{
			printf("%d ", Q->ptr[i]);
		}
	}
}

void BFS(struct Graph *G)
{
	int v;
	struct Queue *q;
	q=create_queue(G->V);
	struct node *t;

	for(int i=0; i<G->V; i++)
	{
		G->status[i]=Ready;
	}

	insert_queue(q,1);
	G->status[0]=Waiting;

	while(q->front!=-1)
	{
		//print_queue(q);
		v=delete_queue(q);
		G->status[v-1]=Processed;
		printf("V%d ",v);

		t=G->adj[v-1];
		while(t!=NULL)
		{
			if(G->status[t->v_no-1]==Ready)
			{
				insert_queue(q,t->v_no);
				G->status[t->v_no-1]=Waiting;
			}
			t=t->next;
		}
	}
}

int main()
{
	struct Graph *g;
	g=create_graph(5,6);

	BFS(g);
	return 0;
}

/*void BFS(struct Graph *G, int start_v)
{
	int data;
	struct Queue *q;
	q=create_queue(G->V);

	insert_queue(q,start_v);
	G->status[start_v]=2;

	while(q->front!=-1)
	{
		print_queue(q);
		data=delete_queue(q);
		printf("Visited: %d\n",data);

		struct node *t;
		t=G->adj[data];

		while(t!=NULL)
		{
			int adjvertex=t->v_no;

			if(G->status[adjvertex]==1)
			{
				insert_queue(q,adjvertex);
				G->status[adjvertex]=2;
			}
			t=t->next;
		}
	}
}*/