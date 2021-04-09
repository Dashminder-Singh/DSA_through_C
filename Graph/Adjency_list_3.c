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

struct Graph *create_graph(int v_count, int e)
{
	struct Graph *G;
	G=(struct Graph *)malloc(sizeof(struct Graph));
	G->V=v_count;
	G->adj=(struct node **)malloc(sizeof(struct node *) *(G->V));
	
	int u,v;
	for(int i=0; i<v_count; i++)
	{
		G->adj[i]=NULL;
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

void print_list(struct Graph *G)
{
	struct node *t;
	for(int i=0; i<G->V; i++)
	{
		t=G->adj[i];
		printf("[%d] ",i);
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
	g=create_graph(5,6);
	print_list(g);
	return 0;
}