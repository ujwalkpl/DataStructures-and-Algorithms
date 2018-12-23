#include<stdio.h>
struct node{
  int data;
  struct node *link;
};
typedef struct node NODE;
NODE *start,*newnode;

NODE *getnode(int value){
  newnode=(NODE *)malloc(sizeof(NODE));
  if(newnode==NULL){
    printf("Memory not available");
  }else{
    newnode->data=value;
    newnode->link=NULL;
  }
}

void insert_beg(){
  int value;
  printf("Enter the value to be inserted");
  scanf("%d",&value);
}
void main(){

}
