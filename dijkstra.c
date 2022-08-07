#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int v;

int minIdx(int dist[],bool mstSet[])
{
    int min_idx,min;
    min_idx=min=INT_MAX;
    for(int i=0;i<v;i++)
    {
        if(dist[i]<=min && !mstSet[i])
        {
            min=dist[i];
            min_idx=i;
        }
    }
    return min_idx;
}

void printAns(int dist[])
{
    printf("city\t shortest distance from city\t\n");
    for(int i=0;i<v;i++)
    {
        printf("%d\t %d\t",i,dist[i]);
        printf("\n");
    }
}

void Dijkstra(int graph[v][v])
{
    int startnode,idx,count,dist[v];
    bool mstSet[v];
    count=0;
    for(int i=0;i<v;i++)
    {
        mstSet[i]=false;
        dist[i]=INT_MAX;
    }
    printf("enter the start node:\n");
    scanf("%d",&startnode);
    dist[startnode]=0;
    for(count=0;count<v;count++)
    {
    idx=minIdx(dist,mstSet);
    mstSet[idx]=true;
    for(int k=0;k<v;k++)
    {
        if(graph[idx][k] && !mstSet[k] && dist[idx]!=INT_MAX && dist[idx]+graph[idx][k]<dist[k])
        {
            dist[k]=graph[idx][k]+dist[idx];
        }
    }
    }
    printAns(dist);
}

void main()
{
    printf("enter the no of vertices:\n");
    scanf("%d",&v);
    int graph[v][v];
    printf("enter the cost matrix:\n");
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    Dijkstra(graph);
}
