#include<stdio.h>
#include<stdlib.h>

// get number of vertices in graph

int n;
printf("Enter the number of vertices in the graph: ");
scanf("%d", &n);

// input the adjacency matrix
int adj[n][n];
printf("Enter the adjacency matrix: ");
for(int i = 0; i < n; i++)
{
    for(int j = 0; j < n; j++)
    {
        scanf("%d", &adj[i][j]);
    }
}

//check if graph is directed or undirected
int directed = 0;
for(int i = 0; i < n; i++)
{
    for(int j = 0; j < n; j++)
    {
        if(adj[i][j] != adj[j][i])
        {
            directed = 1;
            break;
        }
    }
}

if(directed == 1)
{
    printf("The graph is directed.\n");
}
else
{
    printf("The graph is undirected.\n");
}