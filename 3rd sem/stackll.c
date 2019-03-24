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

  }
  else{
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
  }
  else{
    currptr=start;
    while(currptr->link!=NULL){
      currptr=currptr->link;
    }
    currptr->link=newnode;
  }
}


void delete_end(){
  if(start==NULL){
    printf("list empty,no elements to \n");
  }
  else if(start->link==NULL){
    free(start->link);
    start=NULL;
  }else{
    currptr=start;
    while(currptr->link->link!=NULL){
      currptr=currptr->link;

    }
    free(currptr->link);
    currptr->link=NULL;


  }
}


void display(){
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
  printf("stack operations\n1.push\n2.pop\n3.display\n4.Exit\n");
  do {
    printf("Enter the choice\n");
    scanf("%d",&choice);
    switch (choice) {
      case 1:
        insert_end();
        break;
      case 2:
        delete_end();
        break;
      case 3:
        display();
        break;
      case 4:
        exit(0);
        break;
    }
  } while(choice!=4);
}
