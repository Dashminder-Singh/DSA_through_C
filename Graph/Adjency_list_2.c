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

struct Graph * create(int v)
{
	struct Graph *G;
	G=(struct Graph *)malloc(sizeof(struct Graph));
	G->V=v;
	G->adj=(struct node **)malloc(sizeof(struct node *) * (G->V));

	struct node *n, *t;
	int x, y, i,j;

	for(i=1; i<=v; i++)
	{
		G->adj[i]=NULL;
	}

	for(i=1; i<=v; i++)
	{
		printf("Enter the number of neighbour V%d: ",i);
		scanf("%d",&x);
		for(j=1; j<=x; j++)
		{
			printf("Enter value %d: ",j);
			scanf("%d",&y);
			n=(struct node *)malloc(sizeof(struct node));
			n->v_no=y;
			n->next=NULL;

			if(G->adj[i]==NULL)
			{
				G->adj[i]=n;
			}
			else
			{
				t=G->adj[i];
				while(t->next!=NULL)
				{
					t=t->next;
				}
				t->next=n;
			}
		}
	}
	return G;
}

void print_list(struct Graph *G)
{
	struct node *t;
	for(int i=1; i<=G->V; i++)
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
	g=create(5);
	print_list(g);
	return 0;
}