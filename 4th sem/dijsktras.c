#include<stdio.h>
#define MAX 999
void dijstras(int cost[MAX][MAX],int s,int n){
  int i,j;
  int distance[MAX];
  int mindistance;
  int count;
  int visited[MAX],pred[MAX];
  int nextnode;
    for(i=0;i<n;i++){
      distance[i]=cost[s][i];
      pred[i]=s;
      visited[i]=0;
    }
    distance[s]=0;
    visited[s]=1;


    count=1;
    while(count<n-1){
      mindistance=MAX;
    for(i=0;i<n;i++){
      
      if(distance[i]<mindistance&&!visited[i]){
        mindistance=distance[i];
        nextnode=i;
      }


    }
    visited[nextnode]=1;

    for(i=0;i<n;i++){
      if(mindistance+cost[nextnode][i]<distance[i]&&!visited[i]){
      distance[i]=mindistance+cost[nextnode][i];
      pred[i]=nextnode;
      }
    }
    count++;
    }

    for(i=0;i<n;i++){
      if(i!=s){
      printf(" \nShortese distance from %d to %d is %d ",s,i,distance[i]);
       j=i;
       printf(" The path taken is %d",i);
      do{
        j=pred[j]; 
        
        printf(" <- %d",j);
      }while(j!=s);
    }
    }
        
  }


 
void main(){
  int n,s;
  int i,j;
  int cost[MAX][MAX];
  
  printf("Enter the number of nodes\n");

  scanf("%d",&n);
  // printf("Enter the cost matrix\n");
  // for(i=0;i<n;i++){
  //   for(j=0;j<n;j++){

    
  //   scanf("%d",&cost[i][j]);

    int maxedge;
    int source,destination;

maxedge=n*(n-1);
for(i=0;i<maxedge;i++){
    printf("Enter edge number-%d    ",i+1);
    scanf("%d %d",&source,&destination);
    if(source==-1||destination==-1){
      break;

    }
    else{

    printf("Enter weight ");
    scanf("%d",&cost[source][destination]);
    cost[destination][source]=cost[source][destination];
   
    }
}
for(i=0;i<n;i++){
for(j=0;j<n;j++){
  if(cost[i][j]==0)
  cost[i][j]=MAX;

}

}


 
    printf("Enter the source vertex");
    scanf("%d",&s);
    
    dijstras(cost,s,n);
}