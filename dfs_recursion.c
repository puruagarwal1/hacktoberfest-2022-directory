#include<stdio.h>
#include<stdlib.h>



struct Graph
{
	int vertex;
	int edge;
	int ** adjMatrix;
};

struct Graph * createGraph(int v, int e)
{
	int i, j;
	struct Graph * g;
	g = (struct Graph *)malloc(sizeof(struct Graph));

	g->vertex = v;
	g->edge = e;
	g->adjMatrix = (int **)malloc(v * sizeof(int *));

	for(i = 0; i < v; i++)
	{
		g->adjMatrix[i] = (int *)malloc(v * sizeof(int));
		
		for(j = 0; j < v; j++)
			g->adjMatrix[i][j] = 0;
	}
	return g;
}

struct Graph * insertEdge(struct Graph * g, int v1, int v2)
{

	g->adjMatrix[v1][v2] = 1;
	
	//g->adjMatrix[v2][v1] = 1;
	
	return g;
}

void printGraph(struct Graph * g)
{
	int i, j;
	for(i = 0; i < g->vertex; i++)
	{
		for(j = 0; j < g->vertex; j++)
		{
			printf("%d  ", g->adjMatrix[i][j]);
		}
		printf("\n");
	}
}



void recursiveDFS(struct Graph * g,struct Stack * s, int * visited)
{
	int i, x;
	
	if(isEmpty(s)) 
		return;
	x=pop(s);
	printf("%d->",x);
	
	for(i=0;i<g->vertex;i++)
	{
		if(g->adjMatrix[x][i] == 1)
		{
		
			if(!visited[i])
			{
				visited[i]=1;
				push(s,i);
			}
		}
	}
	recursiveDFS(g,s,visited);
}

	
		
int main()
{
    int n, e, v1, v2, i;
    int * visited;
	struct Graph * g;
	
	printf("\nEnter the number of node and number of edge : ");
	scanf("%d%d",&n,&e);
    
	g = createGraph(n,e);
    
    printf("Enter the %d Edges",e);
    for(i=0; i<e; i++)
    {
    	printf("\nEnter the source node and destination node: ");
    	scanf("%d%d",&v1, &v2);
    	g = insertEdge(g,v1,v2);
    }

    printGraph(g);
    visited = (int *)malloc(n*sizeof(int));
	
	for(i = 0; i<n; i++)
		visited[i] = 0;
    struct Stack * st= createStack(10);
    printf("enter the value from which you want to start");
    scanf("%d",&i);
    	if(visited[i]==0)
    	{
    		visited[i]=1;
    		push(st,i);
    		recursiveDFS(g,st,visited);
    	}
    


    return 0;
}

