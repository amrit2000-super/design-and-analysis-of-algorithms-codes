#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int v;

typedef struct tree
{
    int value;
    int source;
    int destination;
}Tree;

int minIdx(int cost[],bool mstSet[])
{
    int min_idx,min;
    min_idx=min=INT_MAX;
    for(int i=0;i<v;i++)
    {
        if(cost[i]<min && !mstSet[i])
        {
            min=cost[i];
            min_idx=i;
        }
    }
    return min_idx;
}

int Prim(int graph[v][v],Tree e[])
{
    int min_cost,cost[v],parent[v],startnode,idx,count;
    bool mstSet[v];
    min_cost=count=0;
    for(int i=0;i<v;i++)
    {
        cost[i]=INT_MAX;
        mstSet[i]=false;
    }
    printf("enter the start node:\n");
    scanf("%d",&startnode);
    parent[startnode]=-1;
    cost[startnode]=0;
    for(count=0;count<v;count++)
    {
    idx=minIdx(cost,mstSet);
    mstSet[idx]=true;
    if(count>=1)
    {
        e[count-1].value=graph[idx][parent[idx]];
        e[count-1].source=parent[idx];
        e[count-1].destination=idx;
        min_cost+=graph[parent[idx]][idx];
    }
    for(int k=0;k<v;k++)
    {
        if(graph[idx][k] && !mstSet[k] && graph[idx][k]<cost[k])
        {
            parent[k]=idx;
            cost[k]=graph[idx][k];
        }
    }
    }
    return min_cost;
}

void main()
{
    int min_cost;
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
    Tree e[v-1];
    min_cost=Prim(graph,e);
    printf("minimum sapnning tree is\n");
    printf("edge\t cost\t\n");
    for(int i=0;i<v;i++)
    {
        printf("%d-%d\t %d\t",e[i].source,e[i].destination,e[i].value);
        printf("\n");
    }
    printf("minimun cost is %d\n",min_cost);
}
