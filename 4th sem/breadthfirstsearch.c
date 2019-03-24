#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define MAX 100
int num,count;
int adj[MAX][MAX];
int visited[MAX],que[MAX];
int front=-1,rear=-1;
void insertq(int element){
    if(front==-1)
        front=0;
    rear=rear+1;
    que[rear]=element;
  //  printf("   %d inserted    ",element);

}

int deleteq(){
    int delete_item;
    if(front == -1 || front > rear)
	{
		printf("Queue Underflow\n");
		exit(1);
	}
    delete_item = que[front];
	front = front+1;
    //printf("    %d deleted    ",delete_item);
	return delete_item;


}
int queempty(){
    if(front==-1||front>rear)
        return 1;
        return 0;
}
void creategraph(){
    int maxedge;
    int i,source,destination;
printf("Enter the number of vertices ");
scanf("%d",&num);
maxedge=num*(num-1);
for(i=0;i<maxedge;i++){
    printf("Enter edge number %d",i+1);
    scanf("%d %d",&source,&destination);
    if(source==-1||destination==-1){
        return;
    }
    adj[source][destination]=1;
}
}
void bfs(int i){
insertq(i);
visited[i]=1;
count++;
int j;
while(!queempty()){

   i=deleteq();
   printf("%d ",i);
 for(j=0;j<num;j++){
     if(adj[i][j]!=0&&visited[j]==0){
         count++; 
         visited[j]=1;
        
         
         insertq(j);
     }
 }
 
}
printf("\n\n");
}


void main(){
    int i;
   creategraph(); 
   for(i=0;i<num;i++){
       visited[i]=0;
   }
    count=0;
    printf("Enter the starting vertex");
    scanf("%d",&i);
        bfs(i);
    }
    
    

