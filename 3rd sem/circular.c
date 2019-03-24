#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *link;
};

  typedef struct node NODE;
  NODE *last=NULL,*currptr,*newnode,*prevptr,*nextptr;
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
      if(last==NULL){
        last=newnode;
        newnode->link = last;
      }
      else{
        newnode->link=last->link;
        last->link=newnode;
      }
    }

  void delete_beg(){
      if(last==NULL){
        printf("List Empty,No elements to delete\n");
        return;
      }
      else if(last->link==last){
        printf("element deleted is %d\n",last->data);
        free(last);
        last=NULL;
      }
      else{
        currptr=last->link;
        last->link=last->link->link;
        printf("element deleted is %d\n",currptr->data);
        free(currptr);
      }
    }

    void insert_end(){
      int value;
      printf("Enter the value to be inserted\n");
      scanf("%d",&value);
      newnode=getnode(value);
      if(last==NULL){
        last=newnode;
        newnode->link=last;
      }
      else{
        newnode->link=last->link;
        last->link=newnode;
        last=last->link;

      }
    }

    void insert_pos(){
      int value,count=0,pos;


      printf("Enter the position");
      scanf("%d",&pos);
      currptr=last->link;
      while(currptr!=last){
        count++;
        currptr=currptr->link;
        }
        count++;
      if(pos==1){
        insert_beg();
      }
      else if(pos>1 && pos<=count){
        printf("Enter the value to be inserted");
        scanf("%d",&value);
        newnode=getnode(value);
        currptr=last;
      for(i=1;i<pos-1;i++)  {
        currptr=currptr->link;
      }
      newnode->link=currptr->link;
      currptr->link=newnode;

      }
      else if(pos==count+1)
        insert_end();
      else
        printf("position out of range");
      }
    void delete_end(){
      if(last==NULL){
        printf("list empty,no elements to delete");
      }
      else if(last->link==last){
        printf("element deleted is %d\n",last->data);
        free(last);
        last=NULL;
      }
      else{
        currptr=last;
        while(currptr->link!=last){
          currptr=currptr->link;

        }

        nextptr=currptr->link;
        currptr->link=currptr->link->link;
        last=currptr;
        printf("element deleted is %d",nextptr->data);
        free(nextptr);

      }
    }

    void delete_pos(){
      int pos,count=0;
      if(last==NULL){
        printf("list empty,no elements to delete");
      }
      else{
        printf("Enter the position");
        scanf("%d",&pos);
        currptr=last->link;
        while (currptr!=last) {
          count++;
          currptr=currptr->link;
        }
        if(pos==1){
          delete_beg();
          return;
        }else if(pos>1 && pos<=count){
          currptr=last;
          for(i=1;i<pos-1;i++){
            currptr=currptr->link;
          }
          nextptr=currptr->link;
          currptr->link=currptr->link->link;
          printf("the deleted element is %d",nextptr->data);
        }else{
          printf("position out of bound");
        }

      }
    }
    void display(){
      currptr=last->link;
      while (currptr!=last) {
        printf("%d ",currptr->data);
        currptr=currptr->link;
      }
      printf("%d\n",currptr->data);
    }


void main() {
  int choice,i;
  printf("1.Insert Beginning\n2.Insert End\n3.Insert position\n4.Delete Beginning\n5.Delete Ending\n6.Delete position\n7.display\n");
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


    }
    fflush(stdin);
  } while(choice!=8);


}
