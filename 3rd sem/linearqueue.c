#include<stdio.h>
#define SIZE 50
int rear=-1,front=-1;
int Queue[SIZE];


void insert(){
  int item;
  printf("Enter the element to insert\n");
  scanf("%d",&item);
   if(rear==-1){
     front=rear=0;
     Queue[rear]=item;


   }else if(rear==SIZE-1){
     printf("Queue full cannot insert\n");
     return;
   }else{
     Queue[++rear]=item;
   }
}

void delete(){
  int item;
  if(rear==-1)
  printf("Queue is empty\n");
  else if(front==rear){
    printf("The deleted element is %d\n",Queue[front]);
    front=rear=-1;
  }else
      printf("The deleted element is %d\n",Queue[front++]);
}

void display(){
  int i;
  if(rear==-1){
    printf("No elements to display");

  }
  else
  {
    for(i=front;i<=rear;i++)
      printf("%d ",Queue[i]);
      printf("\n");
  }
}
void main(){
  printf("Queue operations \n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
  int choice;
  do {
    printf("Enter the choice\n");
    scanf("%d",&choice);
        switch (choice) {
      case 1:
       insert();
        break;
      case 2:
       delete();
        break;
      case 3:
        display();
        break;
      case 4:
        printf("Exit");
        break;
    }
  } while(choice!=4);
}
