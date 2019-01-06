#include<stdio.h>
#include<math.h>
#include<ctype.h>

#define SIZE 50

int i=0,j=0;
  int top=-1;
  char infix[SIZE],postfix[SIZE],stack[SIZE];

void push(char item) {
  if(top==SIZE-1){
        printf("stack overflow,cannot insert\n");

  }else{
    stack[++top]=item;
  }
}

char pop(){
  if(top==-1){
    printf("stack underflow,cannot delete\n");
  }else{
return(stack[top--]);
  }
}

  int isoperator(char item){
  switch (item) {
    case '/':
    case '*':
    case '+':
    case '-':
    case '^':
    case '(':
       return 1;
       break;
    default:
      return 0;
      break;
  }
}

int precedence(char item)
{
  switch (item) {

    case '^':
      return 4;
      break;
    case '/':
    case '*':
      return 3;
      break;
    case '+':
    case '-':
      return 2;
      break;

    case '(':
      return 1;
      break;


  }
}
void main(){
  char item;

  printf("Enter the infix expression\n");
  gets(infix);
  while(infix[i]!='\0'){
    item=infix[i];
    if(isalnum(item)){
      postfix[j++]=item;

    }else if(item=='('){
      push(item);

    }else  if(isoperator(item)){
      if(item=='^')
      push(item);
      else{
        while(top!=-1&&precedence(item)<=precedence(stack[top])){
          postfix[j++]=pop();
        }
        push(item);
      }
    }else if(item==')'){
      while(stack[top]!='('){
        postfix[j++]=pop();
      }
      pop();
    }else{
      printf("wrong expression");

    }
    i++;
  }
  while(top!=-1){
    postfix[j++]=pop();
  }
  postfix[j]='\0';
  printf("The postfix expression is ");
  puts(postfix);
}
