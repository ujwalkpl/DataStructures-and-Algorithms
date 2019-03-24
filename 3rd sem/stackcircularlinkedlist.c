//Stack Using circular linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *link;

};
typedef struct node NODE;

NODE *last=NULL,*currptr,*newnode;

NODE *getnode(int value){
  newnode=(NODE *)malloc(sizeof(NODE));
 if(newnode==NULL){
    printf("memory not available");
return newnode;
  }
  else{

    newnode->data=value;
    newnode->link=NULL;
    return newnode;
  }


}

void insert_end(){
  int value;
  printf("Enter the value to be inserted\n");
  scanf("%d",&value);
  newnode=getnode(value);
  if(last==NULL){
    last=newnode;
    last->link=last;
  }
  else{
    newnode->link=last->link;
    last->link=newnode;
    last=last->link;
  }
}
void delete_end(){
  currptr=last;
  if(last==NULL){
    printf("no elements to delete\n");
      }
  else if(last->link==last){
    free(last);
    last=NULL;
  }
  else{
  while(currptr->link!=last)
  currptr=currptr->link;
  newnode=currptr->link;
  currptr->link=currptr->link->link;
  last=currptr;
  free(newnode);
}
}
void display(){
if(last==NULL){
  printf("no elements to display\n");

}else{
  currptr=last->link;
  while(currptr!=last){
    printf("%d ",currptr->data);
    currptr=currptr->link;
  }
  printf("%d\n",currptr->data);
}
}
void main(){
  int choice;
  printf("1.push\n2.pull\n3.display\n4.exit\n");
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
        printf("Exit\n");
        exit(0);
        break;

    }
  } while(choice!=4);

}
