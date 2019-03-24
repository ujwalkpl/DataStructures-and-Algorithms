#include<stdio.h>
#define SIZE 20

int top=-1;

int stack[SIZE];
void push(int item){
  if(top==SIZE-1){
    printf("Stack overflow cannot insert");
  }else{
    stack[++top]=item;
  }
}

int pop(){
  if(top==-1){
    printf("Stack underflow");
    return;
  }
  else
    return stack[top--];
}
void main(){
  int item;
  int choice;
  printf("Stack operations\n1.Push\n2.Pop\n3.Display");
  do {
    printf("Enter the choice");
    scanf("%d",&choice);
    switch (choice) {
      case 1:
        printf("Enter the element to be pushed");
        scanf("%d",&item);
        push(item);
        break;
      case 2:
        printf("%d",pop());
        break;

    }
  } while(choice!=4);
  scanf("%d",&choice);

}
