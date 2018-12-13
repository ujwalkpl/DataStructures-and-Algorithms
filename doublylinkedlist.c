#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *forw;
  struct node *back;
};

  typedef struct node NODE;
  NODE *start=NULL,*currptr,*newnode,*prevptr,*nextptr;
  int i;
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

    void insert_beg(){
      int value;

      printf("Enter the element to insert\n");
      scanf("%d",&value);
      newnode=getnode(value);
      if(start==NULL){
        start=newnode;
        newnode->forw = NULL;
        newnode->back=NULL;
      }
      else{
        newnode->forw=start;
  newnode->back=NULL;
  start->back=newnode;
        start=newnode;

      }
    }
  void delete_beg(){
      if(start==NULL){
        printf("List Empty,No elements to delete");
        return;
      }
      else{

        currptr=start;
        start=start->forw;
        start->back=NULL;

              printf("element deleted is %d",currptr->data);
        free(currptr);
      }
    }
    void insert_end(){
      int value;
      printf("Enter the value to be inserted");
      scanf("%d",&value);
      newnode=getnode(value);
      if(start==NULL){
        start=newnode;
        newnode->forw=NULL;
        newnode->back=NULL;
      }
      else{
        currptr=start;
        while(currptr->forw!=NULL)
        currptr=currptr->forw;
        currptr->forw=newnode;
        newnode->forw=NULL;
        newnode->back=currptr;
      }
    }

    void insert_pos(){
      int value,count=0,pos;

      printf("Enter the value to be inserted");
      scanf("%d",&value);
      newnode=getnode(value);
      printf("Enter the position");
      scanf("%d",&pos);
      currptr=start;
      while(currptr!=NULL){
        count++;
        currptr=currptr->forw;
        }
      if(pos==1){
        insert_beg();
      }
      else if(pos>1 && pos<=count){
        currptr=start;
      for(i=1;i<pos-1;i++)  {
        currptr=currptr->forw;
      }
      newnode->forw=currptr->forw;
      currptr->forw->back=newnode;

      currptr->forw=newnode;
      newnode->back=currptr;

      }
      else{
        printf("position out of range");
      }
    }
    void delete_end(){
      if(start==NULL){
        printf("list empty,no elements to delete");
      }
      else{
        currptr=start;
        while(currptr->forw->forw!=NULL){
          currptr=currptr->forw;

        }
        nextptr=currptr->forw;
        currptr->forw=NULL;
        printf("element deleted is %d",nextptr->data);
        free(nextptr);

      }
    }

    void delete_pos(){
      int pos,count=0;
      if(start==NULL){
        printf("list empty,no elements to delete");
      }
      else{
        printf("Enter the position");
        scanf("%d",&pos);
        currptr=start;
        while (currptr!=NULL) {
          count++;
          currptr=currptr->forw;
        }
        if(pos==1){
          delete_beg();
          return;
        }else if(pos>1 && pos<=count){
          currptr=start;
          for(i=1;i<pos-1;i++){
            currptr=currptr->forw;
          }
          nextptr=currptr->forw;
          currptr->forw=currptr->forw->forw;
          currptr->forw->back=currptr;
          printf("the deleted element is %d",nextptr->data);
        }else{
          printf("position out of bound");
        }

      }
    }
    void display(){
      currptr=start;
      while (currptr!=NULL) {
        printf("%d",currptr->data);
        currptr=currptr->forw;
      }
    }
    void display_reverse(){
      currptr=start;
      while(currptr->forw!=NULL){
        currptr=currptr->forw;
      }
      while(currptr!=NULL){
        printf("%d",currptr->data);
        currptr=currptr->back;
      }
    }


void main() {
  int choice,i;
  printf("1.Insert Beginning\n2.Insert End\n3.Insert position\n4.Delete Beginning\n5.Delete Ending\n6.Delete position\n7.display\n8.display reverse\n");
  do {
      printf("Enter the choice\n");
      scanf("%d",&choice);
    switch (choice) {
      case 1:
        insert_beg();
        break;
      case 2:
        insert_end();
        break;
      case 3:
        insert_pos();
        break;
      case 4:
        delete_beg();
        break;
      case 5:
        delete_end();
        break;
      case 6:
        delete_pos();
        break;
      case 7:
        display();
        break;
      case 8:
        display_reverse();
        break;


    }
    fflush(stdin);
  } while(choice!=9);


}
