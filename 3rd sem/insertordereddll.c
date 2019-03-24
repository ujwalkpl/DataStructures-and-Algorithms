#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *forw;
  struct node *back;
};
typedef struct node NODE;
NODE *start=NULL,*newnode,*currptr;

NODE *getnode(int value){

  newnode=(NODE *)malloc(sizeof(NODE));
  if(newnode==NULL){
    printf("Memory not available\n");
  }
  else{
    newnode->forw=NULL;
    newnode->back=NULL;
    newnode->data=value;
    return newnode;
  }
  }
  void display(){
    currptr=start;
    while (currptr!=NULL) {
      printf("%d",currptr->data);
      currptr=currptr->forw;
    }
  }

  void sortedInsert(NODE *newnode){
    if(start==NULL||(start->data)>=(newnode->data)){
      newnode->forw=start;
      newnode->back=NULL;
      start=newnode;

    }
    else{
      currptr=start;
      while(currptr->forw!=NULL &&(currptr->forw->data)<newnode->data){
        currptr=currptr->forw;

      }
      newnode->forw=currptr->forw;
      currptr->forw=newnode;
      newnode->back=currptr;
      if(newnode->forw!=NULL)
        newnode->forw->back=newnode;

    }
  }
  void Insert(){
    int value;
    printf("Enter the element to insert");
    scanf("%d",&value);
    newnode=getnode(value);
    sortedInsert(newnode);
  }

void main(){

  printf("\n1.Insert\n2.Display");
    int choice=0;
  do {
      printf("Enter the choice\n");
scanf("%d",&choice);
    switch(choice) {
      case 1:
        Insert();
        break;
      case 2:
       display();
        break;
    }
  } while(choice!=6);
}
