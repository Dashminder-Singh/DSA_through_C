#include <stdio.h>
#include <stdlib.h>

struct node
{
	int v_no;
	struct node *next;
};

struct Graph
{
	int V;
	struct node **adj;
};

struct node *new_node(int no)
{
	struct node *n;
	n=(struct node *)malloc(sizeof(struct node));
	n->v_no=no;
	n->next=NULL;
	return n;
}

struct Graph *create(int v)
{
	struct Graph *G;
	G=(struct Graph *)malloc(sizeof(struct Graph));
	G->V=v;
	G->adj=(struct node **)malloc(sizeof(struct node*) * (G->V));

	for(int i=0; i<v; i++)
	{
		G->adj[i]=NULL;
	}
	return G;
}

void add_edge(struct Graph *G, int s, int d)
{
	struct node *n;
	n=new_node(d);
	n->next=G->adj[s-1];
	G->adj[s-1]=n;

	n=new_node(s);
	n->next=G->adj[d-1];
	G->adj[d-1]=n;
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

int main()
{
	struct Graph *g;
	g=create(5);

	add_edge(g,1, 2);
	add_edge(g,1, 3);
	add_edge(g,2, 3);
	add_edge(g,2, 4);
	add_edge(g,3, 5);
	add_edge(g,4, 5);

	print_list(g);
	return 0;
}