#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *link;
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
      newnode->link=NULL;
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
        newnode->link = NULL;
      }
      else{
        newnode->link=start;
        start=newnode;
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
        while(currptr->link!=NULL)
        currptr=currptr->link;
        currptr->link=newnode;
        newnode->link=NULL;
      }
    }

    void insert_pos(){
      int value,count=0,pos;

      printf("Enter the value to be inserted\n");
      scanf("%d",&value);
      newnode=getnode(value);
      printf("Enter the position\n");
      scanf("%d",&pos);
      currptr=start;
      while(currptr!=NULL){
        count++;
        currptr=currptr->link;
        }
      if(pos==1){
        insert_beg();
      }
      else if(pos>1 && pos<=count){
        currptr=start;
      for(i=1;i<pos-1;i++)  {
        currptr=currptr->link;
      }
      newnode->link=currptr->link;
      currptr->link=newnode;

      }
      else{
        printf("position out of range");
      }
    }
    void display(){
      currptr=start;
      while (currptr!=NULL) {
        printf("%d ",currptr->data);
        currptr=currptr->link;
      }
    }

    void reverse(){
        currptr = start;
        prevptr = NULL;
      nextptr = NULL;

    while (currptr != NULL) {
            nextptr= currptr->link;
            currptr->link = prevptr;
            prevptr = currptr;
            currptr = nextptr;
        }
        start = prevptr;

    }
    void main(){
      int choice;
      printf("1.Insert_beg\n2.Insert_end\n3.Insert_pos\n4.reverse\n5.display\n6.Exit\n");
      do{
          printf("\nEnter the choice\n");
          scanf("%d",&choice);
          switch(choice){
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
              reverse();
              break;
            case 5:
              display();
              break;
            case 6:
              printf("Exit");
              exit(0);
          }
      }while(choice!=6);
    }
