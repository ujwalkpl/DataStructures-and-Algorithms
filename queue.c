#include<stdio.h>
#include<stdlib.h>
#define SIZE 50
int front =-1,rear=-1,queue[SIZE];


void insert(){
  int value;
  printf("Enter the number to be inserted");
  scanf("%d",&value);
  if(front=-1&&rear=-1){
    front++;
    queue[++rear]=value;
  }
  else{
    queue[++rear]=value;
  }
}

void delete(){
  if(front==-1){
    printf("Queue is empty,no elements to delete");
  }else if(front==rear){
    printf("The deleted element is %d ",queue[front]);

  }
}

void main(){
  printf("Queue operations\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");

  int choice;
  do{
      printf("Enter the choice\n");
      scanf("%d",&choice);
    switch (choice) {
      case 1:
      //  Insert();
        break;
      case 2:
      //  Delete();
        break;
      case 3:
      //  Display();
        break;
      case 4:
        printf("Exit");
        exit(0);
        break;
    }
  }while(choice!=4);
}
