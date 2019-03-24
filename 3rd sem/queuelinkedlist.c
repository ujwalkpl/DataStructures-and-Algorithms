#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *link;
};
typedef struct node NODE;
NODE *start,*newnode,*currptr;

NODE *getnode(int value){
  newnode=(NODE *)malloc(sizeof(NODE));
  if(newnode==NULL){
    printf("Memory not available");
  }else{
    newnode->data=value;
    newnode->link=NULL;
  }
}



void insert_end(){
  int value;
  printf("Enter the value to be inserted\n");
  scanf("%d",&value);
  newnode=getnode(value);
  if(start==NULL){
    start=newnode;
    newnode->link=NULL;
  }
  else{
    currptr=start;
    while(currptr->link!=NULL){
      currptr=currptr->link;
    }
    currptr->link=newnode;
     newnode->link=NULL;
  }
}


void delete_beg(){
  if(start==NULL){
    printf("Queue Underflow,no elements to delete\n");

  }
  else{
    currptr=start;
    start=start->link;
    free(currptr);
  }
}
void Display(){
  if(start==NULL){
    printf("Queue empty,no elements to display");
  }
  currptr=start;
  while(currptr!=NULL){
    printf("%d",currptr->data);
    currptr=currptr->link;
  }
  printf("\n");
}
void main(){
  int choice;
    printf("Queue Operations\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
do {
  printf("Enter the choice\n");
  scanf("%d",&choice);

  switch (choice) {
    case 1:
      insert_end();
      break;
    case 2:
      delete_beg();
      break;
    case 3:
      Display();
      break;
    case 4:
      exit(0);
      break;

  }
} while(choice!=4);
}
