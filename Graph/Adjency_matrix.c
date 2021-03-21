#include <stdio.h>
#include <stdlib.h>

struct Graph
{
	int V;
	int E;
	int **adj;
};

struct Graph *Create(int v, int e)
{
	struct Graph *G;
	G=(struct Graph *)malloc(sizeof(struct Graph));
	G->V=v;
	G->E=e;
	G->adj=(int **)malloc(sizeof(int *) * (G->V));

	int i,j;
	for(i=0; i<v; i++)
	{
		G->adj[i]=(int *)malloc(sizeof(int) * (G->V));
		for(j=0; j<v; j++)
		{
			G->adj[i][j]=0;
		}
	}

	for(int k=1; k<=e; k++)
	{
		printf("Enter vertices number which is connected edge %d: ",k);
		scanf("%d%d",&i,&j);
		G->adj[i-1][j-1]=1;
		G->adj[j-1][i-1]=1;
	}
	return G;
}

void print_matrix(struct Graph *G)
{
	printf("\n");
	for(int i=0; i<G->V; i++)
	{
		for(int j=0; j<G->V; j++)
		{
			printf("%d ", G->adj[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	struct Graph *g;

	g=Create(5,6);
	print_matrix(g);
	return 0;
}