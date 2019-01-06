#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

#define SIZE 20
struct node{
  char data;
  struct node *leftchild;
  struct node *rightchild;

};
typedef struct node NODE;
NODE *root=NULL,*newnode,*tree=NULL;
int top = -1;
NODE *stack[SIZE];
char postfix[SIZE];

void push(NODE *root){
  if(top==SIZE-1){
    printf("Stack overflow,cannot insert");
  }else{
    stack[++top]=root;
  }
}

int isoperator(int item){
  switch (item) {
    case '*':
    case '/':
    case '-':
    case '^':
    case '+':
      return 1;
      break;
    default:
      return 0;
    }
  }

NODE *pop(){
  if(top==-1){
    printf("Stack underflow,cannot delete");
  }else{
    return stack[top--];
  }
}

NODE *getnode(char item){
  newnode=(NODE *)malloc(sizeof(NODE));
  if(newnode==NULL)
    printf("Memory not available");
  else{
    newnode->data=item;
    newnode->rightchild=NULL;
    newnode->leftchild=NULL;
    return newnode;
  }
}

void createnode(char *postfix){
  int i;
  for(i=0; postfix[i] != '\0';i++){
    if(isoperator(postfix[i])){
      
      root=getnode(postfix[i]);
      root->rightchild=pop();

      root->leftchild=pop();


      push(root);
      }
      else{

        root=getnode(postfix[i]);

        push(root);
      }
    }
    tree=pop();
  }

int evaluate(NODE *root){


    if(isoperator(root->data)){
      switch (root->data) {
        case '*':
          return evaluate(root->leftchild) * evaluate(root->rightchild);
        case '-':
          return evaluate(root->leftchild) - evaluate(root->rightchild);
        case '/':
          return evaluate(root->leftchild) / evaluate(root->rightchild);
        case '+':
          return (evaluate(root->leftchild) + evaluate(root->rightchild));
        case '^':
          return pow(evaluate(root->leftchild),evaluate(root->rightchild));
    }
  }
    else{
      return (root->data -'0');
    }

  }


void main(){
    printf("Enter the postfix expression");
    scanf("%s",postfix);
    createnode(postfix);

    printf("\n");
    printf("The evaluation of the expression is %d",evaluate(tree));
  }
