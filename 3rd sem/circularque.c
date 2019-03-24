#include<stdio.h>
#define SIZE 4
int rear=-1,front=-1,count=0;
int queue[SIZE];
void insert(){
  int item;

  printf("Enter the element to insert");
  scanf("%d",&item);
  if(rear==-1){
    rear=front=0;
    queue[rear]=item;
    count++;
  }
  else if(count==SIZE){
    printf("Queue full\n");
  }
  else
  {
    rear=(rear+1)%SIZE;
    queue[rear]=item;
    count++;
  }
}

void delete(){
  if(count==0){
    printf("no elements to delete\n");
  }else if(front==rear){
    printf("The deleted element is %d\n",queue[front]);
    front=rear=-1;
    count--;
  }
  else{
      printf("The deleted element is %d\n",queue[front]);
    front=(front+1)%SIZE;
    count--;
  }
}
void display(){
  int i;
  if(count==0)
    printf("no elements to display\n");
  else{
    for(i=front;i!=rear;i=(i+1)%SIZE)
      printf("%d ",queue[i]);
      printf("%d\n",queue[i]);
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
