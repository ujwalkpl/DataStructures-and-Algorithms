#include<stdio.h>
void bfs(int[20][20],int,int);
int i,visited[20],queue[20];
void main()
{
 int n,a[20][20],j,source;
 printf("Enter number of vertices: \n");
 scanf("%d",&n);
 printf("Enter the adjacency matrix: \n");
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
   scanf("%d",&a[i][j]);
 for(i=1;i<=n;i++)
 visited[i]=0;
 printf("Enter the source node \n");
 scanf("%d",&source);
 bfs(a,n,source);
}
 
 void bfs(int a[20][20],int n,int source)
  {
    int f,r,u,v;
    f=0;
    r=-1;
    visited[source]=1;
    queue[++r]=source;
    while(f<=r)
    {
     u=queue[f++];
       printf("%c \t",64+u);
      for(v=1;v<=n;v++)
      {
       if(a[u][v]==1&&visited[v]==0)
        {
         queue[++r]=v;
         visited[v]=1;}
        } 
      }
  }