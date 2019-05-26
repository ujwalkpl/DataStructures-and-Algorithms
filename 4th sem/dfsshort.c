#include<stdio.h>

int dfs(int [20][20],int,int[20],int);
void main()
{
    int n,a[20][20],i,j,visited[20],source,visitedorder[20];
    printf("Enter the no of vertices\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(i=1;i<=n;i++)
        visited[i]=0;
    printf("Enter source node\n");
    scanf("%d",&source);
    for(i=1;i<=n;i++)
        if(visited[i]==0)
            dfs(a,n,visited,i);
    
}
int dfs(int a[20][20],int n,int visited[20],int source)
{   printf("%c \t",source+64);
   
    int v;
    visited[source]=1;
    for(v=1;v<=n;v++)
    {
        if(a[source][v]==1&&visited[v]==0)
        {
            dfs(a,n,visited,v);
        }
    }
}